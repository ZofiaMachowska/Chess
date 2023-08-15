#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "Player.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Represents a chess move made by a player.
 *
 * This structure captures the initial and final positions of a piece
 * during a move and type of the piece that was moved.
 */
struct Move {
    sf::Vector2i start;        ///< The starting position of the piece on the board.
    sf::Vector2i destination;  ///< The destination position of the piece on the board.
    int pieceType;             ///< The type of the piece being moved.
};

/**
 * @brief Represents the evaluation of a particular move in terms of its quality or advantage.
 */
struct MoveEvaluation {
    Move move;       ///< The move that was evaluated.
    int evaluation;  ///< The value representing the quality of the move.
};

/**
 * @brief Represents the AI options for each player.
 *
 * This structure allows the game to know if either of the players is controlled by the AI.
 */
struct Options {
    bool firstPlayerAi;   ///< Indicates whether the first player is controlled by the AI.
    bool secondPlayerAi;  ///< Indicates whether the second player is controlled by the AI.
};

/**
 * @brief Represents a saved game state, including the board configuration and players' details.
 *
 * This structure captures all the necessary details to save and then reload a game.
 */
struct Game {
    int board[8][8];               ///< The configuration of the board.
    Player* player1;               ///< Pointer to the first player's details.
    Player* player2;               ///< Pointer to the second player's details.
    bool gameOver;                ///< Indicates whether the game has ended.
    std::string timeOfSaving;     ///< The timestamp indicating when the game was saved.
};