#include "BishopController.h"

bool BishopController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}

	int dx = newPos.x - oldPos.x;
	int dy = newPos.y - oldPos.y;

	if (std::abs(dx) != std::abs(dy)) {
		return false;
	}

	int stepX = (dx > 0) ? 1 : -1;
	int stepY = (dy > 0) ? 1 : -1;

	int x = oldPos.x + stepX;
	int y = oldPos.y + stepY;

	while (x != newPos.x && y != newPos.y) {
		if (board[y][x] != 0) {
			return false;
		}
		x += stepX;
		y += stepY;
	}

	int targetPiece = board[newPos.y][newPos.x];
	if ((isWhite && targetPiece >= 0) || (!isWhite && targetPiece <= 0)) {
		return true;
	}

	return false;
}

bool BishopController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
    return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
}

std::vector<Move>  BishopController::generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;
	int x = pos.x;
	int y = pos.y;

	int dx[] = { 1, 1, -1, -1 };
	int dy[] = { 1, -1, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		while (isOnBoard(newX, newY)) {
			int piece = board[newY][newX];

			if (piece == 0 || (piece > 0 && board[y][x] < 0) || (piece < 0 && board[y][x] > 0)) {
				validMoves.push_back(Move{ pos, sf::Vector2i(newX, newY), isWhite ? WHITE_BISHOP : BLACK_BISHOP });
			}

			if (piece != 0) {
				break;
			}

			newX += dx[i];
			newY += dy[i];
		}
	}
	return validMoves;
}
