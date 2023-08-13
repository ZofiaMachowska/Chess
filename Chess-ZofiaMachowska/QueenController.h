#pragma once
#include "ChessPieceController.h"

/**
 * @class QueenController
 * @brief Class for controlling the behavior of a queen in a chess game.
 *
 * Provides functionalities specific to a queen, like determining its valid moves and checking if it can capture the opponent's king.
 */
class QueenController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a queen.
     *
     * @param oldPos Starting position of the queen.
     * @param newPos Desired position to move to.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the queen is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Checks if the queen's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the queen.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the queen is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the queen from a specific position.
     *
     * @param pos Current position of the queen.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the queen is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    const int BLACK_QUEEN = 5;  /**< Identifier for a black queen. */
    const int WHITE_QUEEN = -5; /**< Identifier for a white queen. */
    const int VALUE = 9;        /**< Value assigned to the queen for gameplay purposes. */

private:
    /**
     * @brief Contains directions the queen can move in (straight lines and diagonals).
     */
    std::vector<sf::Vector2i> directions = {
    sf::Vector2i(0, 1),
    sf::Vector2i(0, -1),
    sf::Vector2i(1, 0),
    sf::Vector2i(-1, 0),
    sf::Vector2i(1, 1),
    sf::Vector2i(1, -1),
    sf::Vector2i(-1, 1),
    sf::Vector2i(-1, -1)
    };
};
