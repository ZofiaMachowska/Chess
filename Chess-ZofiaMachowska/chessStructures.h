#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "ChessPiece.h"

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
struct GameSaveLoad {
    ChessPiece* board[8][8];               ///< The configuration of the board.
    Player player1;               ///< Pointer to the first player's details.
    Player player2;             ///< Pointer to the second player's details.
    std::string currentPlayerColor;
    bool gameOver;                ///< Indicates whether the game has ended.
    std::string timeOfSaving;     ///< The timestamp indicating when the game was saved.
};
