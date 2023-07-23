#include "QueenController.h"

bool QueenController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	// Sprawdzamy, czy pozycje s¹ na planszy
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y)) {
		return false;
	}

	// Ruch w pionie/poziomie (tak samo jak dla wie¿y)
	if ((oldPos.x != newPos.x && oldPos.y == newPos.y) || (oldPos.x == newPos.x && oldPos.y != newPos.y)) {
		int dx = 0, dy = 0;
		if (oldPos.x != newPos.x) {
			dx = (newPos.x - oldPos.x) / std::abs(newPos.x - oldPos.x);
		}
		if (oldPos.y != newPos.y) {
			dy = (newPos.y - oldPos.y) / std::abs(newPos.y - oldPos.y);
		}

		int x = oldPos.x + dx;
		int y = oldPos.y + dy;

		while (x != newPos.x || y != newPos.y) {
			if (board[y][x] != 0) {
				return false;
			}
			x += dx;
			y += dy;
		}

		return true;
	}

	// Ruch po przek¹tnej (tak samo jak dla goñca)
	if (std::abs(newPos.x - oldPos.x) == std::abs(newPos.y - oldPos.y)) {
		int dx = (newPos.x - oldPos.x) / std::abs(newPos.x - oldPos.x);
		int dy = (newPos.y - oldPos.y) / std::abs(newPos.y - oldPos.y);

		int x = oldPos.x + dx;
		int y = oldPos.y + dy;

		while (x != newPos.x || y != newPos.y) {
			if (board[y][x] != 0) {
				return false;
			}
			x += dx;
			y += dy;
		}

		return true;
	}

	// W przeciwnym przypadku ruch nie jest mo¿liwy
	return false;
}

bool QueenController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
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

bool QueenController::whiteCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
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

bool QueenController::blackCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8]) const {
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

std::vector<Move> QueenController::generateValidMoves(sf::Vector2i position, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;

	// Wszystkie mo¿liwe kierunki, w których mo¿e poruszaæ siê hetman (góra, dó³, lewo, prawo oraz przek¹tne)
	std::vector<sf::Vector2i> directions = {
		sf::Vector2i(0, 1), // W prawo
		sf::Vector2i(0, -1), // W lewo
		sf::Vector2i(1, 0), // W dó³
		sf::Vector2i(-1, 0), // W górê
		sf::Vector2i(1, 1), // W dó³-prawo
		sf::Vector2i(1, -1), // W dó³-lewo
		sf::Vector2i(-1, 1), // W górê-prawo
		sf::Vector2i(-1, -1) // W górê-lewo
	};

	// Dla ka¿dego mo¿liwego kierunku
	for (const auto& dir : directions) {
		sf::Vector2i newPos = position + dir;

		// SprawdŸ czy nowa pozycja jest na planszy
		while (isOnBoard(newPos.x, newPos.y)) {
			// Je¿eli pole jest puste, dodaj ruch do listy mo¿liwych ruchów
			if (board[newPos.y][newPos.x] == 0) {
				validMoves.push_back({ position, newPos, 0 });
			}
			// Je¿eli pole jest zajête przez przeciwnika, dodaj ruch ataku
			else if (board[newPos.y][newPos.x] * board[position.y][position.x] < 0) {
				validMoves.push_back({ position, newPos, 0 });
				break; // Przerwij pêtlê w tym kierunku, bo dalsze ruchy s¹ zablokowane
			}
			else {
				break; // Przerwij pêtlê, bo dalsze ruchy w tym kierunku s¹ niemo¿liwe
			}

			newPos += dir; // Przesuñ siê na nastêpn¹ pozycjê w danym kierunku
		}
	}

	return validMoves;
}