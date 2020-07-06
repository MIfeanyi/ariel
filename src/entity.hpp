#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include<string>

#include"entitymanager.hpp"
#include"component.hpp"
#include"game.hpp"
#include"chaiscript/chaiscript.hpp"

class EntityManager;
class Component;

class Entity{
    private:
        EntityManager& manager;
        bool isActive;
        std::vector<Component*> components;
    public:
        std::string name;
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        void Update(float deltaTime);
        void Render(sf::RenderWindow &w);
        void Destroy();
        bool IsActive() const;
	    void NewComponent(chaiscript::ChaiScript &c);
        template <typename T,typename ... TArgs>
        T& AddComponent(TArgs&&... args){
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->Init();
            return *newComponent;
        }
};


#endif
