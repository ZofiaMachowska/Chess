#pragma once
#include <iostream>
#include <functional>
#include <vector>
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