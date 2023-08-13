#pragma once
#include <SFML/Graphics.hpp>
#include "chessStructures.h"
#include "shared.h"
#include <iostream>

class ChessPieceController {
public:
    virtual bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const = 0;
    virtual bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const = 0;
    virtual std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhitePlayer) const = 0;

    const int BOARD_LENGTH = 7;
};
