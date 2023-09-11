#include "Pawn.h"

Pawn::Pawn(int row, int col, std::string color) : ChessPiece(row, col, color), hasMoved(false) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Pawn::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    int direction = (color == "W") ? -1 : 1;

    int newCol = getCol() + direction;  
    if (newCol >= 0 && newCol < 8) {
        moves.push_back(std::make_pair(getRow(), newCol)); 
    }

    int newRow = getRow() + 1;
    if (newCol >= 0 && newCol < 8 && newRow >= 0 && newRow < 8) {
        moves.push_back(std::make_pair(newRow, newCol));
    }

    newRow = getRow() - 1;
    if (newCol >= 0 && newCol < 8 && newRow >= 0 && newRow < 8) {
        moves.push_back(std::make_pair(newRow, newCol));
    }

    if (!hasMoved) {
        newCol = getCol() + 2 * direction;
        if (newCol >= 0 && newCol < 8) {
            moves.push_back(std::make_pair(getRow(), newCol));
        }
    }
    return moves;
}

std::string Pawn::type() const {
    return "P";
}

void Pawn::setHasMoved(bool moved) {
    hasMoved = moved;
}

bool Pawn::getHasMoved() const { return hasMoved; }

