#pragma once
#include "Board.h"
#include "Player.h"
#include "Move.h"
#include "MoveValidator.h"
#include "AI.h"
#include <functional>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "chessStructures.h"
#include "Pawn.h"

/**
 * @class Game
 * @brief Represents a chess game.
 *
 * The `Game` class manages the chess game, including the board, players, and game logic.
 */
class Game {
private:
    Board board; /**< The chessboard for the game. */
    Player player1; /**< The first player. */
    Player player2; /**< The second player. */
    Player* currentPlayer; /**< Pointer to the current player. */
    ChessPiece* selectedPiece; /**< Pointer to the currently selected chess piece. */
    sf::Vector2i pieceOldPosition; /**< The old position of the selected piece. */
    AI ai; /**< The AI player. */
    bool gameOver; /**< Flag indicating whether the game is over. */

public:
    /**
     * @brief Constructor for Game.
     * @param player1AI True if the first player is AI-controlled, false otherwise.
     * @param player2AI True if the second player is AI-controlled, false otherwise.
     */
    Game(bool player1AI, bool player2AI);

    /**
     * @brief Start the chess game.
     */
    void start();

    /**
     * @brief Load a game from a saved state.
     * @param gameToLoad The saved game state to load.
     */
    void loadGame(GameSaveLoad gameToLoad);

    /**
     * @brief Switch to the next player's turn.
     */
    void switchPlayer();

    /**
     * @brief Check if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool isGameOver();

    /**
     * @brief Get a pointer to the current player.
     * @return Pointer to the current player.
     */
    Player* getCurrentPlayer();

    /**
     * @brief Get the first player.
     * @return The first player.
     */
    Player get1Player();

    /**
     * @brief Get the second player.
     * @return The second player.
     */
    Player get2Player();

    /**
     * @brief Get a reference to the chessboard.
     * @return A reference to the chessboard.
     */
    ChessPiece* (&getChessBoard())[8][8];

    /**
     * @brief Get the currently selected chess piece.
     * @return Pointer to the currently selected chess piece.
     */
    ChessPiece* getSelectedPiece();

    /**
     * @brief Handle a click event on the chessboard.
     * @param x The x-coordinate of the click.
     * @param y The y-coordinate of the click.
     */
    void onBoardClicked(int x, int y);

    /**
     * @brief Handle a release event on the chessboard.
     * @param x The x-coordinate of the release.
     * @param y The y-coordinate of the release.
     */
    void onBoardReleased(int x, int y);

    /**
     * @brief Make a move in the game.
     * @param newMove The move to be made.
     */
    void makeAMove(Move newMove);
};
