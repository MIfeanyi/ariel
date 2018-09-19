#include <vector>
#include "state.hpp"

template <class T>
class StateManager {
    public:
        void AddState(T & s);
        void Init();
        void Run();
        void Update(sf::Event & e);
        void Render(sf::RenderWindow &w);
        bool SwitchState(std::string n);
        T GetState();
    private:
    std::vector<State*> States;
    T CurrentState;
};