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
	void calculateBestMove(int board[][8], bool isWhitePlayer);

private:
	void makeMove(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]);
	void unmakeMove(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]);
	void makePlayerMove();
	int positionQuality(int board[][8]);
	bool checkKingSafe(int pieceType, int board[][8]);
	MoveEvaluation minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer, int board[][8]);
	std::vector<Move> generatePossibleMoves(int board[][8], bool maximizingPlayer);
	std::vector<Move> generateValidMovesForPiece(int piece, sf::Vector2i position, int board[][8]);
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
};
