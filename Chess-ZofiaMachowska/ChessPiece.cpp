#include "ChessPiece.h"

ChessPiece::ChessPiece(int row, int col, std::string color) : position(row, col), color(color) {}

void ChessPiece::setPosition(int row, int col) {
    position.setX(row);
    position.setY(col);
}

int ChessPiece::getRow() const {
    return position.getX();
}

int ChessPiece::getCol() const {
    return position.getY();
}

std::string ChessPiece::getColor() const { return color; }