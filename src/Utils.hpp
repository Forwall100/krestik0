#pragma once
#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Line.hpp"

enum CONTENT{
    CIRCLE,
    CROSS,
    EMPTY
};

using Board = std::array<std::array<CONTENT, 3>, 3>;

// All cells EMPTY. Never rely on zero-initialization: CIRCLE is 0.
Board EmptyBoard();

// Returns the winning line, or nullptr when `type` has no three in a row.
std::unique_ptr<Line> WinLine(const Board &board, CONTENT type);
