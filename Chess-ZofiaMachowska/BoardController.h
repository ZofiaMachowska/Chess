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

class BoardController {
public:
	static void setGameOver();
	static void aiUpdateBoardState(int aiMovedFigure, sf::Vector2i oldPos, sf::Vector2i newPos);
    void onBoardClicked(sf::Vector2i pos);
	void onBoardReleased(sf::Vector2i pos);
	void startNewGame(Options aiOptionsChoice);
	void loadGame(Game gameToLoad);

	int getMovedFigure();
	int(&getBoard())[8][8];
	bool isGameOver();

	Player* getCurrentPlayer();
	std::vector<Player*> getCurrentPlayers();

private:
	static void moveFigureTemporarily(sf::Vector2i pos, int piece);
	static void prepareTemporaryBoard();
	static void updateBoardState(sf::Vector2i pos);
	void moveThisPiece(bool whitePlayer, int pieceNumber, sf::Vector2i position);
	void handleNoValidMoves();
	void resetBoard();

	static bool checkKingSafe(int board[][8], bool whitePlayer);
	static bool checkForCheckMate();
	static bool isKingMovePossible(bool whitePlayerTurn);
	static bool checkPossiblePieceMoves(int piece, std::vector<Move> possibleMoves, bool whitePlayerTurn);
	static bool isAnyFigureMovePossible(bool whitePlayerTurn);
	static bool checkPieceAnyMovePossible(const sf::Vector2i& piecePosition, bool whitePlayerTurn);
	static bool checkPieceBlocking(const sf::Vector2i& piecePosition, const sf::Vector2i& kingPosition, bool whitePlayerTurn, int board[][8]);
	bool checkPieceMovePossible(const sf::Vector2i& newPosition, bool whitePlayerTurn);

	static const int BOARD_LENGTH = 7;
	static int movedFigure;
	static bool gameOver;
	static sf::Vector2i oldPosition;

	static PawnController pawn;
	static KnightController knight;
	static BishopController bishop;
	static RookController rook;
	static QueenController queen;
	static KingController king;
	static PlayerController playerController;
};
