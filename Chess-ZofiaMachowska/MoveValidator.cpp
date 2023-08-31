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

    std::vector<std::pair<int, int>> moves = pieceToMove->possibleMoves();

    moves.erase(
        std::remove_if(moves.begin(), moves.end(), [board, currentPlayer](std::pair<int, int> to) {
            ChessPiece* targetPiece = board[to.second][to.first];
            return (targetPiece != nullptr && targetPiece->getColor() == currentPlayer);
            }),
        moves.end()
    );

    bool movePossible = std::find(moves.begin(), moves.end(), std::make_pair(move.toRow, move.toCol)) != moves.end();
    if (movePossible) {
        std::string pieceType = pieceToMove->type();
        return checkPathClear(board,  move, pieceType);
    }
    return false;
}

bool MoveValidator::isPathClearLinear(ChessPiece* board[][8], Move move) {
    int fromRow = move.fromCol;
    int fromCol = move.fromRow;
    int toRow = move.toCol;
    int toCol = move.toRow;

    int rowStep = (toRow > fromRow) ? 1 : ((toRow < fromRow) ? -1 : 0);
    int colStep = (toCol > fromCol) ? 1 : ((toCol < fromCol) ? -1 : 0);

    if (rowStep == 0 && colStep == 0) {
        return false; 
    }

    if (rowStep == 0 || colStep == 0) {
        int curRow = fromRow + rowStep;
        int curCol = fromCol + colStep;

        while (curRow != toRow || curCol != toCol) {
            if (board[curRow][curCol] != nullptr) {
                return false;  
            }
            curRow += rowStep;
            curCol += colStep;
        }
    }

    return true;
}

bool MoveValidator::isPathClearDiagonal(ChessPiece* board[][8], Move move) {
    int fromRow = move.fromCol;
    int fromCol = move.fromRow;
    int toRow = move.toCol;
    int toCol = move.toRow;

    int rowStep = (toRow > fromRow) ? 1 : ((toRow < fromRow) ? -1 : 0);
    int colStep = (toCol > fromCol) ? 1 : ((toCol < fromCol) ? -1 : 0);

    if (rowStep == 0 && colStep == 0) {
        return false; 
    }

    if (rowStep != 0 && colStep != 0) {
        int curRow = fromRow + rowStep;
        int curCol = fromCol + colStep;

        while (curRow != toRow || curCol != toCol) {
            if (board[curRow][curCol] != nullptr) {
                return false;
            }
            curRow += rowStep;
            curCol += colStep;
        }
    }

    return true;
}


bool MoveValidator::isPathClearFront(ChessPiece* board[][8], Move move) {
    if (move.fromRow == move.toRow) {
        if (board[move.toCol][move.toRow] != nullptr) {
            return false;
        }
    }
    else if (std::abs(move.fromCol - move.toCol) == 1 && std::abs(move.fromRow - move.toRow) == 1) {
        if (board[move.toCol][move.toRow] == nullptr || board[move.toCol][move.toRow]->getColor() == board[move.fromCol][move.fromRow]->getColor()) {
            return false;
        }
    }
    return true;
}

bool MoveValidator::checkPathClear(ChessPiece* board[][8], Move move, std::string pieceType) {
    bool pathClear = true;
    if (pieceType == "R") {
        pathClear = isPathClearLinear(board, move);
    }
    else if (pieceType == "B") {
        pathClear = isPathClearDiagonal(board, move);
    }
    else if (pieceType == "Q") {
        pathClear = isPathClearLinear(board, move) && isPathClearDiagonal(board, move);
    }
    else if (pieceType == "P") {
        pathClear = isPathClearFront(board, move);
    }
    return pathClear;
}

