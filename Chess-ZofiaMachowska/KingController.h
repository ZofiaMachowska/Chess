#pragma once
#include "ChessPieceController.h"

/**
 * @class KingController
 * @brief Class for controlling the behavior of a king in a chess game.
 *
 * Provides the functionalities specific to a king, like determining its valid moves, checking if it can capture another king, and finding its position.
 */
class KingController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a king.
     *
     * @param oldPos Starting position of the king.
     * @param newPos Desired position to move to.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the king is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Checks if the king's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the king.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the king is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the king from a specific position.
     *
     * @param pos Current position of the king.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the king is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Finds the position of the king on the board.
     *
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the king is white.
     * @return The position of the king as a Vector2i.
     */
    sf::Vector2i findKingPosition(int board[8][8], bool isWhite) const;

    const int BLACK_KING = 6; /**< Identifier for a black king. */
    const int WHITE_KING = -6; /**< Identifier for a white king. */

private:
    /**
     * @brief Finds the position of the white king on the board.
     *
     * @param board Current state of the chess board.
     * @return The position of the white king as a Vector2i.
     */
    sf::Vector2i findWhiteKingPosition(int board[8][8]) const;

    /**
     * @brief Finds the position of the black king on the board.
     *
     * @param board Current state of the chess board.
     * @return The position of the black king as a Vector2i.
     */
    sf::Vector2i findBlackKingPosition(int board[8][8]) const;

    std::vector<sf::Vector2i> directions = { /**< Directions in which the king can move. */
        sf::Vector2i(1, 0),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(0, -1),
        sf::Vector2i(1, 1),
        sf::Vector2i(1, -1),
        sf::Vector2i(-1, 1),
        sf::Vector2i(-1, -1)
    };
};
