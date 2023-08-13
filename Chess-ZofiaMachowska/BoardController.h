#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "ChessPieceController.h"
#include "KingController.h"
#include "QueenController.h"
#include "RookController.h"
#include "BishopController.h"
#include "KnightController.h"
#include "PawnController.h"
#include "PlayerController.h"
#include "shared.h"

/**
 * @brief Responsible for controlling and managing the game board state, including pieces and players.
 *
 * The BoardController class handles the logic behind piece movements, player turns, and game end conditions. It also integrates the rules and movement logic for each specific type of chess piece.
 */
class BoardController {
public:
    /**
     * @brief Destructs the BoardController object, cleaning up any resources.
     */
    ~BoardController();

    /**
     * @brief Sets the game to its over state.
     */
    static void setGameOver();

    /**
     * @brief Updates the board state based on the AI's move.
     *
     * @param aiMovedFigure The piece type that the AI moved.
     * @param oldPos The original position of the piece.
     * @param newPos The new position to which the piece was moved.
     */
    static void aiUpdateBoardState(int aiMovedFigure, sf::Vector2i oldPos, sf::Vector2i newPos);

    /**
     * @brief Checks if the king of the specified player is in a safe position.
     *
     * @param board The current state of the chess board.
     * @param whitePlayer Indicates whether to check for the white player's king or the black player's king.
     * @return true If the king is safe, false otherwise.
     */
    static bool checkKingSafe(int board[][8], bool whitePlayer);

    /**
     * @brief Triggered when a board square is clicked.
     *
     * @param pos The position of the clicked square.
     */
    void onBoardClicked(sf::Vector2i pos);

    /**
     * @brief Triggered when a board square is released after being clicked.
     *
     * @param pos The position of the released square.
     */
    void onBoardReleased(sf::Vector2i pos);

    /**
     * @brief Starts a new game with the specified AI options.
     *
     * @param aiOptionsChoice The options regarding the AI for the new game.
     */
    void startNewGame(Options aiOptionsChoice);

    /**
     * @brief Loads a previously saved game.
     *
     * @param gameToLoad The game state to load.
     */
    void loadGame(Game gameToLoad);
    /**
        * @brief Returns the type of the piece that has been moved.
        *
        * @return int The type of the moved piece.
        */
    int getMovedFigure();

    /**
     * @brief Provides access to the current state of the game board.
     *
     * @return int(&)[8][8] A reference to the 8x8 board matrix.
     */
    int(&getBoard())[8][8];

    /**
     * @brief Indicates whether the game is over or not.
     *
     * @return bool True if the game is over, otherwise false.
     */
    bool isGameOver();

    /**
     * @brief Retrieves the current player whose turn it is.
     *
     * @return Player* Pointer to the current player.
     */
    Player* getCurrentPlayer();

    /**
     * @brief Retrieves all active players in the game.
     *
     * @return std::vector<Player*> A vector containing pointers to the players.
     */
    std::vector<Player*> getCurrentPlayers();

private:
    /**
     * @brief Temporarily moves a piece to a specified position for testing purposes.
     */
    static void moveFigureTemporarily(sf::Vector2i pos, int piece);

    /**
     * @brief Prepares a temporary board state, often for validation or testing.
     */
    static void prepareTemporaryBoard();

    /**
 * @brief Updates the board state based on a provided position.
 */
    static void updateBoardState(sf::Vector2i pos);

    /**
     * @brief Moves a chess piece to a new position on the board.
     */
    void moveThisPiece(bool whitePlayer, int pieceNumber, sf::Vector2i position);

    /**
     * @brief Handles scenarios where no valid moves are available.
     */
    void handleNoValidMoves();

    /**
     * @brief Resets the board to its initial state.
     */
    void resetBoard();

    /**
     * @brief Checks if the current state of the board results in a checkmate.
     */
    static bool checkForCheckMate();

    /**
     * @brief Determines if a move is possible for the king.
     */
    static bool isKingMovePossible(bool whitePlayerTurn);

    /**
     * @brief Checks possible moves for a specific chess piece.
     */
    static bool checkPossiblePieceMoves(int piece, std::vector<Move> possibleMoves, bool whitePlayerTurn);

    /**
     * @brief Determines if any chess figure has a possible move.
     */
    static bool isAnyFigureMovePossible(bool whitePlayerTurn);

    /**
     * @brief Checks if any move is possible for a specific chess piece from a given position.
     */
    static bool checkPieceAnyMovePossible(const sf::Vector2i& piecePosition, bool whitePlayerTurn);

    /**
     * @brief Determines if a chess piece is blocking another piece's movement.
     */
    static bool checkPieceBlocking(const sf::Vector2i& piecePosition, const sf::Vector2i& kingPosition, bool whitePlayerTurn, int board[][8]);

    /**
     * @brief Checks if a move is possible for a chess piece to a specific new position.
     */
    bool checkPieceMovePossible(const sf::Vector2i& newPosition, bool whitePlayerTurn);


    // Data members can be documented as well, for example:
    /**
     * @brief The length of the board side (as the board is a square).
     */
    static const int BOARD_LENGTH = 7;

    /**
     * @brief Represents the figure that has been moved.
     */
    static int movedFigure;

    /**
     * @brief Indicates if the game has ended.
     */
    static bool gameOver;

    /**
     * @brief Holds the position of the piece before it was moved.
     */
    static sf::Vector2i oldPosition;

    /**
     * @brief Static instance for controlling the pawn pieces' behavior on the board.
     */
    static PawnController pawn;

    /**
     * @brief Static instance for controlling the knight pieces' behavior on the board.
     */
    static KnightController knight;

    /**
     * @brief Static instance for controlling the bishop pieces' behavior on the board.
     */
    static BishopController bishop;

    /**
     * @brief Static instance for controlling the rook pieces' behavior on the board.
     */
    static RookController rook;

    /**
     * @brief Static instance for controlling the queen pieces' behavior on the board.
     */
    static QueenController queen;

    /**
     * @brief Static instance for controlling the king pieces' behavior on the board.
     */
    static KingController king;

    /**
     * @brief Static instance for controlling the players' actions and states on the board.
     */
    static PlayerController playerController;

};
