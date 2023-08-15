#pragma once
#include <SFML/Graphics.hpp>
#include "chessStructures.h"
#include "shared.h"
#include <iostream>

/**
 * @class ChessPieceController
 * @brief Abstract class defining functionalities for chess pieces.
 *
 * This class provides a set of virtual methods that are meant to be overridden by specific chess piece classes.
 */
class ChessPieceController {
public:
    /**
     * @brief Determines if a move from an old position to a new position is possible.
     *
     * @param oldPos Starting position of the piece.
     * @param newPos Desired position to move to.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move is possible, false otherwise.
     */
    virtual bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const = 0;

    /**
     * @brief Checks if the move results in capturing the opponent's king.
     *
     * @param oldPos Starting position of the piece.
     * @param kingPos Position of the opponent's king.
     * @param board Current state of the board.
     * @param isWhite Flag to determine if the player is white.
     * @return true if the move captures the king, false otherwise.
     */
    virtual bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const = 0;

    /**
     * @brief Generates a list of valid moves for a given piece from a specific position.
     *
     * @param pos Current position of the piece.
     * @param board Current state of the board.
     * @param isWhitePlayer Flag to determine if the player is white.
     * @return A vector containing all valid moves.
     */
    virtual std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhitePlayer) const = 0;

    const int BOARD_LENGTH = 7; /**< Defines the length of the board. */
};
