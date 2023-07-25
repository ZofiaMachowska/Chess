#pragma once
#define UIBOARDCONTROLLER_H
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Button.h"

class UIBoardController {
public:
    UIBoardController();

    void redrawBoard(sf::RenderWindow& window, sf::Vector2i mousePos, int board[][8], int movedFigure, Player* currentPlayer, bool gameOver);

    void setFiguresVisuals();

    void printBoardDebug(int board[][8]);

    Button* backButton;
    Button* saveButton;

private:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;
    const int SQUARE_SIZE = 100;
    const int BOARD_LENGTH = 7;

    void drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i);
    sf::Sprite getMovedFigureSprite(int movedFigure);
    void redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, int movedFigure);
    void redrawInfoPannel(sf::RenderWindow& window, Player* currentPlayer, bool isGameOver);
    void calculateTimer(std::pair<int, int> time);

    sf::Texture pawnWTexture, rookWTexture, knightWTexture, bishopWTexture, queenWTexture, kingWTexture;
    sf::Texture pawnBTexture, rookBTexture, knightBTexture, bishopBTexture, queenBTexture, kingBTexture;
    sf::Texture boardTexture;

    sf::Sprite pawnWSprite, rookWSprite, knightWSprite, bishopWSprite, queenWSprite, kingWSprite;
    sf::Sprite pawnBSprite, rookBSprite, knightBSprite, bishopBSprite, queenBSprite, kingBSprite;
    sf::Sprite boardSprite;

    sf::Font font;
    sf::Text title, timerInformation;
};
