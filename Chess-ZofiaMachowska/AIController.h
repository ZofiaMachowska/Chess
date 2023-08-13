#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>
#include <thread>
#include <cstring>
#include "ChessPieceController.h"
#include "KingController.h"
#include "QueenController.h"
#include "RookController.h"
#include "BishopController.h"
#include "KnightController.h"
#include "PawnController.h"
#include "chessStructures.h"

/**
 * @class AIController
 * @brief Class that controls the AI for the chess game.
 *
 * This class encompasses methods and utilities to determine the best possible moves the AI can make in a chess game.
 */
class AIController {
public:
	/**
	 * @brief Default constructor for AIController.
	 */
	AIController();

	/**
	 * @brief Destructor for AIController.
	 */
	~AIController();

	/**
	 * @brief Calculates the best move for the AI in the current board state.
	 *
	 * @param board The current state of the chessboard.
	 * @param isWhitePlayer Flag indicating if the AI is playing as the white player.
	 */
	void calculateBestMove(int board[][8], bool isWhitePlayer);

private:
	/**
	 * @brief Executes a chess move.
	 *
	 * @param from The starting position.
	 * @param to The destination position.
	 */
	void makeMove(const sf::Vector2i& from, const sf::Vector2i& to);

	/**
	 * @brief Undoes a chess move.
	 *
	 * @param from The position from which the piece was moved.
	 * @param to The position to which the piece was moved.
	 */
	void unmakeMove(const sf::Vector2i& from, const sf::Vector2i& to);

	/**
	 * @brief Makes a player's move in the chess game.
	 */
	void makePlayerMove();

	/**
	 * @brief Evaluates the quality of the current position.
	 *
	 * @return An integer representing the quality of the position.
	 */
	int positionQuality();

	/**
	 * @brief Uses the alpha-beta pruning algorithm to evaluate the best move.
	 *
	 * @param depth The current depth of the search.
	 * @param alpha The alpha value for pruning.
	 * @param beta The beta value for pruning.
	 * @param maximizingPlayer Flag indicating if the current move is maximizing or minimizing.
	 * @return A MoveEvaluation representing the value of the move and its evaluation.
	 */
	MoveEvaluation alphaBetaPruning(int depth, int alpha, int beta, bool maximizingPlayer);
	/**
	 * @brief Generates possible moves for the AI.
	 *
	 * @param maximizingPlayer Flag indicating if the current move is maximizing or minimizing.
	 * @return A vector of possible moves.
	 */
	std::vector<Move> generatePossibleMoves(bool maximizingPlayer);

	/**
	 * @brief Generates valid moves for a specific chess piece.
	 *
	 * @param piece The chess piece identifier.
	 * @param position The current position of the chess piece.
	 * @return A vector of valid moves for the piece.
	 */
	std::vector<Move> generateValidMovesForPiece(int piece, sf::Vector2i position);

	/**
	 * @brief Sets the move piece callback.
	 *
	 * @param callback A function to be called when a move is made.
	 */
	void setMovePieceCallback(std::function<void()> callback);

	// ... Attributes ...

	/**
	 * @brief Static controller for pawn moves.
	 */
	static PawnController pawn;

	/**
	 * @brief Static controller for knight moves.
	 */
	static KnightController knight;

	/**
	 * @brief Static controller for bishop moves.
	 */
	static BishopController bishop;

	/**
	 * @brief Static controller for rook moves.
	 */
	static RookController rook;

	/**
	 * @brief Static controller for queen moves.
	 */
	static QueenController queen;

	/**
	 * @brief Static controller for king moves.
	 */
	static KingController king;

	/**
	 * @brief Callback function for when a move is made.
	 */
	std::function<void()> movePieceCallback;

	/**
	 * @brief Evaluation of the best move.
	 */
	MoveEvaluation bestMoveEvaluation;

	/**
	 * @brief Represents the best move for the AI.
	 */
	Move bestMove;

	/**
	 * @brief Length of the chessboard.
	 */
	const int BOARD_LENGTH = 7;

	/**
	 * @brief Matrix representing positional values on the chessboard.
	 */
	const int POSITION_VALUES[8][8] = {
	 { 4,  3,  2,  1,  1,  2,  3,  4},
	 { 3,  2,  1,  0,  0,  1,  2,  3},
	 { 2,  1,  0, -1, -1,  0,  1,  2},
	 { 1,  0, -1, -2, -2, -1,  0,  1},
	 { 1,  0, -1, -2, -2, -1,  0,  1},
	 { 2,  1,  0, -1, -1,  0,  1,  2},
	 { 3,  2,  1,  0,  0,  1,  2,  3},
	 { 4,  3,  2,  1,  1,  2,  3,  4},
	};
};
