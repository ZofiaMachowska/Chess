#include <iostream>
#include "GameController.h"

GameController::GameController()
{
	player1 = new Player("White");
	player2 = new Player("Black");
}

bool GameController::getWhitePlayer() {
	return whitePlayer;
}

void GameController::switchPlayer() {
	whitePlayer = !whitePlayer;
}
