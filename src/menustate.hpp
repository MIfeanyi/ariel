#include "state.hpp"
class MenuState: public State {
    public:
        sf::CircleShape shape;
        void Init();
        void Update(sf::Event &e);
        void Render(sf::RenderWindow &w);
};