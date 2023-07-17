#include <iostream>
#include "GameController.h"

GameController::GameController()
{
	player1 = new Player("White", true);
	player2 = new Player("Black", false);
}

bool GameController::isFirstPlayerTurn() {
	return player1->checkIsActive();
}

Player* GameController::getCurrentPlayer() {
	return player1->checkIsActive()? player1 : player2;
}

void GameController::switchPlayer() {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
}

void GameController::startTimer() {
	player1->timer->start();
	player2->timer->start();
	player2->timer->stop();
}
