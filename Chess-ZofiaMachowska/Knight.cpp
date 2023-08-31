#include "Knight.h"

Knight::Knight(int row, int col, std::string color) : ChessPiece() {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Knight::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    // Definicja mo�liwych ruch�w skoczka
    const int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
    const int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            moves.push_back(std::make_pair(newRow, newCol));
        }
    }

    return moves;
}

//bool Knight::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
//    int fromRow = getRow();
//    int fromCol = getCol();
//
//    int rowDiff = abs(toRow - fromRow);
//    int colDiff = abs(toCol - fromCol);
//
//    // Sprawdzenie, czy ruch jest zgodny z ruchem skoczka (L-kszta�tny ruch)
//    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
//        // Sprawdzenie, czy pole docelowe jest puste lub zaj�te przez przeciwnika
//        if (board[toRow, toCol] == nullptr) {
//            return true; // Ruch jest prawid�owy
//        }
//    }
//
//    return false; // Ruch jest nieprawid�owy
//}


std::string Knight::type() const {
    return "N";  // 'N' jest u�ywane zamiast 'K' aby unikn�� konfliktu z kr�lem (King)
}
