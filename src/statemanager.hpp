#include <vector>
#include "state.hpp"

class StateManager {
    public:
        void AddState(State & s);
        void init();
        void Run();
        void Update(sf::Event & e);
        void Render(sf::RenderWindow & w);
        bool SwitchState(std::string n);
        std::string GetState();
    private:
    std::vector<State> States;
    std::string CurrentState;
};