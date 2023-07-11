#include "KnightController.h"

bool KnightController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);
}

bool KnightController::checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteCapture(oldPos, kingPos, board);
	return blackCapture(oldPos, kingPos, board);
}

bool KnightController::whiteMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	if (oldPos.y - 2 >= 0 && oldPos.x - 1 >= 0 && newPos.y == oldPos.y - 2 && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 2 >= 0 && oldPos.x + 1 <= BOARD_LENGTH && newPos.y == oldPos.y - 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 2 <= BOARD_LENGTH && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x + 2 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x + 2 <= BOARD_LENGTH && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x + 2 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x + 1 <= BOARD_LENGTH && newPos.y == oldPos.y + 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x - 1 >= 0 && newPos.y == oldPos.y + 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x - 2 >= 0 && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x - 2 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x - 2 >= 0 && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x - 2 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	return false;
}

bool KnightController::blackMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	if (oldPos.y - 2 >= 0 && oldPos.x - 1 >= 0 && newPos.y == oldPos.y - 2 && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 2 >= 0 && oldPos.x + 1 <= BOARD_LENGTH && newPos.y == oldPos.y - 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 2 <= BOARD_LENGTH && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x + 2 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x + 2 <= BOARD_LENGTH && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x + 2 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x + 1 <= BOARD_LENGTH && newPos.y == oldPos.y + 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x - 1 >= 0 && newPos.y == oldPos.y + 2 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x - 2 >= 0 && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x - 2 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x - 2 >= 0 && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x - 2 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	return false;
}


bool KnightController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (oldPos.y - 2 >= 0 && oldPos.x - 1 >= 0 && kingPos.y == oldPos.y - 2 && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 2 >= 0 && oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y - 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 2 <= BOARD_LENGTH && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x + 2 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x + 2 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x + 2 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x - 1 >= 0 && kingPos.y == oldPos.y + 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x - 2 >= 0 && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x - 2 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x - 2 >= 0 && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x - 2 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	return false;
}

bool KnightController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (oldPos.y - 2 >= 0 && oldPos.x - 1 >= 0 && kingPos.y == oldPos.y - 2 && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 2 >= 0 && oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y - 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 2 <= BOARD_LENGTH && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x + 2 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x + 2 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x + 2 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 2 <= BOARD_LENGTH && oldPos.x - 1 >= 0 && kingPos.y == oldPos.y + 2 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && oldPos.x - 2 >= 0 && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x - 2 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x - 2 >= 0 && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x - 2 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	return false;
}