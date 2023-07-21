#include "KingController.h"


bool KingController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (isWhite) return whiteMove(oldPos, newPos, board);
	return blackMove(oldPos, newPos, board);
}

bool KingController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
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

bool KingController::whiteMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	if (oldPos.x - 1 >= 0 && oldPos.y - 1 >= 0 && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && newPos.x == oldPos.x && newPos.y == oldPos.y - 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 1 < 8 && newPos.x == oldPos.x + 1 && newPos.y == oldPos.y - 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.x + 1 < 8 && newPos.y == oldPos.y && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.x + 1 < 8 && oldPos.y + 1 < 8 && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 < 8 && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && oldPos.y + 1 < 8 && newPos.x == oldPos.x - 1 && newPos.y == oldPos.y + 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && newPos.y == oldPos.y && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] >= 0) {
		return true;
	}
	return false;
}


bool KingController::blackMove(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8]) const {
	if (oldPos.x - 1 >= 0 && oldPos.y - 1 >= 0 && newPos.y == oldPos.y - 1 && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && newPos.x == oldPos.x && newPos.y == oldPos.y - 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 1 < BOARD_LENGTH && newPos.x == oldPos.x + 1 && newPos.y == oldPos.y - 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.x + 1 < BOARD_LENGTH && newPos.y == oldPos.y && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.x + 1 < BOARD_LENGTH && oldPos.y + 1 < BOARD_LENGTH && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 < BOARD_LENGTH && newPos.y == oldPos.y + 1 && newPos.x == oldPos.x && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && oldPos.y + 1 < BOARD_LENGTH && newPos.x == oldPos.x - 1 && newPos.y == oldPos.y + 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && newPos.y == oldPos.y && newPos.x == oldPos.x - 1 && board[newPos.y][newPos.x] <= 0) {
		return true;
	}
	return false;
}


bool KingController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (oldPos.x - 1 >= 0 && oldPos.y - 1 >= 0 && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && kingPos.y == oldPos.x && kingPos.y == oldPos.y - 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 1 < BOARD_LENGTH && kingPos.x == oldPos.x + 1 && kingPos.y == oldPos.y - 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.x + 1 <= BOARD_LENGTH && oldPos.y + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && oldPos.y + 1 <= BOARD_LENGTH && kingPos.x == oldPos.x + 1 && kingPos.y == oldPos.y + 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && kingPos.y == oldPos.y && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] <= 0) {
		return true;
	}
	return false;

}

bool KingController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
	if (oldPos.x - 1 >= 0 && oldPos.y - 1 >= 0 && kingPos.y == oldPos.y - 1 && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && kingPos.y == oldPos.x && kingPos.y == oldPos.y - 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y - 1 >= 0 && oldPos.x + 1 < BOARD_LENGTH && kingPos.x == oldPos.x + 1 && kingPos.y == oldPos.y - 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.x + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.x + 1 <= BOARD_LENGTH && oldPos.y + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.y + 1 <= BOARD_LENGTH && kingPos.y == oldPos.y + 1 && kingPos.x == oldPos.x && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && oldPos.y + 1 <= BOARD_LENGTH && kingPos.x == oldPos.x + 1 && kingPos.y == oldPos.y + 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	if (oldPos.x - 1 >= 0 && kingPos.y == oldPos.y && kingPos.x == oldPos.x - 1 && board[kingPos.y][kingPos.x] >= 0) {
		return true;
	}
	return false;

}

sf::Vector2i KingController::findKingPosition(int board[8][8], bool whitePlayerTurn) const {
	return whitePlayerTurn ? findWhiteKingPosition(board) : findBlackKingPosition(board);
}

sf::Vector2i KingController::findWhiteKingPosition(int board[8][8]) const {
	for (int i = 0; i <= BOARD_LENGTH; i++) {
		for (int j = 0; j <= BOARD_LENGTH; j++) {
			if (board[i][j] == -6) {
				return sf::Vector2i(j, i);
			}
		}
	}
}

sf::Vector2i KingController::findBlackKingPosition(int board[8][8]) const {
	for (int i = 0; i <= BOARD_LENGTH; i++) {
		for (int j = 0; j <= BOARD_LENGTH; j++) {
			if (board[i][j] == 6) {
				return sf::Vector2i(j, i);
			}
		}
	}
}