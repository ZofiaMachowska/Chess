#pragma once
#include "ChessPieceController.h"

class PawnController : public ChessPieceController {
public:
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const override;
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;
    std::vector<Move> generateValidMoves(sf::Vector2i position, int board[][8], bool isWhitePlayer) const override;

    const int BLACK_PAWN = 1;
    const int WHITE_PAWN = -1;
    const int VALUE = 1;
};
