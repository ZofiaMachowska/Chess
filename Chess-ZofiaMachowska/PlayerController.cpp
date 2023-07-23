#include <iostream>
#include "PlayerController.h"
#include "BoardController.h"

PlayerController::PlayerController(): aiController()
{
	player1 = new Player("White", true, false);
	player2 = new Player("Black", false, false);
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

void PlayerController::shouldRunAI(int board[][8]) {
	aiController.calculateBestMove(board);
}

void PlayerController::switchPlayer(int board[][8]) {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
	if (isActivePlayerAI()) {
		shouldRunAI(board);
	}
}

void PlayerController::resetFirstPlayer() {
	player1->setActiveState(true);
	player2->setActiveState(false);
}

void PlayerController::startTimer() {
	player1->timer->stop();
	player2->timer->stop();

	player1->timer->reset();
	player2->timer->reset();

	player1->timer->start();
	player2->timer->start();
	player2->timer->stop();

	player1->timer->setTimerOverCallback([this]() {
		BoardController::setGameOver();
		});
	player2->timer->setTimerOverCallback([this]() {
		BoardController::setGameOver();
		});
}
