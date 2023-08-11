#include "Player.h"

Player::Player(const std::string& color, const bool isActive, const bool isAI) : color(color), isActive(isActive), isAI(isAI) {
    this->color = color;
    this->isAI = isAI;
    this->timer = new Timer();
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

void Player::loadPlayerOptions(Player* playerOption) {
    isAI = playerOption->isAI;
    timer->remaining_time = playerOption->timer->remaining_time;
    isActive = playerOption->isActive;
    isActive ? timer->resume() : timer->stop();
}

void Player::setActiveState(bool isActive) {
    this->isActive = isActive;
    isActive ? timer->resume() : timer->stop();
}