#include <SFML/Graphics.hpp> 

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui-SFML.h"

#include"component.hpp"
#include"entity.hpp"
#include"entitymanager.hpp"

using namespace std;

class Game{
    public:
        void Init();
        void Update();
        void Render();
        void Close();
        virtual int Run()
        {
             while (window->isOpen()) {
                while (window->pollEvent(event)){
                    if (event.type == sf::Event::EventType::Closed){
                        window->close();
                    }
                }
                 Update();
                 Render();
             }
             Close();
             return 0;
        };
    protected:
        static sf::RenderWindow *window;
        sf::Event event;
        sf::Clock deltaClock;
        bool Running = true;
};
