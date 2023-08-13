#include "RookController.h"

bool RookController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}
	if (oldPos.x != newPos.x && oldPos.y != newPos.y) {
		return false;
	}

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
	return true;
}

bool RookController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
	return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
}

std::vector<Move> RookController::generateValidMoves(sf::Vector2i position, int board[8][8], bool isWhite) const {
	std::vector<Move> validMoves;
	for (const auto& direction : directions) {
		sf::Vector2i newPos = position + direction;

		while (isOnBoard(newPos.x, newPos.y)) {
			if (board[newPos.y][newPos.x] == 0) {
				validMoves.push_back({ position, newPos, isWhite ? WHITE_ROOK : BLACK_ROOK });
			}
			else if (board[newPos.y][newPos.x] * board[position.y][position.x] < 0) {
				validMoves.push_back({ position, newPos, isWhite ? WHITE_ROOK : BLACK_ROOK });
				break;
			}
			else {
				break;
			}
			newPos += direction;
		}
	}
	return validMoves;
}
