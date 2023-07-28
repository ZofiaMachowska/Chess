#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <SFML/Graphics.hpp>

struct Move {
	sf::Vector2i start; // Wsp�rz�dne pola, z kt�rego ruszamy pionkiem
	sf::Vector2i destination; // Wsp�rz�dne pola, na kt�re przemieszczamy pionka
	int pieceType; // Rodzaj figury (1 - Pionek, 2 - Wie�a, 3 - Skoczek, 4 - Goniec, 5 - Hetman, 6 - Kr�l)
};

struct MoveEvaluation {
	Move move; // Ruch
	int evaluation; // Warto�� oceny pozycji dla tego ruchu
};

struct Options {
	bool firstPlayerAi;
	bool secondPlayerAi;
};