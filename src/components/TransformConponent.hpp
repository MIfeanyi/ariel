#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include"../entitymanager.hpp"
#include"../component.hpp"
#include"../game.hpp"
#include"../vector2d.hpp"

class TransformComponent: public Component {
    public:
        int width;
        int hieght;
        int scale;
        Vector2D position;
        Vector2D velocity;
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

        }

        void Update(float deltaTime) override {
            //TODO
            position.x+= velocity.x;
            position.y+= velocity.y;
    
        }

        void Render() override {
            //render sprite
            //TODO: call static window renderer from game class

        }
};

#endif