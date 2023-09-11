#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "ChessPiece.h"
#include "MoveValidator.h"
#include "Move.h"

/**
 * @class Board
 * @brief Represents a chessboard.
 *
 * The `Board` class is responsible for managing the chessboard and its pieces.
 */
class Board {
private:
    ChessPiece* board[8][8]; /**< The main chessboard representing piece positions. */
    ChessPiece* temporaryTestingBoard[8][8]; /**< Temporary board for move testing. */

public:
    /**
     * @brief Default constructor for Board.
     * Initializes the chessboard.
     */
    Board();

    /**
     * @brief Destructor for Board.
     * Cleans up resources.
     */
    ~Board();

    /**
     * @brief Initialize the chessboard with pieces in their initial positions.
     */
    void initialize();

    /**
     * @brief Get the chess piece at a specific position.
     *
     * @param row The row index.
     * @param col The column index.
     * @return A pointer to the chess piece at the specified position.
     */
    ChessPiece* getPiece(int row, int col) const;

    /**
     * @brief Set the chess piece at a specific position.
     *
     * @param row The row index.
     * @param col The column index.
     * @param piece Pointer to the chess piece to place on the board.
     */
    void setPiece(int row, int col, ChessPiece* piece);

    /**
     * @brief Move a chess piece from one position to another.
     *
     * @param fromRow The starting row.
     * @param fromCol The starting column.
     * @param toRow The target row.
     * @param toCol The target column.
     */
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);

    /**
     * @brief Print the current state of the chessboard.
     */
    void printBoard() const;

    /**
     * @brief Get the chess piece at a specific position.
     *
     * @param row The row index.
     * @param col The column index.
     * @return A pointer to the chess piece at the specified position.
     */
    ChessPiece* getPieceAt(int row, int col);

    /**
     * @brief Prepare a temporary board for move testing.
     */
    void prepareTemporaryBoard();

    /**
     * @brief Get a reference to the main chessboard.
     *
     * @return A reference to the main chessboard.
     */
    ChessPiece* (&getBoard())[8][8];

    /**
     * @brief Get a reference to the temporary testing board.
     *
     * @return A reference to the temporary testing board.
     */
    ChessPiece* (&getTemporaryBoard())[8][8];

    /**
     * @brief Check if a move is possible for the current player.
     *
     * @param move The move to be tested.
     * @param currentPlayer The color of the current player ("white" or "black").
     * @return True if the move is possible, false otherwise.
     */
    bool isMovePossible(Move move, std::string currentPlayer);
};
