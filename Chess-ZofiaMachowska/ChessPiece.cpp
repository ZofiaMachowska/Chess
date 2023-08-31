#include "ChessPiece.h"

//bool ChessPiece::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
//    return false;
//}

void ChessPiece::setPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

int ChessPiece::getRow() const {
    return row;
}

int ChessPiece::getCol() const {
    return col;
}

std::string ChessPiece::getColor() const { return color; }