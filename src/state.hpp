#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class State {
    public:
        State(){};
        virtual void Init(){};
        virtual void Run(){};
        virtual void Clean(){};
        virtual void Update(sf::Event &e){};
        virtual void Render(sf::RenderWindow &w){};
        virtual ~State(){};
        void SetName(std::string n);
        std::string GetName();
    protected:
        std::string name;
};