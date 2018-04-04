//TODO

#include "config.h"

#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

void splash()
{
    sf::RenderWindow splash(sf::VideoMode(400, 300), "My window", sf::Style::None);
    splash.clear();
    splash.display();
    sf::sleep(sf::milliseconds(1000));
    splash.close();
}