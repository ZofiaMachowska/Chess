#include "PawnController.h"


bool PawnController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const {
	// Sprawdzamy, czy pozycje s¹ na planszy
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y)) {
		return false;
	}

	int dx = newPos.x - oldPos.x;
	int dy = newPos.y - oldPos.y;
	int targetPiece = board[newPos.y][newPos.x];
	// Sprawdzamy, czy ruch jest mo¿liwy dla pionka
	if (isWhite) {
		// Ruchy pionka bia³ego
		if (dy == -1 && std::abs(dx) == 1 && targetPiece > 0) {
			return true; // Bicie w przek¹tnej
		}
		if (dy == -1 && dx == 0 && targetPiece == 0) {
			return true; // Zwyk³y ruch do przodu o jedno pole
		}
		if (dy == -2 && dx == 0 && oldPos.y == 6 && targetPiece == 0 && board[newPos.y + 1][newPos.x] == 0) {
			return true; // Pionek wychodzi o 2 pola na starcie
		}
	}
	else {
		// Ruchy pionka czarnego
		if (dy == 1 && std::abs(dx) == 1 && targetPiece < 0) {
			return true; // Bicie w przek¹tnej
		}
		if (dy == 1 && dx == 0 && targetPiece == 0) {
			return true; // Zwyk³y ruch do przodu o jedno pole
		}
		if (dy == 2 && dx == 0 && oldPos.y == 1 && targetPiece == 0 && board[newPos.y - 1][newPos.x] == 0) {
			return true; // Pionek wychodzi o 2 pola na starcie
		}
	}

	// W przeciwnym przypadku ruch nie jest mo¿liwy
	return false;
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

std::vector<Move> PawnController::generateValidMoves(sf::Vector2i position, int board[][8], bool isWhitePlayer) const {
	
	std::vector<Move> validMoves;
	int x = position.x;
	int y = position.y;

	// Bia³e pionki poruszaj¹ siê w kierunku malej¹cych wspó³rzêdnych Y, a czarne w kierunku rosn¹cych
	int direction = isWhitePlayer ? -1 : 1;

	// Sprawdzamy czy pionek mo¿e wykonaæ zwyk³y ruch do przodu
	if (isOnBoard(x, y + direction) && board[y + direction][x] == 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x, y + direction), 1 });

		// Sprawdzamy czy pionek mo¿e wykonaæ podwójny ruch do przodu, jeœli stoi na swoim pocz¹tkowym polu
		if ((isWhitePlayer && y == 6) || (!isWhitePlayer && y == 1)) {
			if (board[y + 2 * direction][x] == 0) {
				validMoves.push_back(Move{ position, sf::Vector2i(x, y + 2 * direction), 1 });
			}
		}
	}

	// Sprawdzamy czy pionek mo¿e wykonaæ bicie w prawo
	if (isOnBoard(x + 1, y + direction) && board[y + direction][x + 1] * direction < 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x + 1, y + direction), 1 });
	}

	// Sprawdzamy czy pionek mo¿e wykonaæ bicie w lewo
	if (isOnBoard(x - 1, y + direction) && board[y + direction][x - 1] * direction < 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x - 1, y + direction), 1 });
	}
	return validMoves;
}
