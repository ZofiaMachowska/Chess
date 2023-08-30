#include "MoveValidator.h"

bool MoveValidator::isValidMove(ChessPiece* board[][8], Move move, std::string currentPlayer) {
    int fromRow = move.fromRow;
    int fromCol = move.fromCol;
    int toRow = move.toRow;
    int toCol = move.toCol;

    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
        return false;
    }

    ChessPiece* pieceToMove = board[fromCol][fromRow];

    if (pieceToMove == nullptr) {
        return false;
    }
    if (pieceToMove->getColor() != currentPlayer) {
        return false;
    }

    ////// Sprawdzenie, czy ruch jest dozwolony dla tego typu pionka
    //if (!pieceToMove->isValidMove(toRow, toCol, board.getBoard())) {
    //    return false;
    //}

    //// Sprawdzenie, czy pole docelowe jest puste lub zawiera pionek przeciwnika
    //if (targetPiece != nullptr) {
    //    if (targetPiece->getColor() == currentPlayer) {
    //        return false;
    //    }
    //}
    return true;
}