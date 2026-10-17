#pragma once
#include <SFML/Graphics.hpp>
#include "Line.hpp"

class Cross : public sf::Drawable{
public:
    Cross(sf::Vector2f coord, sf::Color color, float thickness, float diagonal);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override{
        target.draw(line1, states);
        target.draw(line2, states);
    }

    Line line1, line2;
};
