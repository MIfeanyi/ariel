#include "game.hpp"



EntityManager manager;

void Game::Init(){
    window.create(sf::VideoMode(640, 480), "Ariel Engine");
    window.setFramerateLimit(30);
    TestLevel(1);
    //ImGui::SFML::Init(window);
}

void Game::TestLevel(int level){
    Entity& newEntity(manager.AddEntity("projectile"));
    newEntity.AddComponent<TransformComponent>(0,0,20,20,32,32,1);
}
void Game::Close(){
    
}

void Game::Update(){
    //call manager update
    int dt;
    manager.Update(dt);
}

void Game::Render(){
    window.clear();
    if(!manager.HasNoEntities()){
        manager.Render(window);
    }
    window.display();
}