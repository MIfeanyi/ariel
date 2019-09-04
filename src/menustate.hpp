#include <iostream>
#include "state.hpp"

const int MENU = 0;

class MenuState: public State {
    public:
        sf::CircleShape shape;
        void Init();
        void Update(sf::Event & e);
        void Render(sf::RenderWindow & w);
};