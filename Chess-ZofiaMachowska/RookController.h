#pragma once
#include "ChessPieceController.h"

/**
 * @class RookController
 * @brief Class for controlling the behavior of a rook in chess.
 *
 * Provides functionalities specific to a rook.
 */
class RookController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a rook.
     *
     * @param oldPos Starting position of the rook.
     * @param newPos Desired position to move to.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Checks if the rook's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the rook.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the rook from a specific position.
     *
     * @param pos Current position of the rook.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    const int BLACK_ROOK = 2;  /**< Identifier for a black rook. */
    const int WHITE_ROOK = -2; /**< Identifier for a white rook. */
    const int VALUE = 5;       /**< Point value for capturing a rook. */

private:
    /**
     * @brief Contains directions the rook can move in.
     */
    std::vector<sf::Vector2i> directions = {
    sf::Vector2i(0, 1),
    sf::Vector2i(0, -1),
    sf::Vector2i(1, 0),
    sf::Vector2i(-1, 0)
    };
};
