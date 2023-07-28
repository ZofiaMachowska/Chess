#include "KingController.h"


bool KingController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}

	int dx = std::abs(newPos.x - oldPos.x);
	int dy = std::abs(newPos.y - oldPos.y);
	int targetPiece = board[newPos.y][newPos.x];

	// Sprawdzamy, czy ruch jest mo¿liwy dla króla
	if (dx <= 1 && dy <= 1 && (targetPiece >= 0 && isWhite || targetPiece <= 0 && !isWhite)) {
		// Ruch o jedno pole w dowolnym kierunku
		return true;
	}

	// W przeciwnym przypadku ruch nie jest mo¿liwy
	return false;
}

bool KingController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
	return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
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

std::vector<Move> KingController::generateValidMoves(sf::Vector2i position, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;

	// Wszystkie mo¿liwe przesuniêcia króla wokó³ swojej pozycji (³¹cznie z przek¹tnymi)
	std::vector<sf::Vector2i> moves = {
		sf::Vector2i(1, 0), // W prawo
		sf::Vector2i(-1, 0), // W lewo
		sf::Vector2i(0, 1), // W dó³
		sf::Vector2i(0, -1), // W górê
		sf::Vector2i(1, 1), // W dó³-prawo
		sf::Vector2i(1, -1), // W dó³-lewo
		sf::Vector2i(-1, 1), // W górê-prawo
		sf::Vector2i(-1, -1) // W górê-lewo
	};

	// Dla ka¿dego mo¿liwego przesuniêcia
	for (const auto& move : moves) {
		sf::Vector2i newPos = position + move;

		// SprawdŸ czy nowa pozycja jest na planszy
		if (isOnBoard(newPos.x, newPos.y)) {
			// Je¿eli pole jest puste lub zajête przez przeciwnika, dodaj ruch do listy mo¿liwych ruchów
			if (board[newPos.y][newPos.x] == 0 || board[newPos.y][newPos.x] * board[position.y][position.x] < 0) {
				validMoves.push_back({ position, newPos, 0 });
			}
		}
	}

	return validMoves;
}
