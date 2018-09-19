#include <SFML/Graphics.hpp> 
#include "state.hpp"
#include "menustate.hpp"
#include <iostream>
void MenuState::Init(){
    shape.setRadius(100);
    shape.setFillColor(sf::Color::Green);
    shape.setPointCount(500);
    std::cout<<"Setup Menu & Shape: "<<shape.getRadius()<<"\n";
}

void MenuState::Update(sf::Event & e){
    shape.setRadius(100);
    shape.setFillColor(sf::Color::Green);
    shape.setPointCount(500);
    std::cout<<"updating \n";
}

void MenuState::Render(sf::RenderWindow &w){
    std::cout<<"Drawing circle \n";
    w.draw(shape);
}