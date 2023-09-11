#pragma once
#include <vector>

/**
 * @class Move
 * @brief Represents a chess move.
 */
class Move {
public:
    int fromRow, fromCol, toRow, toCol; /**< Source and destination coordinates for the move. */

    /**
     * @brief Constructor for Move.
     * @param fromRow The source row.
     * @param fromCol The source column.
     * @param toRow The destination row.
     * @param toCol The destination column.
     */
    Move(int fromRow, int fromCol, int toRow, int toCol);
};
