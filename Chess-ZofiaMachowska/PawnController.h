#pragma once
#define PAWNCONTROLLER_H
#include "ChessPieceController.h"

class PawnController : public ChessPieceController {
public:

    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhitePlayer) const override;
};
