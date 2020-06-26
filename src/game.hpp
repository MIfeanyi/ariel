#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp> 

#include <string>
#include <vector>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include"component.hpp"
#include"entity.hpp"
#include"entitymanager.hpp"
#include"components/TransformConponent.hpp"

using namespace std;

class Game{
    public:
        void Init();
        void Update();
        void Render();
        void Close();
        void TestLevel(int level);
        sf::RenderWindow window;
        virtual int Run()
        {
             while (window.isOpen()) {
                while (window.pollEvent(event)){
                    if (event.type == sf::Event::EventType::Closed){
                        window.close();
                    }
                }
                 Update();
                 Render();
             }
             Close();
             return 0;
        };
    protected:
        sf::Event event;
        sf::Clock deltaClock;
        bool Running = true;
};

#endif