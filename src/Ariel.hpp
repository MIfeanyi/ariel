#pragma once
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "chaiscript/chaiscript.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "statemanager.hpp"
/**
 * Ariel-> Init()
 * Ariel->Managers()
 * Ariel->AddState()
 * Ariel->Run() //loop till finished
 * 
 */

class State; class StateManager;

class Graphics;

namespace Ariel
{
    class App {
        public:
            StateManager MState;
            App();
            void Init(std::string title, int width, int height, bool fullscreen);
            virtual void Update(){
                char input[255] ="";
                ImGuiWindowFlags window_flags = 0;
                window_flags |= ImGuiWindowFlags_NoMove;
                bool* p_open = false;
                while (window.pollEvent(event)) {
                    ImGui::SFML::ProcessEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                ImGui::SFML::Update(window, deltaClock.restart());

                ImGui::Begin("Load",p_open,window_flags);
                ImGui::InputText("filename",input,255);
                if(ImGui::Button("Run")){

                }
                ImGui::End();
            };
            virtual void Render(){
                ImGui::SFML::Render(window);
            };
            int Run();
            ~App();
        protected:
            sf::RenderWindow window;
            sf::Event event;
            sf::Clock deltaClock;
            chaiscript::ChaiScript cs;
    };
}