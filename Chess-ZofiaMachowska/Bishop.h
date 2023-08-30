#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece {
public:
    Bishop(int row, int col, std::string color);

    std::vector<std::pair<int, int>> possibleMoves() const override;
    bool isValidMove(int toRow, int toCol, ChessPiece* board[][8]) override;
    std::string type() const override;
};
