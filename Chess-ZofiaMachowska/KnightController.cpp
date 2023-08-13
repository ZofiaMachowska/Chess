#include "KnightController.h"

bool KnightController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}
	int dx = std::abs(newPos.x - oldPos.x);
	int dy = std::abs(newPos.y - oldPos.y);

	if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
		int targetPiece = board[newPos.y][newPos.x];
		if ((isWhite && targetPiece >= 0) || (!isWhite && targetPiece <= 0)) {
			return true;
		}
	}
	return false;
}

bool KnightController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
	return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
}

std::vector<Move> KnightController::generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;
	int x = pos.x;
	int y = pos.y;

	int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	for (int i = 0; i < 8; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (isOnBoard(newX, newY)) {
			int piece = board[newY][newX];

			if (piece == 0 || (piece > 0 && board[y][x] < 0) || (piece < 0 && board[y][x] > 0)) {
				validMoves.push_back(Move{ pos, sf::Vector2i(newX, newY), isWhite ? WHITE_KNIGHT : BLACK_KNIGHT });
			}
		}
	}
	return validMoves;
}
