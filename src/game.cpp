#include "game.hpp"

EntityManager manager;
sf::RenderWindow* Game::window;

void Game::Init(){
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(640, 480), "Ariel Engine");
    window->setFramerateLimit(30);
    //ImGui::SFML::Init(window);
}
void Game::Close(){
    
}

void Game::Update(){
    //call manager update
    int dt;
    manager.Update(dt);
}

void Game::Render(){
    window->clear();
    manager.Render();
    window->display();
}