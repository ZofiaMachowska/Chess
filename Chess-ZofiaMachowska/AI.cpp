#include "AI.h"

AI::AI(const std::string& playerColor) : color(playerColor), moveValidator() {}

Move AI::makeMove(Board& board, Player* currentPlayer) {
    std::vector<Move> possibleMoves = currentPlayer->generatePossibleMoves(board);
    std::cout << "POSSIBLE MOVES " << possibleMoves.size() << std::endl;
    for (const auto& move : possibleMoves) {
        std::cout << "From: (" << move.fromCol << ", " << move.fromRow << ") " << std::endl;
    }
    if (possibleMoves.empty()) {
        return Move(-1,-1,-1,-1);
    }
    std::vector<Move> validMoves;
    for (const auto& move : possibleMoves) {
        if (moveValidator.isValidMove(board.getBoard(), move, currentPlayer->getColor())) {
            validMoves.push_back(move);
        }
    }
    std::cout << "VALID MOVES " << validMoves.size() << std::endl;

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