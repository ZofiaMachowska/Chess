#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "ChessPiece.h"
#include "MoveValidator.h"
#include "Move.h"

class Board {
private:
    ChessPiece* board[8][8];
    ChessPiece* temporaryTestingBoard[8][8];
public:
    Board();
    ~Board();

    void initialize();
    ChessPiece* getPiece(int row, int col) const;
    void setPiece(int row, int col, ChessPiece* piece);
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
    void printBoard() const;
    ChessPiece* getPieceAt(int row, int col);
    void prepareTemporaryBoard();
    ChessPiece*(&getBoard())[8][8];
    ChessPiece* (&getTemporaryBoard())[8][8];
    bool isMovePossible(Move move, std::string currentPlayer);
};
