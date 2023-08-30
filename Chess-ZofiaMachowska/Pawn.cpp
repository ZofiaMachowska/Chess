#include "Pawn.h"

Pawn::Pawn(int row, int col, std::string color) : ChessPiece(), hasMoved(false) {
    setPosition(row, col);
    this->color = color;
}

std::vector<std::pair<int, int>> Pawn::possibleMoves() const {
    std::vector<std::pair<int, int>> moves;

    // Bia�e pionki poruszaj� si� "do g�ry", czarne "na d�"
    int direction = (color == "W") ? 1 : -1;

    // Prosty ruch o jedno pole
    int newRow = row + direction;
    if (newRow >= 0 && newRow < 8) {
        moves.push_back(std::make_pair(newRow, col));
    }

    // Ruch o dwa pola, je�eli pionek nie rusza� si� jeszcze
    if (!hasMoved) {
        newRow = row + 2 * direction;
        if (newRow >= 0 && newRow < 8) {
            moves.push_back(std::make_pair(newRow, col));
        }
    }

    // TODO: Atak na skos, en passant, i promocja s� bardziej z�o�onymi ruchami i mog� by� dodane p�niej

    return moves;
}

bool Pawn::isValidMove(int toRow, int toCol, ChessPiece* board[][8]) {
    int fromRow = getRow();
    int fromCol = getCol();

    int rowDiff = toRow - fromRow;
    int colDiff = abs(toCol - fromCol);

    std::string color = getColor(); // Pobieranie koloru pionka

    // Sprawdzenie, czy ruch jest o jedno pole do przodu (lub dwa pola w pierwszym ruchu) i w tej samej kolumnie
    if ((color == "W" && rowDiff != -1 && rowDiff != -2) ||
        (color == "B" && rowDiff != 1 && rowDiff != 2)) {
        return false;
    }

    // Sprawdzenie, czy pionek wykonuje atak na ukos
    if (colDiff == 1 && rowDiff == ((color == "W") ? -1 : 1)) {
        if (board[toRow, toCol] == nullptr) {
            return false; // Brak pionka do zaatakowania
        }
    }
    else if (colDiff != 0 || (rowDiff == 2 && hasMoved)) {
        return false;
    }

    // Sprawdzenie, czy na docelowym polu nie ma innego pionka tego samego koloru
    if (board[toRow, toCol] != nullptr) {
        return false;
    }

    // Je�li �adne z powy�szych warunk�w nie zosta�o spe�nione, ruch jest prawid�owy
    if (!hasMoved) {
        setHasMoved(true);
    }
    return true;
}


std::string Pawn::type() const {
    return "P";
}

void Pawn::setHasMoved(bool moved) {
    hasMoved = moved;
}

bool Pawn::getHasMoved() const { return hasMoved; }

