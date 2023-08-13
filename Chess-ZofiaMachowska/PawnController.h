#pragma once
#include "ChessPieceController.h"

/**
 * @class PawnController
 * @brief Class for controlling the behavior of a pawn in a chess game.
 *
 * Provides the functionalities specific to a pawn, like determining its valid moves, checking if it can capture the opponent's king, and pawn promotions.
 */
class PawnController : public ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible for a pawn.
     *
     * @param oldPos Starting position of the pawn.
     * @param newPos Desired position to move to.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the pawn is white.
     * @return true if the move is possible, false otherwise.
     */
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const override;

    /**
     * @brief Checks if the pawn's move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the pawn.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the chess board.
     * @param isWhite Flag to determine if the pawn is white.
     * @return true if the move captures the king, false otherwise.
     */
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;

    /**
     * @brief Generates a list of valid moves for the pawn from a specific position.
     *
     * @param position Current position of the pawn.
     * @param board Current state of the chess board.
     * @param isWhitePlayer Flag to determine if the pawn is white.
     * @return A vector containing all valid moves.
     */
    std::vector<Move> generateValidMoves(sf::Vector2i position, int board[][8], bool isWhitePlayer) const override;

    const int BLACK_PAWN = 1;  /**< Identifier for a black pawn. */
    const int WHITE_PAWN = -1; /**< Identifier for a white pawn. */
    const int VALUE = 1;       /**< Value assigned to the pawn for gameplay purposes. */
};
