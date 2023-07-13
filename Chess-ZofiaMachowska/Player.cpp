#include "Player.h"

Player::Player(const std::string& kolor) : color(color) {}

std::string Player::getColor() const {
    return color;
}

int Player::getTime() const {
    return timer->isRunning() ? std::chrono::duration_cast<std::chrono::seconds>(timer->remaining_time).count() : 0;
}