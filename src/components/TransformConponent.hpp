#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SFML/Graphics.hpp>

#include"../entitymanager.hpp"
#include"../component.hpp"
#include"../game.hpp"
#include"../vector2d.hpp"


class TransformComponent: public Component {
    protected:
        int width;
        int hieght;
        int scale;
        Vector2D position;
        Vector2D velocity;
        sf::CircleShape shape;
    public:
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s){
            position.x = posX;
            position.y = posY;
            velocity.x = velX;
            velocity.y = velY;
            width = w;
            hieght = h;
            scale = s;
        }
        void Init() override {
            shape.setRadius(50.f);
            shape.setFillColor(sf::Color(100, 250, 50));
        }

        void Update(float deltaTime) override {
            //TODO
            position.x+= velocity.x;
            position.y+= velocity.y;
    
        }

        void Render(sf::RenderWindow &w) override {
            w.clear(sf::Color::Magenta);
            w.draw(shape);
        }
};

#endif