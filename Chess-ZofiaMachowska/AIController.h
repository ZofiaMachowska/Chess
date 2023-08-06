//jak jest AI to nie rejestruje eventow zadnych (oprocz game exit). 
// AIController aktywuje sie sie przy setActiveState
// //AIController co ture powinien robic tablice 2 wymiarowa z polami zagrozonymi przez gracza drugiego (true, false)
//sprawdza bezpieczenstwo krola w pierwszej kolejnosci.
//  sprawdza czy moze uciec krolem a potem sprawdza czy ew moze zaslonic krola inna figura
// funkcja ktora sprawdza czy dowolna figura jest zagrozona 
// priorytyzuje ucieczke figury o najwiekszej wartosci 
// nastpeny krok proba zbicia najwyzszej figury 
// a jezeli nic to krok do przodu dowolny losowy

#pragma once
#define AICONTROLLER_H
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ChessPieceController.h"
#include "KingController.h"
#include "QueenController.h"
#include "RookController.h"
#include "BishopController.h"
#include "KnightController.h"
#include "PawnController.h"
#include "chessStructures.h"
#include <cstring>

class AIController {
public:
	AIController();
	void calculateBestMove(int board[][8], bool isWhitePlayer);

private:
	int positionQuality(int board[][8]);
	bool checkKingSafe(int pieceType, int board[][8]);
	void make_move(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]);
	void unmake_move(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]);
	MoveEvaluation minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer, int board[][8]);
	std::vector<Move> generatePossibleMoves(int board[][8], bool maximizingPlayer);
	std::vector<Move> generateValidMovesForPiece(int piece, sf::Vector2i position, int board[][8]);
	std::vector<std::pair<sf::Vector2i, sf::Vector2i>> possibleMoves;
	void makeAMove();
	void setMovePieceCallback(std::function<void()> callback);
	std::function<void()> movePieceCallback;
	MoveEvaluation bestMoveEvaluation;
	Move bestMove;
	static PawnController pawn;
	static KnightController knight;
	static BishopController bishop;
	static RookController rook;
	static QueenController queen;
	static KingController king;

};
