#include <iostream>
#include "GameController.h"

GameController::GameController()
{
	player1 = new Player("White", true);
	player2 = new Player("Black", false);
}

bool GameController::getWhitePlayer() {
	return player1->checkIsActive();
}

void GameController::switchPlayer() {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
}
