#pragma once
#include "Player.h"
#include "AIController.h"
#include "chessStructures.h"
#include <thread>
#include <chrono>
#include <random>

/**
 * @brief Manages the game players, their attributes, and associated actions.
 */
class PlayerController {
public:
    /**
     * @brief Constructs a new PlayerController object with default attributes.
     */
    PlayerController();

    /**
     * @brief Destroys the PlayerController object and frees associated resources.
     */
    ~PlayerController();

    /**
     * @brief Sets players' AI status based on game options.
     *
     * @param aiOptions Options object containing AI settings.
     */
    void setPlayersAiFromOptions(Options aiOptions);

    /**
     * @brief Loads player attributes from a saved game.
     *
     * @param gameToLoad Game object containing saved player attributes.
     */
    void setLoadedPlayers(Game gameToLoad);

    /**
     * @brief Determines if the AI should make a move based on the current player and board state.
     *
     * @param board Current state of the chessboard.
     */
    void shouldRunAI(int board[][8]);

    /**
     * @brief Switches the active player and updates the game state accordingly.
     *
     * @param board Current state of the chessboard.
     */
    void switchPlayer(int board[][8]);

    /**
     * @brief Starts the timer for the active player.
     */
    void startTimer();

    /**
     * @brief Resets the game to start with the first player.
     */
    void resetFirstPlayer();

    /**
     * @brief Determines if it's the first player's turn.
     *
     * @return true if it's the first player's turn, false otherwise.
     */
    bool isFirstPlayerTurn();

    /**
     * @brief Checks if the currently active player is controlled by AI.
     *
     * @return true if the active player is an AI, false otherwise.
     */
    bool isActivePlayerAI();

    /**
     * @brief Returns a pointer to the currently active player.
     *
     * @return Pointer to the active Player object.
     */
    Player* getCurrentPlayer();

    /**
     * @brief Returns a vector containing pointers to all players.
     *
     * @return Vector of Player pointers.
     */
    std::vector<Player*> getPlayers();

private:
    /**
     * @brief Pointer to the first player.
     */
    Player* player1;

    /**
     * @brief Pointer to the second player.
     */
    Player* player2;

    /**
     * @brief AIController object to manage AI player actions.
     */
    AIController aiController;
};