#pragma once
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "ChessPieceController.h"
#include "ChessPieceController.h"
#include "KingController.h"
#include "QueenController.h"
#include "RookController.h"
#include "BishopController.h"
#include "KnightController.h"
#include "PawnController.h"
#include "GameController.h"
#include <vector>

class BoardController {
public:

	BoardController();

    void onBoardClicked(sf::Vector2i pos);

	void onBoardReleased(sf::Vector2i pos);

	void resetBoard();

	void startNewGame();

	int getMovedFigure();

	Player* getCurrentPlayer();

	int(&getBoard())[8][8];


private:
	const int BOARD_LENGTH = 7;

	int movedFigure = 0;
	
	static PawnController pawn;
	static KnightController knight;
	static BishopController bishop;
	static RookController rook;
	static QueenController queen;
	static KingController king;
	static GameController gameController; //logiczniej moze na odwrot zeby bylo 

	sf::Vector2i oldPosition;

	void moveThisPiece(int pieceNumber, sf::Vector2i position);
	void moveBlackPiece(sf::Vector2i position);
	void moveWhitePiece(sf::Vector2i position);
	bool checkKingSafe(sf::Vector2i pos, bool whitePlayer);
	void checkPlayerMoveValidity(sf::Vector2i pos, bool kingSafe, bool movePossible);
	void updateBoardState(sf::Vector2i pos);
	void handleNoValidMoves();
};
