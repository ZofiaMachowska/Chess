#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
private:
    bool hasMoved;
public:
    Pawn(int row, int col, std::string color);

    std::vector<std::pair<int, int>> possibleMoves() const override;
    std::string type() const override;
    void setHasMoved(bool moved);
   // bool isValidMove(int toRow, int toCol, ChessPiece* board[][8]) override;

    bool getHasMoved() const;
};

