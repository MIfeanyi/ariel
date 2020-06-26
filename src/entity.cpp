#include"entity.hpp"

Entity::Entity(EntityManager& manager): manager(manager){
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name): manager(manager), name(name) {
    this->isActive = true;
}

void Entity::Update(float deltaTime){
    for (auto& component: components){
        component->Update(deltaTime);
    }  
}
void Entity::Render(sf::RenderWindow &w){
    for (auto& component: components){
    component->Render(w);
    }  
}
void Entity::Destroy(){
    isActive = false;
}
bool Entity::IsActive() const{
    return isActive;
}