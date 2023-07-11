#pragma once
#define CHESSUICONTROLLER_H

#include <SFML/Graphics.hpp>

class ChessUIController {
public:

    void redrawBoard(sf::RenderWindow& window, sf::Vector2i mousePos, int board[][8], int movedFigure, bool isWhitePlayer);

    void setTexturesOfFigures();

    int getWindowHeight() const;

    int getWindowWidth() const;

    int getSquareSize() const;

    void printBoardDebug(int board[][8]);

private:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;
    const int SQUARE_SIZE = 100;
    const int BOARD_LENGTH = 7;

    void drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i);
    sf::Sprite getMovedFigureSprite(int movedFigure);
    void redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, int movedFigure);
    void setTurnInfoText(sf::RenderWindow& window, bool whitePlayer);

    sf::Texture pawnWTexture, rookWTexture, knightWTexture, bishopWTexture, queenWTexture, kingWTexture;
    sf::Texture pawnBTexture, rookBTexture, knightBTexture, bishopBTexture, queenBTexture, kingBTexture;
    sf::Texture boardTexture;

    sf::Sprite pawnWSprite, rookWSprite, knightWSprite, bishopWSprite, queenWSprite, kingWSprite;
    sf::Sprite pawnBSprite, rookBSprite, knightBSprite, bishopBSprite, queenBSprite, kingBSprite;
    sf::Sprite boardSprite;

    sf::Font font;
    sf::Text title;
};
