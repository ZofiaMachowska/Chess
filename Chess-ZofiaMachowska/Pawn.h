#pragma once
#include "ChessPiece.h"

/**
 * @class Pawn
 * @brief Represents a Pawn chess piece.
 */
class Pawn : public ChessPiece {
private:
    bool hasMoved; /**< Flag indicating if the Pawn has moved. */

public:
    /**
     * @brief Constructor for Pawn.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    Pawn(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for Pawn.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("P").
     */
    std::string type() const override;

    /**
     * @brief Set the "hasMoved" flag for the Pawn.
     * @param moved True if the Pawn has moved, false otherwise.
     */
    void setHasMoved(bool moved);

    /**
     * @brief Check if the Pawn has moved.
     * @return True if the Pawn has moved, false otherwise.
     */
    bool getHasMoved() const;
};
