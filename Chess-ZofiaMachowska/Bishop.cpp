#include "Bishop.h"

Bishop::Bishop(int row, int col, std::string color) : ChessPiece(row, col, color) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Bishop::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;
    const int dx[] = { -1, -1, 1, 1 };
    const int dy[] = { -1, 1, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        for (int step = 1; step < 8; ++step) {
            int newRow = getRow() + step * dx[i];
            int newCol = getCol() + step * dy[i];

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                moves.push_back(std::make_pair(newRow, newCol));
            }
        }
    }
    return moves;
}

std::string Bishop::type() const {
    return "B";
}
