#pragma once
#define PLAYER_H

class Player {
public:
    Player(bool isWhite);

    bool getColor() const;

private:
    bool isWhite;
    int currentPlayer;
};
