#include "AI.h"

AI::AI(const std::string& playerColor) : color(playerColor), moveValidator() {}

Move AI::makeMove(ChessPiece* board[][8], Player* currentPlayer) {
    std::vector<Move> possibleMoves = currentPlayer->generatePossibleMoves(board);
    if (possibleMoves.empty()) {
        return Move(-1,-1,-1,-1);
    }
    std::vector<Move> validMoves;
    for (const auto& move : possibleMoves) {
        if (moveValidator.isValidMove(board, move, currentPlayer->getColor())) {
            validMoves.push_back(move);
        }
    }

    if (validMoves.empty()) {
        return Move(-1, -1, -1, -1);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, validMoves.size()-1);
    int randomIndex = distr(gen);
    Move selectedMove = validMoves[randomIndex];
    
    return selectedMove;
}