#pragma once
#define CHESSPIECECONTROLLER_H
#include <SFML/Graphics.hpp>
#include <iostream>

class ChessPieceController {
public:

    virtual bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const = 0;

    virtual bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const = 0;

    const int BOARD_LENGTH = 7;

};
