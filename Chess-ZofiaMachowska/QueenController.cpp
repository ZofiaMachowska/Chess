#include "QueenController.h"

bool QueenController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	// Sprawdzamy, czy pozycje s� na planszy
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}

	int targetPiece = board[newPos.y][newPos.x];
	if (targetPiece < 0 && isWhite || targetPiece > 0 && !isWhite) {
		return false;
	}

	// Ruch w pionie/poziomie (tak samo jak dla wie�y)
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

	// Ruch po przek�tnej (tak samo jak dla go�ca)
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

	// W przeciwnym przypadku ruch nie jest mo�liwy
	return false;
}

bool QueenController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
	return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
}

std::vector<Move> QueenController::generateValidMoves(sf::Vector2i position, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;

	// Wszystkie mo�liwe kierunki, w kt�rych mo�e porusza� si� hetman (g�ra, d�, lewo, prawo oraz przek�tne)
	std::vector<sf::Vector2i> directions = {
		sf::Vector2i(0, 1), // W prawo
		sf::Vector2i(0, -1), // W lewo
		sf::Vector2i(1, 0), // W d�
		sf::Vector2i(-1, 0), // W g�r�
		sf::Vector2i(1, 1), // W d�-prawo
		sf::Vector2i(1, -1), // W d�-lewo
		sf::Vector2i(-1, 1), // W g�r�-prawo
		sf::Vector2i(-1, -1) // W g�r�-lewo
	};

	// Dla ka�dego mo�liwego kierunku
	for (const auto& dir : directions) {
		sf::Vector2i newPos = position + dir;

		// Sprawd� czy nowa pozycja jest na planszy
		while (isOnBoard(newPos.x, newPos.y)) {
			// Je�eli pole jest puste, dodaj ruch do listy mo�liwych ruch�w
			if (board[newPos.y][newPos.x] == 0) {
				validMoves.push_back({ position, newPos, isWhite ? -5 : 5 });
			}
			// Je�eli pole jest zaj�te przez przeciwnika, dodaj ruch ataku
			else if (board[newPos.y][newPos.x] * board[position.y][position.x] < 0) {
				validMoves.push_back({ position, newPos, isWhite ? -5 : 5 });
				break; // Przerwij p�tl� w tym kierunku, bo dalsze ruchy s� zablokowane
			}
			else {
				break; // Przerwij p�tl�, bo dalsze ruchy w tym kierunku s� niemo�liwe
			}

			newPos += dir; // Przesu� si� na nast�pn� pozycj� w danym kierunku
		}
	}

	return validMoves;
}