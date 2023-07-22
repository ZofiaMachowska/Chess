#include "Player.h"

Player::Player(const std::string& color, const bool isActive, const bool isAI) : color(color), isActive(isActive), isAI(isAI) {
    this->color = color;
    this->isAI = isAI;
    timer = new Timer();
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

void Player::setActiveState(bool isActive) {
    this->isActive = isActive;
    isActive ? timer->resume() : timer->stop();
}