#pragma once
#include "Board.h"
#include "Move.h"

class MoveValidator {
public:
    static bool isValidMove(ChessPiece* board[][8], Move move, std::string currentPlayer);
};
