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


std::vector<Move>  BishopController::generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;
	int x = pos.x;
	int y = pos.y;

	// Tablica z ró¿nicami wspó³rzêdnych x i y, aby sprawdziæ przek¹tne
	int dx[] = { 1, 1, -1, -1 };
	int dy[] = { 1, -1, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		// Sprawdzamy przek¹tne, dopóki nie wyjdziemy poza szachownicê
		while (isOnBoard(newX, newY)) {
			int piece = board[newY][newX];

			// Jeœli na przek¹tnej znajduje siê figura przeciwnego gracza lub pole jest puste, to dodajemy ruch
			if (piece == 0 || (piece > 0 && board[y][x] < 0) || (piece < 0 && board[y][x] > 0)) {
				validMoves.push_back(Move{ pos, sf::Vector2i(newX, newY), abs(board[y][x]) });
			}

			// Jeœli na przek¹tnej znajduje siê figura, przerywamy pêtlê
			if (piece != 0) {
				break;
			}

			newX += dx[i];
			newY += dy[i];
		}
	}

	return validMoves;
}
