#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinates.h"

/**
 * @class ChessPiece
 * @brief Represents a generic chess piece.
 */
class ChessPiece {
public:
    Coordinates<int> position; /**< Current position on the chessboard. */
    std::string color; /**< The color of the chess piece ("white" or "black"). */

    /**
     * @brief Constructor for ChessPiece.
     * @param row The initial row on the chessboard.
     * @param col The initial column on the chessboard.
     * @param color The piece color ("white" or "black").
     */
    ChessPiece(int row, int col, std::string color);

    /**
     * @brief Set the position of the chess piece.
     * @param row The new row.
     * @param col The new column.
     */
    void setPosition(int row, int col);

    /**
     * @brief Get the row of the chess piece.
     * @return The current row.
     */
    int getRow() const;

    /**
     * @brief Get the column of the chess piece.
     * @return The current column.
     */
    int getCol() const;

    /**
     * @brief Get the color of the chess piece.
     * @return The piece color ("white" or "black").
     */
    std::string getColor() const;

    /**
     * @brief Calculate possible moves for the chess piece.
     * @return Vector of possible moves as (row, col) pairs.
     */
    virtual std::vector<std::pair<int, int>> possibleMoves() const = 0;

    /**
     * @brief Get the type of the chess piece.
     * @return Type string (e.g., "Pawn", "Bishop").
     */
    virtual std::string type() const = 0;
};
