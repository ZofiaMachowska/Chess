#pragma once
#include "ChessPiece.h"

/**
 * @class Knight
 * @brief Represents a Knight chess piece.
 */
class Knight : public ChessPiece {
public:
    /**
     * @brief Constructor for Knight.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    Knight(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for Knight.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("N").
     */
    std::string type() const override;
};
