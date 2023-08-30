#include "AI.h"

Move AI::generateMove(Board& board, char playerColor) {
    // Placeholder function that just picks a random legal move.
    // You'd replace this with more advanced logic.
    std::vector<Move> legalMoves; // Assume you have a function to populate this

    // Populate legalMoves... (not shown here)

    if (legalMoves.empty()) {
        // No legal moves available
        return Move(-1, -1, -1, -1); // Invalid move
    }

    int randomIndex = std::rand() % legalMoves.size();
    return legalMoves[randomIndex];
}