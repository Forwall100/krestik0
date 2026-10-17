#pragma once
#include <SFML/Graphics.hpp>

class Line : public sf::Drawable{
public:
    Line(float length, float thickness, float rotation, sf::Vector2f coord, sf::Color color);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override{
        target.draw(line, states);
    }

    sf::RectangleShape line;
};
