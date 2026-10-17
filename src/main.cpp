#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Utils.hpp"
#include "Field.hpp"
#include "Cross.hpp"
#include "Circle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "krestik0!");

    Field field;
    std::vector<std::unique_ptr<sf::Drawable>> marks;

    Board board = EmptyBoard();
    bool cross_turn = true;
    bool stop = false;

    auto draw = [&]{
        window.clear(sf::Color::Yellow);
        window.draw(field);
        for(const auto &mark : marks){
            window.draw(*mark);
        }
        window.display();
    };

    draw();

    // Turn-based game: block until something happens instead of rendering
    // frames in a tight loop (that busy loop was burning a third of a core).
    while (window.isOpen())
    {
        sf::Event event;
        if(!window.waitEvent(event)){
            break;
        }

        do
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed && !stop){
                if(event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    int pos_x = position.x / 100;
                    int pos_y = position.y / 100;

                    if(pos_x < 0 || pos_x > 2 || pos_y < 0 || pos_y > 2){
                        continue;
                    }

                    if(board[pos_x][pos_y] != CONTENT::EMPTY){
                        continue;
                    }

                    CONTENT played = cross_turn ? CONTENT::CROSS : CONTENT::CIRCLE;
                    sf::Vector2f center(pos_x * 100 + 50, pos_y * 100 + 50);

                    if(cross_turn){
                        marks.push_back(std::make_unique<Cross>(center, sf::Color::Black, 3, 113));
                    }else{
                        marks.push_back(std::make_unique<Circle>(40, sf::Color::Black, sf::Color::Yellow, 3, center));
                    }

                    board[pos_x][pos_y] = played;
                    cross_turn = !cross_turn;

                    // Check the board once per move, not twice per frame.
                    if(auto win = WinLine(board, played)){
                        marks.push_back(std::move(win));
                        stop = true;
                    }
                }
            }

            if(event.type == sf::Event::KeyPressed && stop){
                if(event.key.code == sf::Keyboard::Escape){
                    marks.clear();
                    board = EmptyBoard();
                    cross_turn = true;
                    stop = false;
                }
            }
        }
        while (window.pollEvent(event));

        if(window.isOpen()){
            draw();
        }
    }

    return 0;
}
