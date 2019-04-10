#include <SFML/Graphics.hpp> 

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui-SFML.h"
#include "state.hpp"
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
        };
    protected:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock deltaClock;
        string CurrentState;
        vector <string>States;
        Script script;
        bool Running = true;
};
