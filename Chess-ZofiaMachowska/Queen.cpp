#include "Queen.h"

Queen::Queen(int row, int col, std::string color) : ChessPiece(row, col, color) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Queen::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < 8; ++i) {
        if (i != getCol()) {
            moves.push_back(std::make_pair(getRow(), i));
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (i != getRow()) {
            moves.push_back(std::make_pair(i, getCol()));
        }
    }
    for (int i = -7; i <= 7; ++i) {
        if (i != 0) {
            int newRow = getRow() + i;
            int newCol = getCol() + i;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                moves.push_back(std::make_pair(newRow, newCol));
            }

            newCol = getCol() - i;
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                moves.push_back(std::make_pair(newRow, newCol));
            }
        }
    }

    return moves;
}

std::string Queen::type() const {
    return "Q";
}
