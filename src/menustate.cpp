#include <SFML/Graphics.hpp> 
#include "state.hpp"
#include "menustate.hpp"
#include <iostream>
void MenuState::Init(){
    std::cout<<"setup Menu";
    shape.setRadius(100);
    shape.setFillColor(sf::Color::Green);
}

void MenuState::Update(sf::Event & e){
    
}

void MenuState::Render(sf::RenderWindow & w){
    w.draw(shape);
}