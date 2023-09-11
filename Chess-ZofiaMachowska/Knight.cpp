#include "Knight.h"

Knight::Knight(int row, int col, std::string color) : ChessPiece(row, col, color) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Knight::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    const int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
    const int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int i = 0; i < 8; ++i) {
        int newRow = getRow() + dx[i];
        int newCol = getCol() + dy[i];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            moves.push_back(std::make_pair(newRow, newCol));
        }
    }
    return moves;
}

std::string Knight::type() const {
    return "N"; 
}
