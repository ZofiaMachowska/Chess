#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>
#include <thread>
#include <cstring>
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Board.h"
#include "Move.h"

class AI {
public:
    static Move generateMove(Board& board, char playerColor);
};
