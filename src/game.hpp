#include <SFML/Graphics.hpp> 

#include "state.hpp"
class Game : public State {
    public:
    void Init();
    void Update(sf::Event & e);
    void Render(sf::RenderWindow & w);
};
