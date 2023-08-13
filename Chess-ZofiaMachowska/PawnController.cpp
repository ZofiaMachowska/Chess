#include "PawnController.h"


bool PawnController::isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[][8], bool isWhite) const {
	if (!isOnBoard(oldPos.x, oldPos.y) || !isOnBoard(newPos.x, newPos.y) || newPos == oldPos) {
		return false;
	}

	int dx = newPos.x - oldPos.x;
	int dy = newPos.y - oldPos.y;
	int targetPiece = board[newPos.y][newPos.x];
	if (isWhite) {
		if (dy == -1 && std::abs(dx) == 1 && targetPiece > 0) {
			return true;
		}
		if (dy == -1 && dx == 0 && targetPiece == 0) {
			return true;
		}
		if (dy == -2 && dx == 0 && oldPos.y == 6 && targetPiece == 0 && board[newPos.y + 1][newPos.x] == 0) {
			return true;
		}
	}
	else {
		if (dy == 1 && std::abs(dx) == 1 && targetPiece < 0) {
			return true;
		}
		if (dy == 1 && dx == 0 && targetPiece == 0) {
			return true;
		}
		if (dy == 2 && dx == 0 && oldPos.y == 1 && targetPiece == 0 && board[newPos.y - 1][newPos.x] == 0) {
			return true;
		}
	}
	return false;
}

bool PawnController::checkKingCapture(sf::Vector2i figurePos, sf::Vector2i kingPos, int board[8][8], bool whitePlayerTurn) const {
	int kingPiece = board[kingPos.y][kingPos.x];
	int figurePiece = board[figurePos.y][figurePos.x];
	return (kingPiece < 0 && figurePiece < 0 || kingPiece > 0 && figurePiece > 0) ? false : isMovePossible(figurePos, kingPos, board, !whitePlayerTurn);
}

std::vector<Move> PawnController::generateValidMoves(sf::Vector2i position, int board[][8], bool isWhitePlayer) const {
	std::vector<Move> validMoves;
	int x = position.x;
	int y = position.y;

	int direction = isWhitePlayer ? -1 : 1;

	if (isOnBoard(x, y + direction) && board[y + direction][x] == 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x, y + direction), isWhitePlayer ? WHITE_PAWN : BLACK_PAWN });

		if ((isWhitePlayer && y == 6) || (!isWhitePlayer && y == 1)) {
			if (board[y + 2 * direction][x] == 0) {
				validMoves.push_back(Move{ position, sf::Vector2i(x, y + 2 * direction), isWhitePlayer? WHITE_PAWN : BLACK_PAWN });
			}
		}
	}
	if (isOnBoard(x + 1, y + direction) && board[y + direction][x + 1] * direction < 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x + 1, y + direction), isWhitePlayer ? WHITE_PAWN : BLACK_PAWN });
	}
	if (isOnBoard(x - 1, y + direction) && board[y + direction][x - 1] * direction < 0) {
		validMoves.push_back(Move{ position, sf::Vector2i(x - 1, y + direction), isWhitePlayer ? WHITE_PAWN : BLACK_PAWN });
	}
	return validMoves;
}
