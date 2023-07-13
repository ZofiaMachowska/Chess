#include "Player.h"

Player::Player(const std::string& kolor, const bool isActive ) : color(color), isActive(isActive) {}

std::string Player::getColor() const {
    return color;
}

bool Player::checkIsActive() {
    return isActive;
}

void Player::setActiveState(bool isActive) {
    this->isActive = isActive;
}

int Player::getTime() const {
    return timer->isRunning() ? std::chrono::duration_cast<std::chrono::seconds>(timer->remaining_time).count() : 0;
}
