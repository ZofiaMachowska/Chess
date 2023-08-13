#pragma once
#include "Timer.h"

class Player
{
private:
    std::string color;
    bool isActive;
    bool isAI;

public:
    Player(const std::string& kolor, const bool isActive, const bool isAI);
    void setActiveState(bool isActive);
    void setAiStatus(bool aiActive);
    void loadPlayerOptions(Player* playerOption);
    bool checkIsActive();
    bool isPlayerAI();
    std::string getColor() const;
    Timer* timer;
};
