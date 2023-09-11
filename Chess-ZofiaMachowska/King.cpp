#include "King.h"

King::King(int row, int col, std::string color) : ChessPiece(row, col, color), hasMoved(false) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> King::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    const int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    const int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int i = 0; i < 8; ++i) {
        int newRow = getRow() + dx[i];
        int newCol = getCol() + dy[i];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            moves.push_back(std::make_pair(newRow, newCol));
        }
    }

    return moves;
}

std::string King::type() const {
    return "K";
}

void King::setHasMoved(bool moved) {
    hasMoved = moved;
}

bool King::getHasMoved() const { return hasMoved; }