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

/**
 * @class AI
 * @brief Represents an artificial intelligence player for chess.
 *
 * The AI class is responsible for making intelligent moves in a chess game.
 */
class AI {
private:
    std::string color; /**< The color of the AI player ("white" or "black"). */
    MoveValidator moveValidator; /**< Validator for checking the validity of moves. */

public:
    /**
     * @brief Constructor for AI.
     *
     * @param playerColor The color of the AI player ("white" or "black").
     */
    AI(const std::string& playerColor);

    /**
     * @brief Make a move for the AI player.
     *
     * This function generates and returns a move for the AI player based on the current
     * state of the chessboard and the player whose turn it is.
     *
     * @param board Reference to the chessboard.
     * @param currentPlayer Pointer to the current player.
     * @return The generated move.
     */
    Move makeMove(ChessPiece* board[][8], Player* currentPlayer);
};
