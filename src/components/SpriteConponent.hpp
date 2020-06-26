#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SFML/Graphics.hpp>

#include"TransformConponent.hpp"

#include"../entitymanager.hpp"
#include"../component.hpp"
#include"../game.hpp"
#include"../vector2d.hpp"

class SpriteConponent: public TransformComponent{
    protected:
        sf::Sprite sprite;

};



#endif