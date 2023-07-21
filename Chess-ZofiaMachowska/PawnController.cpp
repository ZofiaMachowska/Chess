#include "PawnController.h"


bool PawnController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);
}

bool PawnController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	if (whitePlayerTurn && board[figurePos.y][figurePos.x] > 0) {
		return blackCapture(figurePos, kingPos, board);
	}
	else if (!whitePlayerTurn && board[figurePos.y][figurePos.x] < 0) {
		return whiteCapture(figurePos, kingPos, board);
	}
	else {
		return false;
	}
}

//czy moze byc wykonany krok dla bialego pionka
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