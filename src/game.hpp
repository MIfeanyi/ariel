#include <SFML/Graphics.hpp> 

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui-SFML.h"

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
    protected:
        sf::RenderWindow window;
        sf::Event event;
        sf::Clock deltaClock;
        vector <string>States;
        bool Running = true;
};
