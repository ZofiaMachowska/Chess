#include "RookController.h"


bool RookController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y)) {
		return false;
	}

	// Sprawdzamy, czy nowa pozycja jest na tej samej linii (wierszu lub kolumnie) co stara pozycja
	if (oldPos.x != newPos.x && oldPos.y != newPos.y) {
		return false;
	}

	// Sprawdzamy, czy na drodze do nowej pozycji nie ma innych pionków
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

	int targetPiece = board[newPos.y][newPos.x];
	if (targetPiece < 0 && isWhite || targetPiece > 0 && !isWhite) {
		return false;
	}

	// Je¿eli nie znaleziono przeszkód, ruch jest mo¿liwy
	return true;
}

bool RookController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
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

std::vector<Move> RookController::generateValidMoves(sf::Vector2i position, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;

	// Wszystkie mo¿liwe kierunki, w których mo¿e poruszaæ siê wie¿a (góra, dó³, lewo, prawo)
	std::vector<sf::Vector2i> directions = {
		sf::Vector2i(0, 1), // W prawo
		sf::Vector2i(0, -1), // W lewo
		sf::Vector2i(1, 0), // W dó³
		sf::Vector2i(-1, 0) // W górê
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
