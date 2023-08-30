#pragma once
#include <vector>

class Move {
public:
    int fromRow, fromCol, toRow, toCol;
    Move(int fromRow, int fromCol, int toRow, int toCol);
};