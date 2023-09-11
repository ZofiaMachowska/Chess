#pragma once
#include "ChessPiece.h"

/**
 * @class Bishop
 * @brief Represents a Bishop chess piece.
 */
class Bishop : public ChessPiece {
public:
    /**
     * @brief Constructor for Bishop.
     * @param row The row on the chessboard.
     * @param col The column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    Bishop(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for Bishop.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("B").
     */
    std::string type() const override;
};
