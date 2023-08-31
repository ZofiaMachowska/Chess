#include "Player.h"

Player::Player(std::string color, bool playerAI) : color(color), firstMove(true), playerAI(playerAI) {
    this->playerTimer = new Timer();
}

std::string Player::getColor() const {
    return color;
}

bool Player::getIsPlayerAI() const {
    return playerAI;
}

Timer* Player::getTimer() {
    return playerTimer;
}

void Player::setTimer(Timer* timer) {
    playerTimer = timer;
}

bool Player::isFirstMove() {
    return firstMove;
}

void Player::setFirstMove(bool move1) {
    firstMove = move1;
}

void Player::startNewTimer() {
    playerTimer->reset();
    playerTimer->start();
}

void Player::stopTimer() {
    playerTimer->stop();
}

void Player::resumeTimer() {
    playerTimer->resume();
}

std::vector<Move> Player::generatePossibleMoves(Board& board) {
    std::vector<Move> possibleMoves;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            ChessPiece* piece = board.getPiece(row, col);
            if (piece && piece->getColor() == color) {
                std::vector<std::pair<int, int>> moveCoordinates = piece->possibleMoves();
                // Convert coordinates to Move objects
                for (const auto& coords : moveCoordinates) {
                    Move move(row, col, coords.first, coords.second);
                    possibleMoves.push_back(move);
                }
            }
        }
    }
    return possibleMoves;
}
