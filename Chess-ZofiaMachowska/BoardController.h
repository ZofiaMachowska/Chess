#pragma once
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "ChessPieceController.h"
#include "KingController.h"
#include "QueenController.h"
#include "RookController.h"
#include "BishopController.h"
#include "KnightController.h"
#include "PawnController.h"
#include "PlayerController.h"
#include "shared.h"
#include <vector>

class BoardController {
public:
    void onBoardClicked(sf::Vector2i pos);

	void onBoardReleased(sf::Vector2i pos);

	void resetBoard();

	void startNewGame();

	int getMovedFigure();

	static void aiUpdateBoardState(int aiMovedFigure, sf::Vector2i oldPos, sf::Vector2i newPos);

	Player* getCurrentPlayer();

	int(&getBoard())[8][8];

	static void setGameOver();

	bool isGameOver();

private:
	const int BOARD_LENGTH = 7;
	static sf::Vector2i oldPosition;
	static int movedFigure;

	static PawnController pawn;
	static KnightController knight;
	static BishopController bishop;
	static RookController rook;
	static QueenController queen;
	static KingController king;
	static PlayerController playerController;

	void moveThisPiece(bool whitePlayer, int pieceNumber, sf::Vector2i position);
	bool checkKingSafe(sf::Vector2i pos, bool whitePlayer);
	void checkPlayerMoveValidity(sf::Vector2i pos, bool kingSafe, bool movePossible);
	void handleNoValidMoves();
	static void updateBoardState(sf::Vector2i pos);
	static bool gameOver;
};
