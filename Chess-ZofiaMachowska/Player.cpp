#include "Player.h"

Player::Player(const std::string& color, const bool isActive, const bool isAI) : color(color), isActive(isActive), isAI(isAI) {
    this->color = color;
    this->isAI = isAI;
    this->timer = new Timer();
}

Player::~Player() {
    delete timer;
}

std::string Player::getColor() const {
    return color;
}

bool Player::checkIsActive() {
    return isActive;
}

bool Player::isPlayerAI() {
    return isAI;
}

void Player::setAiStatus(bool aiActive) {
    isAI = aiActive;
}

void Player::setActiveState(bool isActive) {
    this->isActive = isActive;
    isActive ? timer->resume() : timer->stop();
}

void Player::loadPlayerOptions(Player* playerOption) {
    isAI = playerOption->isAI;
    timer->remainingTime = playerOption->timer->remainingTime;
    isActive = playerOption->isActive;
    isActive ? timer->resume() : timer->stop();
}
