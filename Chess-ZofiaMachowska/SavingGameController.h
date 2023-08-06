#pragma once
#include <fstream>
#include <iostream>
#include <json\json.h>
#include "chessStructures.h"
#include "Player.h"

class SavingGameController
{
public:
	Json::Value playerToJson(Player* player) const;
	void saveGameToFile(int board[][8], std::vector<Player*> game, const std::string& fileName);
};

