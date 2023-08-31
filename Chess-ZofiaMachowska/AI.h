#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Board.h"
#include "Move.h"
#include "Player.h"
#include "MoveValidator.h"
#include <random>

class AI {
private:
    std::string color;
    MoveValidator moveValidator;

public:
    AI(const std::string& playerColor);

    Move makeMove(Board& board, Player* currentPlayer);
};
