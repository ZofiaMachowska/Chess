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
