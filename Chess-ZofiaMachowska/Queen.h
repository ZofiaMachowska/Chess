#pragma once
#include "ChessPiece.h"

/**
 * @class Queen
 * @brief Represents a Queen chess piece.
 */
class Queen : public ChessPiece {
public:
    /**
     * @brief Constructor for Queen.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    Queen(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for Queen.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("Queen").
     */
    std::string type() const override;
};
