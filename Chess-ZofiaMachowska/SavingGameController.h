#pragma once
#include <fstream>
#include <iostream>
#include <json\json.h>
#include "chessStructures.h"
#include "Player.h"

class SavingGameController
{
public:
	const int maxGameHistory = 6;
	void setSaveNewGameCallback(std::function<void()> callback);
	std::function<void()> savedNewGameCallback;
	const std::string fileName = "stan_gry.json";
	std::vector<Game> games;
	void addNewGameToHistory(int board[][8], std::vector<Player*> players, bool gameOver);
	Json::Value playerToJson(Player* player) const;
	Json::Value timerToJson(Timer* time) const;
	void saveGameToFile();
	void loadGamesFromFile();
	std::vector<Game> getGames();
	Player* createPlayerFromJson(const Json::Value& jsonPlayer);
	Timer* createTimerFromJson(const Json::Value& jsonTimer);
};

