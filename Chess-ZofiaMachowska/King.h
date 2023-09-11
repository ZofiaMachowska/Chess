#pragma once
#include "ChessPiece.h"

/**
 * @class King
 * @brief Represents a King chess piece.
 */
class King : public ChessPiece {
private:
    bool hasMoved; /**< Flag indicating if the King has moved. */

public:
    /**
     * @brief Constructor for King.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    King(int row, int col, std::string color);

    /**
     * @brief Calculate possible moves for King.
     * @return Vector of possible moves as (row, col) pairs.
     */
    std::vector<std::pair<int, int>> possibleMoves() const override;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string ("K").
     */
    std::string type() const override;

    /**
     * @brief Set the "hasMoved" flag for the King.
     * @param moved True if the King has moved, false otherwise.
     */
    void setHasMoved(bool moved);

    /**
     * @brief Check if the King has moved.
     * @return True if the King has moved, false otherwise.
     */
    bool getHasMoved() const;
};
