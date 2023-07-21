#include "BishopController.h"

bool BishopController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);

}

bool BishopController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
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

bool BishopController::whiteMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	int j = oldPos.x - 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] >= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] >= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	j = oldPos.x - 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] >= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] >= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	return false;

}

bool BishopController::blackMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	int j = oldPos.x - 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] <= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] <= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	j = oldPos.x - 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] <= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] <= 0 && (newPos.y == i && newPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	return false;
}

bool BishopController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	int j = oldPos.x - 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] >= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] >= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	j = oldPos.x - 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] >= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] >= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	return false;
}

bool BishopController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	int j = oldPos.x - 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] <= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y - 1; i >= 0; i--) {
		if (board[i][j] <= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	j = oldPos.x - 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] <= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j--;
	}
	j = oldPos.x + 1;
	for (int i = oldPos.y + 1; i <= BOARD_LENGTH; i++) {
		if (board[i][j] <= 0 && (kingPos.y == i && kingPos.x == j)) {
			return true;
		}
		else if (board[i][j] != 0) {
			break;
		}
		j++;
	}
	return false;
}