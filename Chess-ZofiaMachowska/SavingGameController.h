#pragma once
#include <fstream>
#include <iostream>
#include <json\json.h>
#include "chessStructures.h"
#include "Player.h"

class SavingGameController
{
public:
	~SavingGameController();
	void addNewGameToHistory(int board[][8], std::vector<Player*> players, bool gameOver);
	void saveGameToFile();
	void loadGamesFromFile();
	void setSaveNewGameCallback(std::function<void()> callback);
	std::vector<Game> getGames();
	std::vector<Game> games;
	std::function<void()> savedNewGameCallback;

private:
	Player* createPlayerFromJson(const Json::Value& jsonPlayer);
	Timer* createTimerFromJson(const Json::Value& jsonTimer);
	Json::Value playerToJson(Player* player) const;
	Json::Value timerToJson(Timer* time) const;

	const int MAX_GAME_HISTORY = 6;
	const std::string FILE_NAME = "stan_gry.json";
};

