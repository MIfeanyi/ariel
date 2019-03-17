#include <vector>
#include "state.hpp"

class StateManager {
    public:
        void AddState(State S);
        void Init();
        void Run();
        void Update(sf::Event & e);
        void Render(sf::RenderWindow &w);
        bool SwitchState(std::string n);
    private:
    std::vector<State*> States;
};