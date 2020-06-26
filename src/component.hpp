#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>

class Entity;

class Component {
    public:
        Entity* owner;
        virtual ~Component(){}
        virtual void Init(){}
        virtual void Update(float deltaTime){}
        virtual void Render(sf::RenderWindow &w){}

};

#endif