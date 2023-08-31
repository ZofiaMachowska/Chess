#include "Bishop.h"

Bishop::Bishop(int row, int col, std::string color) : ChessPiece() {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Bishop::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    // Diagonal moves for Bishop
    const int dx[] = { -1, -1, 1, 1 };
    const int dy[] = { -1, 1, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        for (int step = 1; step < 8; ++step) {
            int newRow = row + step * dx[i];
            int newCol = col + step * dy[i];

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                moves.push_back(std::make_pair(newRow, newCol));
            }
        }
    }

    return moves;
}


//bool Bishop::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
//    int fromRow = getRow();
//    int fromCol = getCol();
//
//    // Sprawdzenie, czy ruch jest po przek¹tnej
//    if (abs(fromRow - toRow) != abs(fromCol - toCol)) {
//        return false;
//    }
//
//    // Sprawdzenie, czy pomiêdzy startowym i koñcowym polem nie ma innych pionków
//    int rowStep = (fromRow < toRow) ? 1 : -1;
//    int colStep = (fromCol < toCol) ? 1 : -1;
//
//    int stepRow = fromRow + rowStep;
//    int stepCol = fromCol + colStep;
//
//    while (stepRow != toRow && stepCol != toCol) {
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

std::string Bishop::type() const {
    return "B";
}
