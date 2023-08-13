#pragma once
#include "ChessPieceController.h"

class RookController : public ChessPieceController {
public:
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    const int BLACK_ROOK = 2;
    const int WHITE_ROOK = -2;
    const int VALUE = 5;

private:
    std::vector<sf::Vector2i> directions = {
    sf::Vector2i(0, 1),
    sf::Vector2i(0, -1),
    sf::Vector2i(1, 0),
    sf::Vector2i(-1, 0)
    };
};
