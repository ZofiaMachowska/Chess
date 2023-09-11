#include "Queen.h"

Queen::Queen(int row, int col, std::string color) : ChessPiece(row, col, color) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Queen::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    // Ruchy poziome i pionowe (jak dla wie¿y)
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

    // Ruchy po przek¹tnych (jak dla goñca)
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

//bool Queen::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
//    int fromRow = getRow();
//    int fromCol = getCol();
//
//    // Sprawdzenie, czy ruch jest po przek¹tnej lub w tej samej kolumnie/rzêdzie
//    if (fromRow != toRow && fromCol != toCol && abs(fromRow - toRow) != abs(fromCol - toCol)) {
//        return false;
//    }
//
//    // Sprawdzenie, czy pomiêdzy startowym i koñcowym polem nie ma innych pionków
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
//    // Jeœli ¿adne z powy¿szych warunków nie zosta³o spe³nione, ruch jest prawid³owy
//    return true;
//}


std::string Queen::type() const {
    return "Q";
}
