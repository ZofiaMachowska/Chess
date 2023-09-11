#include "Rook.h"

Rook::Rook(int row, int col, std::string color) : ChessPiece(row, col, color) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Rook::possibleMoves() const {
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

    return moves;
}

std::string Rook::type() const {
    return "R";
}
