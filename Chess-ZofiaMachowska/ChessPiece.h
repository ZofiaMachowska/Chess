#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinates.h"

class ChessPiece {
public:
    Coordinates<int> position;
    std::string color;

    ChessPiece(int row, int col, std::string color);
    void setPosition(int row, int col);
    int getRow() const;
    int getCol() const;
    std::string getColor() const;
    virtual std::vector<std::pair<int, int>> possibleMoves() const = 0;
    //virtual bool isValidMove(int toRow, int toCol, ChessPiece* board[][8]);
    virtual std::string type() const = 0; 
};
