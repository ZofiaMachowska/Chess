#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece {
public:
    Queen(int row, int col, std::string color);

    std::vector<std::pair<int, int>> possibleMoves() const override;
    std::string type() const override;
    bool isValidMove(int toRow, int toCol, ChessPiece* board[][8]) override;
};

