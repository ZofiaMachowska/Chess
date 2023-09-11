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

//bool Rook::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
//    int fromRow = getRow();
//    int fromCol = getCol();
//
//    // Sprawdzenie, czy ruch jest w tej samej kolumnie lub rz�dzie
//    if (fromRow != toRow && fromCol != toCol) {
//        return false;
//    }
//
//    // Sprawdzenie, czy pomi�dzy startowym i ko�cowym polem nie ma innych pionk�w
//    int rowStep = (fromRow < toRow) ? 1 : (fromRow > toRow) ? -1 : 0;
//    int colStep = (fromCol < toCol) ? 1 : (fromCol > toCol) ? -1 : 0;
//
//    int stepRow = fromRow + rowStep;
//    int stepCol = fromCol + colStep;
//
//    while (stepRow != toRow || stepCol != toCol) {
//        if (board[stepRow, stepCol] != nullptr) {
//            return false; // Jest pionek na drodze
//        }
//        stepRow += rowStep;
//        stepCol += colStep;
//    }
//
//    // Je�li �adne z powy�szych warunk�w nie zosta�o spe�nione, ruch jest prawid�owy
//    return true;
//}


std::string Rook::type() const {
    return "R";
}
