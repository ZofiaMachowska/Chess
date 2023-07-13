#pragma once
#define PLAYER_H
#include "Timer.h"

class Player
{
private:
    std::string color;
    Timer* timer;

public:
    Player(const std::string& kolor);

    std::string getColor() const;

    int getTime() const;

};
