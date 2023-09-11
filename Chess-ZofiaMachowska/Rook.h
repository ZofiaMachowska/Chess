#pragma once
#include "ChessPiece.h"

/**
 * @class Rook
 * @brief Represents a Rook chess piece.
 */
class Rook : public ChessPiece {
public:
    /**
     * @brief Constructor for Rook.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    Rook(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for Rook.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("R").
     */
    std::string type() const override;
};
