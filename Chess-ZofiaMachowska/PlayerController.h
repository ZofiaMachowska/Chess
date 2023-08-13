#pragma once
#include "Player.h"
#include "AIController.h"
#include "chessStructures.h"
#include <thread>
#include <chrono>
#include <random>

class PlayerController {
public:
	PlayerController();
	~PlayerController();
	void setPlayersAiFromOptions(Options aiOptions);
	void setLoadedPlayers(Game gameToLoad);
	void shouldRunAI(int board[][8]);
	void switchPlayer(int board[][8]);
	void startTimer();
	void resetFirstPlayer();
	bool isFirstPlayerTurn();
	bool isActivePlayerAI();
	Player* getCurrentPlayer();
	std::vector<Player*> getPlayers();

private:
	Player* player1;
	Player* player2;
	AIController aiController;
};