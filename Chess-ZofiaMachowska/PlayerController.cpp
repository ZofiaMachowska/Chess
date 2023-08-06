#include <iostream>
#include "PlayerController.h"
#include "BoardController.h"
#include <thread>
PlayerController::PlayerController(): aiController()
{
	player1 = new Player("White", true, false);
	player2 = new Player("Black", false, false);
}

void PlayerController::setPlayersAiFromOptions(Options aiOptions) {
	player1->setAiStatus(aiOptions.firstPlayerAi);
	player2->setAiStatus(aiOptions.secondPlayerAi);
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

std::vector<Player*> PlayerController::getPlayers() {
	std::vector<Player*> players = { player1, player2 };
	return players;
}

void PlayerController::shouldRunAI(int board[][8]) {
	if (isActivePlayerAI()) {
		//ai_thread = std::thread([this, &board]() {
			aiController.calculateBestMove(board, isFirstPlayerTurn());
		//});
	}
}

void PlayerController::switchPlayer(int board[][8]) {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
	shouldRunAI(board);
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
