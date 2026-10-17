#include "Utils.hpp"

Board EmptyBoard(){
    Board board;
    for(auto &row : board){
        row.fill(CONTENT::EMPTY);
    }
    return board;
}

std::unique_ptr<Line> WinLine(const Board &board, CONTENT type){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == type && board[i][1] == type && board[i][2] == type){
            return std::make_unique<Line>(300, 3, 90, sf::Vector2f(50 + 100 * i, 0), sf::Color::Black);
        }
        if(board[0][i] == type && board[1][i] == type && board[2][i] == type){
            return std::make_unique<Line>(300, 3, 0, sf::Vector2f(0, 50 + 100 * i), sf::Color::Black);
        }
    }

    if(board[0][0] == type && board[1][1] == type && board[2][2] == type){
        return std::make_unique<Line>(450, 3, 45, sf::Vector2f(0, 0), sf::Color::Black);
    }

    if(board[0][2] == type && board[1][1] == type && board[2][0] == type){
        return std::make_unique<Line>(450, 3, -45, sf::Vector2f(0, 300), sf::Color::Black);
    }

    return nullptr;
}
