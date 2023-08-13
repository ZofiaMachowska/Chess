#pragma once
#include "Timer.h"

class Player {
public:
    Player(const std::string& kolor, const bool isActive, const bool isAI);
    ~Player();
    void setActiveState(bool isActive);
    void setAiStatus(bool aiActive);
    void loadPlayerOptions(Player* playerOption);
    bool checkIsActive();
    bool isPlayerAI();
    std::string getColor() const;
    Timer* timer;

private:
    std::string color;
    bool isActive;
    bool isAI;
};
