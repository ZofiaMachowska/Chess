#pragma once
#define PLAYERCONTROLLER_H
#include "Player.h"
#include "AIController.h"

class PlayerController {
public:
	PlayerController();
	bool isFirstPlayerTurn();
	bool isActivePlayerAI();
	void switchPlayer();
	void startTimer();
	Player* getCurrentPlayer();

private:
	Player* player1;
	Player* player2;
	AIController aiController;

	void shouldRunAI();

};