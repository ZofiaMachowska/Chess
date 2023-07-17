#pragma once
#define PLAYER_H
#include "Timer.h"

class Player
{
private:
    std::string color;
    bool isActive;

public:
    Player(const std::string& kolor, const bool isActive);
    Timer* timer;

    std::string getColor() const;
    bool checkIsActive();
    void setActiveState(bool isActive);

};
