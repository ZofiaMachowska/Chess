#pragma once
#include "ChessPieceController.h"

class KingController : public ChessPieceController {
public:
    bool isMovePossible(sf::Vector2i oldPos, sf::Vector2i newPos, int board[8][8], bool isWhite) const override;
    bool checkKingCapture(sf::Vector2i oldPos, sf::Vector2i kingPos, int board[8][8], bool isWhite) const override;
    std::vector<Move> generateValidMoves(sf::Vector2i pos, int board[8][8], bool isWhite) const override;
    sf::Vector2i findKingPosition(int board[8][8], bool isWhite) const;

	const int BLACK_KING = 6;
	const int WHITE_KING = -6;

private:
    sf::Vector2i findWhiteKingPosition(int board[8][8]) const;
    sf::Vector2i findBlackKingPosition(int board[8][8]) const;
	std::vector<sf::Vector2i> directions = {
	sf::Vector2i(1, 0),
	sf::Vector2i(-1, 0),
	sf::Vector2i(0, 1),
	sf::Vector2i(0, -1),
	sf::Vector2i(1, 1),
	sf::Vector2i(1, -1),
	sf::Vector2i(-1, 1),
	sf::Vector2i(-1, -1)
	};
};
