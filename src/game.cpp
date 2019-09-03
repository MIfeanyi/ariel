#include "game.hpp"
#include "gui_test.hpp"


void Game::Init(){
    window.create(sf::VideoMode(640, 480), "Ariel Engine");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
}
void Game::Close(){
    
}

void Game::Update(){
    /*
    char input[255] ="";
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_MenuBar;
    bool* p_open;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::Begin("Load",p_open,window_flags);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) {}
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { window.close(); }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::InputText("filename",input,255);
    if(ImGui::Button("Run")){
        script.Eval(input);
    }
    ImGui::End();
    */
   mStates.Update(event);
}

void Game::Render(){
    /*
    window.clear();
    ImGui::SFML::Render(window);
    window.display(); */
    mStates.Render(window);
}