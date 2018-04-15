#include "ariel.hpp"
namespace Ariel{
    App::App(){

    }
    void App::Init(std::string title, int width, int height, bool fullscreen){
            window.create(sf::VideoMode(width,height,fullscreen),title);
            window.setFramerateLimit(60);
            ImGui::SFML::Init(window);
    }
    App::~App(){

    }
    int App::Run(){
        while (window.isOpen()) {
            MState.Update(event);
            window.clear();
            MState.Render(window);
            Update(); Render();
            window.display();
        }
        ImGui::SFML::Shutdown();
        return 0;
    }
}