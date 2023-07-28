#pragma once
#define PLAYERCONTROLLER_H
#include "Player.h"
#include "AIController.h"
#include "chessStructures.h"

class PlayerController {
public:
	PlayerController();
	void setPlayersAiFromOptions(Options aiOptions);
	bool isFirstPlayerTurn();
	bool isActivePlayerAI();
	void switchPlayer(int board[][8]);
	void startTimer();
	void resetFirstPlayer();
	Player* getCurrentPlayer();
	void shouldRunAI(int board[][8]);

private:
	Player* player1;
	Player* player2;
	AIController aiController;
};