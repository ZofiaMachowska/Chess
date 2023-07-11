#include "RookController.h"


bool RookController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);
}

bool RookController::checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteCapture(oldPos, kingPos, board);
	return blackCapture(oldPos, kingPos, board);
}

bool RookController::whiteMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	for (int i = oldPos.x - 1; i >= 0; i--) {
		if (board[oldPos.y][i] >= 0 && (newPos.x == i && newPos.y == oldPos.y)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][oldPos.x] >= 0 && (newPos.y == i && newPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	for (int i = oldPos.x + 1; i <= BOARD_LENGTH; i++) {
		if (board[oldPos.y][i] >= 0 && (newPos.y == oldPos.y && newPos.x == i)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][oldPos.x] >= 0 && (newPos.y == i && newPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	return false;
}

bool RookController::blackMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	for (int i = oldPos.x - 1; i >= 0; i--) {
		if (board[oldPos.y][i] <= 0 && (newPos.x == i && newPos.y == oldPos.y)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][oldPos.x] <= 0 && (newPos.y == i && newPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	for (int i = oldPos.x + 1; i <= BOARD_LENGTH; i++) {
		if (board[oldPos.y][i] <= 0 && (newPos.y == oldPos.y && newPos.x == i)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][oldPos.x] <= 0 && (newPos.y == i && newPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	return false;
}

//zagrozenie krolowi
bool RookController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	for (int i = oldPos.x - 1; i >= 0; i--) {
		if (board[oldPos.y][i] >= 0 && (kingPos.x == i && kingPos.y == oldPos.y)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][oldPos.x] >= 0 && (kingPos.y == i && kingPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	for (int i = oldPos.x + 1; i <= BOARD_LENGTH; i++) {
		if (board[oldPos.y][i] >= 0 && (kingPos.y == oldPos.y && kingPos.x == i)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][oldPos.x] >= 0 && (kingPos.y == i && kingPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	return false;
}

bool RookController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	for (int i = oldPos.x - 1; i >= 0; i--) {
		if (board[oldPos.y][i] <= 0 && (kingPos.x == i && kingPos.y == oldPos.y)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][oldPos.x] <= 0 && (kingPos.y == i && kingPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	for (int i = oldPos.x + 1; i <= BOARD_LENGTH; i++) {
		if (board[oldPos.y][i] <= 0 && (kingPos.y == oldPos.y && kingPos.x == i)) {
			return true;
		}
		else if (board[oldPos.y][i] != 0) {
			break;
		}
	}
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][oldPos.x] <= 0 && (kingPos.y == i && kingPos.x == oldPos.x)) {
			return true;
		}
		else if (board[i][oldPos.x] != 0) {
			break;
		}
	}
	return false;
}