#pragma once
#define GAMECONTROLLER_H
#include "Player.h"

class GameController {
public:
	GameController();
	void switchPlayer();
	bool getWhitePlayer();

private:
	Player* player1;
	Player* player2;
};