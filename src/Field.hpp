#pragma once
#include <SFML/Graphics.hpp>
#include "Line.hpp"

class Field : public sf::Drawable{
public:
    Field();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override{
        target.draw(line1, states);
        target.draw(line2, states);
        target.draw(line3, states);
        target.draw(line4, states);
    }

    Line line1, line2, line3, line4;
};
