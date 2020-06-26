#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include<vector>

#include"entity.hpp"
#include"component.hpp"

class EntityManager{
    private:
        std::vector<Entity*> entities;

    public:
        void ClearData();
        void Update(float deltaTime);
        void Render(sf::RenderWindow &w);
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        unsigned int GetEntityCount();
};
#endif