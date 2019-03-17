#include<SFML/Graphics.hpp>
#include<string>
#include "rect.hpp"

class Sprite: public Rect {
        sf::Texture* Texture;
    public:
        void Load(std::string file);
        void SetSmooth(bool s);
        void SetRect(int x, int y, int h, int w);
        void Offset(int x, int y);
        sf::Texture Draw();
        ~Sprite();
};