#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ChessPiece {
public:
    int row;
    int col;
    std::string color; // 'W' for white, 'B' for black

    void setPosition(int row, int col);
    int getRow() const;
    int getCol() const;
    std::string getColor() const;
    virtual std::vector<std::pair<int, int>> possibleMoves() const = 0;
    virtual bool isValidMove(int toRow, int toCol, ChessPiece* board[][8]);
    virtual std::string type() const = 0; // W, N, B, R, Q, K
};
