#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "Player.h"
#include <SFML/Graphics.hpp>

struct Move {
	sf::Vector2i start;
	sf::Vector2i destination; 
	int pieceType; 
};

struct MoveEvaluation {
	Move move; 
	int evaluation; 
};

struct Options {
	bool firstPlayerAi;
	bool secondPlayerAi;
};

struct Game {
	int board[8][8];
	Player* player1;
	Player* player2;
	bool gameOver;
	std::string timeOfSaving;
};