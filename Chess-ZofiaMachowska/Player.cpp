#include "Player.h"

Player::Player(const std::string& color, const bool isActive ) : color(color), isActive(isActive) {
    this->color = color;
    timer = new Timer();
}

std::string Player::getColor() const {
    return color;
}

bool Player::checkIsActive() {
    return isActive;
}

void Player::setActiveState(bool isActive) {
    this->isActive = isActive;
    if (isActive) {
        timer->resume();
    }
    else {
        timer->stop();
    }
}