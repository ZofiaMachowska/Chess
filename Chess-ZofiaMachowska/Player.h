#pragma once
#define PLAYER_H
#include "Timer.h"

class Player
{
private:
    std::string color;
    bool isActive;
    bool isAI;

public:
    Player(const std::string& kolor, const bool isActive, const bool isAI);
    std::string getColor() const;
    bool checkIsActive();
    bool isPlayerAI();
    void setActiveState(bool isActive);

    Timer* timer;
};
