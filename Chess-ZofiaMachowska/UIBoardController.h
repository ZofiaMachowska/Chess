#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Player.h"
#include "Button.h"

class UIBoardController {
public:
    UIBoardController();
    void redrawBoard(sf::RenderWindow& window, int board[][8], int movedFigure, Player* currentPlayer, bool gameOver);
    void printBoardDebug(int board[][8]);

    Button* backButton;
    Button* saveButton;

private:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;
    const int SQUARE_SIZE = 100;
    const int BOARD_LENGTH = 7;

    sf::Texture pawnWTexture, rookWTexture, knightWTexture, bishopWTexture, queenWTexture, kingWTexture;
    sf::Texture pawnBTexture, rookBTexture, knightBTexture, bishopBTexture, queenBTexture, kingBTexture;
    sf::Texture boardTexture;
    sf::Sprite pawnWSprite, rookWSprite, knightWSprite, bishopWSprite, queenWSprite, kingWSprite;
    sf::Sprite pawnBSprite, rookBSprite, knightBSprite, bishopBSprite, queenBSprite, kingBSprite;
    sf::Sprite boardSprite;
    sf::Font font;
    sf::Text title, timerInformation;

    void setFiguresVisuals();
    void drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i);
    void redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, int movedFigure);
    void redrawInfoPannel(sf::RenderWindow& window, Player* currentPlayer, bool isGameOver);
    void calculateTimer(std::pair<int, int> time);

    sf::Sprite getMovedFigureSprite(int movedFigure);
};
