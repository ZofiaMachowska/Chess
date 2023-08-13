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

class AIController {
public:
	AIController();
	~AIController();
	void calculateBestMove(int board[][8], bool isWhitePlayer);

private:
	void makeMove(const sf::Vector2i& from, const sf::Vector2i& to);
	void unmakeMove(const sf::Vector2i& from, const sf::Vector2i& to);
	void makePlayerMove();
	int positionQuality();
	MoveEvaluation minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer);
	std::vector<Move> generatePossibleMoves(bool maximizingPlayer);
	std::vector<Move> generateValidMovesForPiece(int piece, sf::Vector2i position);
	std::vector<std::pair<sf::Vector2i, sf::Vector2i>> possibleMoves;
	void setMovePieceCallback(std::function<void()> callback);

	static PawnController pawn;
	static KnightController knight;
	static BishopController bishop;
	static RookController rook;
	static QueenController queen;
	static KingController king;
	std::function<void()> movePieceCallback;
	MoveEvaluation bestMoveEvaluation;
	Move bestMove;
	const int BOARD_LENGTH = 7;
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
