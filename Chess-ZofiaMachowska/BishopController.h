#pragma once
#include "ChessPieceController.h"

/**
 * @class BishopController
 * @brief Class for controlling the behavior of a bishop in chess.
 *
 * This class provides the functionalities specific to a bishop.
 */
class BishopController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a bishop.
     *
     * @param oldPos Starting position of the bishop.
     * @param newPos Desired position to move to.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Checks if the bishop's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the bishop.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the bishop from a specific position.
     *
     * @param pos Current position of the bishop.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;

    const int BLACK_BISHOP = 4; /**< Identifier for a black bishop. */
    const int WHITE_BISHOP = -4; /**< Identifier for a white bishop. */
    const int VALUE = 3; /**< Point value for capturing a bishop. */
};
