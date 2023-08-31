#pragma once
#include "Board.h"
#include "Move.h"

class MoveValidator {
public:
    static bool isValidMove(ChessPiece* board[][8], Move move, std::string currentPlayer);
private:
    static bool isPathClearLinear(ChessPiece* board[][8], Move move);
    static bool isPathClearDiagonal(ChessPiece* board[][8], Move move);
    static bool checkPathClear(ChessPiece* board[][8], Move move, std::string pieceType);
    static bool isPathClearFront(ChessPiece* board[][8], Move move);
};
