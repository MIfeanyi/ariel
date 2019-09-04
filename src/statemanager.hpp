#include "state.hpp"
#include <unordered_map>

using StatesID = int64_t;

template <class Type>
using StatesMap = std::unordered_map<StatesID, Type>;
using States = StatesMap<State>;
class StateManager {
    public:
        template <class Type>
        void AddState(StatesID id, Type & T){
            states[id] = T;
        };
        void Init();
        void Run();
        void Update(sf::Event & e){
            states[current].Update(e);

        };
        void Render(sf::RenderWindow & w){
            for(auto& [id,state]: states){
                if(id==current){
                    states[current].Render(w);
                }
            }
        };
        void SwitchState(StatesID id){
            current = id;
        };
    private:
        StatesID current;
        States states;
};
