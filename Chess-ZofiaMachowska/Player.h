#pragma once
#include "Timer.h"
#include <iostream>

class Player {
private:
    std::string color;
    bool playerAI;
    bool firstMove;
    Timer* playerTimer;
public:
    Player() = default; 
    Player(std::string color, bool playerAI);
    std::string getColor() const;
    bool getIsPlayerAI() const;
    void setFirstMove(bool move1);
    bool isFirstMove();
    void startNewTimer();
    void stopTimer();
    void resumeTimer();
    Timer* getTimer();
    void setTimer(Timer*);

};