#pragma once
#include "Board.h"
#include "Move.h"

/**
 * @class MoveValidator
 * @brief Provides methods for validating chess moves.
 */
class MoveValidator {
public:
    /**
     * @brief Check if a move is valid for the current player.
     *
     * @param board The chessboard.
     * @param move The move to validate.
     * @param currentPlayer The color of the current player ("white" or "black").
     * @return True if the move is valid, false otherwise.
     */
    static bool isValidMove(ChessPiece* board[][8], Move move, std::string currentPlayer);

private:
    /**
     * @brief Check if the path for a linear move is clear.
     *
     * @param board The chessboard.
     * @param move The move to check.
     * @return True if the path is clear, false otherwise.
     */
    static bool isPathClearLinear(ChessPiece* board[][8], Move move);

    /**
     * @brief Check if the path for a diagonal move is clear.
     *
     * @param board The chessboard.
     * @param move The move to check.
     * @return True if the path is clear, false otherwise.
     */
    static bool isPathClearDiagonal(ChessPiece* board[][8], Move move);

    /**
     * @brief Check if the path for a specific piece type is clear.
     *
     * @param board The chessboard.
     * @param move The move to check.
     * @param pieceType The type of the chess piece.
     * @return True if the path is clear, false otherwise.
     */
    static bool checkPathClear(ChessPiece* board[][8], Move move, std::string pieceType);

    /**
     * @brief Check if the path for a pawn move is clear.
     *
     * @param board The chessboard.
     * @param move The move to check.
     * @return True if the path is clear, false otherwise.
     */
    static bool isPathClearPawn(ChessPiece* board[][8], Move move);
};
