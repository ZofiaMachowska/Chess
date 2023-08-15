#pragma once
#define KNIGHTCONTROLLER_H
#include "ChessPieceController.h"

/**
 * @class KnightController
 * @brief Class for controlling the behavior of a knight in chess.
 *
 * Provides the functionalities specific to a knight.
 */
class KnightController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a knight.
     *
     * @param oldPos Starting position of the knight.
     * @param newPos Desired position to move to.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Checks if the knight's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the knight.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the knight from a specific position.
     *
     * @param pos Current position of the knight.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    const int BLACK_KNIGHT = 3; /**< Identifier for a black knight. */
    const int WHITE_KNIGHT = -3; /**< Identifier for a white knight. */
    const int VALUE = 3; /**< Point value for capturing a knight. */
};
