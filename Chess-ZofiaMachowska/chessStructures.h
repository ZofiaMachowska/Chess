#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>

struct Move {
	sf::Vector2i start; // Wspó³rzêdne pola, z którego ruszamy pionkiem
	sf::Vector2i destination; // Wspó³rzêdne pola, na które przemieszczamy pionka
	int pieceType; // Rodzaj figury (1 - Pionek, 2 - Wie¿a, 3 - Skoczek, 4 - Goniec, 5 - Hetman, 6 - Król)
};

struct MoveEvaluation {
	Move move; // Ruch
	int evaluation; // Wartoœæ oceny pozycji dla tego ruchu
};

struct Options {
	bool firstPlayerAi;
	bool secondPlayerAi;
};