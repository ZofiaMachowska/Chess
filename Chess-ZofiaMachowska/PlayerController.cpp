#include <iostream>
#include "PlayerController.h"

PlayerController::PlayerController(): aiController()
{
	player1 = new Player("White", true, false);
	player2 = new Player("Black", false, true);
}

bool PlayerController::isFirstPlayerTurn() {
	return player1->checkIsActive();
}

bool PlayerController::isActivePlayerAI() {
	return player1->checkIsActive() ? player1->isPlayerAI() : player2->isPlayerAI();
}

Player* PlayerController::getCurrentPlayer() {
	return player1->checkIsActive()? player1 : player2;
}

void PlayerController::shouldRunAI() {
	aiController.makeAMove();
}

void PlayerController::switchPlayer() {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
	if (isActivePlayerAI()) {
		shouldRunAI();
	}
}

void PlayerController::startTimer() {
	player1->timer->start();
	player2->timer->start();
	player2->timer->stop();
}
