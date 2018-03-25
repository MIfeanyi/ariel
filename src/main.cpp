#include "config.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char* argv[]) {

  // Code adapted from the SFML 2 "Window" example.

  cout<<"Version "<<myproject_VERSION_MAJOR <<"."<< myproject_VERSION_MINOR;

  sf::Window App(sf::VideoMode(800, 600), "Ariel");

  while (App.isOpen()) {
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
	App.close();
    }
    App.display();
  }
}