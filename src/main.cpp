#include "config.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imgui.h"
#include "imgui-SFML.h"
#include "chaiscript/chaiscript.hpp"

#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;

void splash();

void chai_test(string filename)
{
    chaiscript::ChaiScript chai;
    chai.eval_file(filename.c_str());

}

int main()
{
    splash();
    
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
            chai_test(input);
        }
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}