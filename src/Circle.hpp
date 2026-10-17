#pragma once
#include <SFML/Graphics.hpp>

class Circle : public sf::Drawable{
public:
    Circle(float rad, sf::Color color, sf::Color bg, float thickness, sf::Vector2f coord);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override{
        target.draw(circle, states);
    }

    sf::CircleShape circle;
};
