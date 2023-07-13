#pragma once
#define GAMECONTROLLER_H
#include "Player.h"

class GameController {
public:
	Player* player1;
	Player* player2;
	GameController();
	void switchPlayer();
	bool getWhitePlayer();

private:
	bool whitePlayer = true;
};