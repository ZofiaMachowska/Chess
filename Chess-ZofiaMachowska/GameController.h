#pragma once
#define GAMECONTROLLER_H
#include "Player.h"

class GameController {
public:
	GameController();
	bool isFirstPlayerTurn();
	void switchPlayer();
	Player* getCurrentPlayer();
	void startTimer();

private:
	Player* player1;
	Player* player2;
};