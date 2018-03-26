#include "config.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duktape.h"
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;

void splash();
static void push_file_as_string(duk_context *ctx, const char *filename) {
    FILE *f;
    size_t len;
    char buf[16384];

    f = fopen(filename, "rb");
    if (f) {
        len = fread((void *) buf, 1, sizeof(buf), f);
        fclose(f);
        duk_push_lstring(ctx, (const char *) buf, (duk_size_t) len);
    } else {
        duk_push_undefined(ctx);
    }
}

void duk_test(string filename) {
    duk_context *ctx = NULL;
    char line[4096];
    size_t idx;
    int ch;

    //(void) argc; (void) argv;

    ctx = duk_create_heap_default();
    if (!ctx) {
        printf("Failed to create a Duktape heap.\n");
        exit(1);
    }

    push_file_as_string(ctx, filename.c_str());
    if (duk_peval(ctx) != 0) {
        printf("Error: %s\n", duk_safe_to_string(ctx, -1));
        goto finished;
    }
    duk_pop(ctx);  /* ignore result */

    memset(line, 0, sizeof(line));
    idx = 0;
    for (;;) {
        if (idx >= sizeof(line)) {
            printf("Line too long\n");
            exit(1);
        }

        ch = fgetc(stdin);
        if (ch == 0x0a) {
            line[idx++] = '\0';

            duk_push_global_object(ctx);
            duk_get_prop_string(ctx, -1 /*index*/, "processLine");
            duk_push_string(ctx, line);
            if (duk_pcall(ctx, 1 /*nargs*/) != 0) {
                printf("Error: %s\n", duk_safe_to_string(ctx, -1));
            } else {
                printf("%s\n", duk_safe_to_string(ctx, -1));
            }
            duk_pop(ctx);  /* pop result/error */

            idx = 0;
        } else if (ch == EOF) {
            break;
        } else {
            line[idx++] = (char) ch;
        }
    }

 finished:
    duk_destroy_heap(ctx);
}

int main()
{
    splash();
    duk_test("scripts/tests/test.js");
    sf::RenderWindow window(sf::VideoMode(640, 480), "Ariel Engine");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    char input[255] = "";
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Load Script");
        ImGui::InputText("filename", input, 255);

        if (ImGui::Button("Run")){
            duk_test(input);
        }
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}