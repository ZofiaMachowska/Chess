#pragma once
#include "Board.h"
#include "Player.h"
#include "Move.h"
#include "MoveValidator.h"
#include "AI.h"
#include <functional>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "chessStructures.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;
    ChessPiece* selectedPiece;
    sf::Vector2i pieceOldPosition;
    bool gameOver;

public:
    Game(bool player1AI, bool player2AI);
    void start();
    void loadGame(GameSaveLoad gameToLoad);
    void switchPlayer();
    bool isCheck();
    bool isGameOver();
    Player* getCurrentPlayer();
    Player get1Player();
    Player get2Player();
    ChessPiece* (&getChessBoard())[8][8];
    ChessPiece* getSelectedPiece();
    bool isCheckmate();
    void onBoardClicked(int x, int y);
    void onBoardReleased(int x, int y);
};