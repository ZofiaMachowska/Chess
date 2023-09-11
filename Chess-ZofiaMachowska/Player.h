#pragma once
#include "Timer.h"
#include <iostream>
#include <vector>
#include "Move.h"
#include "ChessPiece.h"
#include "Board.h"

/**
 * @class Player
 * @brief Represents a player in a chess game.
 */
class Player {
private:
    std::string color; /**< The player's color ("white" or "black"). */
    bool playerAI; /**< Flag indicating if the player is controlled by AI. */
    bool firstMove; /**< Flag indicating if it's the player's first move. */
    Timer* playerTimer; /**< Pointer to the player's timer. */

public:
    /**
     * @brief Default constructor for Player.
     */
    Player() = default;

    /**
     * @brief Constructor for Player.
     * @param color The player's color ("white" or "black").
     * @param playerAI True if the player is controlled by AI, false otherwise.
     */
    Player(std::string color, bool playerAI);

    /**
     * @brief Get the player's color.
     * @return The player's color ("white" or "black").
     */
    std::string getColor() const;

    /**
     * @brief Check if the player is controlled by AI.
     * @return True if the player is controlled by AI, false otherwise.
     */
    bool getIsPlayerAI() const;

    /**
     * @brief Set the flag indicating the player's first move.
     * @param move1 True if it's the player's first move, false otherwise.
     */
    void setFirstMove(bool move1);

    /**
     * @brief Check if it's the player's first move.
     * @return True if it's the player's first move, false otherwise.
     */
    bool isFirstMove();

    /**
     * @brief Start a new timer for the player.
     */
    void startNewTimer();

    /**
     * @brief Stop the player's timer.
     */
    void stopTimer();

    /**
     * @brief Resume the player's timer.
     */
    void resumeTimer();

    /**
     * @brief Get a pointer to the player's timer.
     * @return Pointer to the player's timer.
     */
    Timer* getTimer();

    /**
     * @brief Set the player's timer.
     * @param timer Pointer to the player's timer.
     */
    void setTimer(Timer* timer);

    /**
     * @brief Generate possible moves for the player.
     * @param board Reference to the chessboard.
     * @return Vector of possible moves.
     */
    std::vector<Move> generatePossibleMoves(Board& board);
};
