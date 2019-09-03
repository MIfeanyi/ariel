#include <SFML/Graphics.hpp> 

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui-SFML.h"
#include "statemanager.hpp"
#include "script.hpp"

using namespace std;

class Game{
    public:
        void Init();
        void Update();
        void Render();
        void Close();
        virtual int Run()
        {
             while (window.isOpen()) {
                 Update();
                 Render();
             }
             return 0;
        };
        StateManager mStates;
    protected:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock deltaClock;
        vector <string>States;
        Script script;
        bool Running = true;
};
