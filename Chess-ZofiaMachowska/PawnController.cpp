#include "PawnController.h"


bool PawnController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);
}

bool PawnController::checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteCapture(oldPos, kingPos, board);
	return blackCapture(oldPos, kingPos, board);
}

//czy moze byc wykonany krok
bool PawnController::whiteMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8]) const {
	if (oldPos.y == 6) {
		if ((newPos.y == oldPos.y - 1 && newPos.x == oldPos.x && board[oldPos.y - 1][oldPos.x] == 0) ||
			(newPos.y == oldPos.y - 2 && newPos.x == oldPos.x && board[oldPos.y - 1][oldPos.x] == 0 && board[oldPos.y - 2][oldPos.x] == 0)) {
			return true;
		}
	} 
	else if (newPos.y == oldPos.y - 1 && newPos.x == oldPos.x && board[oldPos.y - 1][oldPos.x] == 0) {
		return true;
	}

	if (board[oldPos.y - 1][oldPos.x - 1] > 0) {
		if (newPos.y == oldPos.y - 1 && newPos.x == oldPos.x - 1) {
			return true;
		}
	}
	if (board[oldPos.y - 1][oldPos.x + 1] > 0) {
		if (newPos.y == oldPos.y - 1 && newPos.x == oldPos.x + 1) {
			return true;
		}
	}
	return false;
}

bool PawnController::blackMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	if (oldPos.y == 1) {
		if ((newPos.y == oldPos.y + 1 && newPos.x == oldPos.x && board[oldPos.y + 1][oldPos.x] == 0) ||
			(newPos.y == oldPos.y + 2 && newPos.x == oldPos.x && board[oldPos.y + 1][oldPos.x] == 0 && board[oldPos.y + 2][oldPos.x] == 0)) {
			return true;
		}
	}
	else if (newPos.y == oldPos.y + 1 && newPos.x == oldPos.x && board[oldPos.y + 1][oldPos.x] == 0) {
		return true;
	}

	if (board[oldPos.y + 1][oldPos.x - 1] < 0) {
		if (newPos.y == oldPos.y + 1 && newPos.x == oldPos.x - 1) {
			return true;
		}
	}
	if (board[oldPos.y + 1][oldPos.x + 1] < 0) {
		if (newPos.y == oldPos.y + 1 && newPos.x == oldPos.x + 1) {
			return true;
		}
	}
	return false;
}

bool PawnController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (board[oldPos.y - 1][oldPos.x - 1] >= 0) {
		if (oldPos.y - 1 == kingPos.y && oldPos.x - 1 == kingPos.x) {
			return true;
		}
	}
	if (board[oldPos.y - 1][oldPos.x + 1] >= 0) {
		if (oldPos.y - 1 == kingPos.y && oldPos.x + 1 == kingPos.x) {
			return true;
		}
	}
	return false;

}

//Ta funkcja sprawdza, czy pionek o kolorze czarnym mo¿e zbiæ króla przeciwnika 
bool PawnController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (board[oldPos.y + 1][oldPos.x - 1] <= 0) {
		if (kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x - 1) {
			return true;
		}
	}
	if (board[oldPos.y + 1][oldPos.x + 1] <= 0) {
		if (kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x + 1) {
			return true;
		}
	}
	return false;
}