#include "ChessUIController.h"
#include <iostream>

int ChessUIController::getWindowWidth() const {
    return WINDOW_WIDTH;
}

int ChessUIController::getWindowHeight() const {
    return WINDOW_HEIGHT;
}

int ChessUIController::getSquareSize() const{
    return SQUARE_SIZE;
}

void ChessUIController::drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i) {
    piece.setPosition(j * SQUARE_SIZE, i * SQUARE_SIZE);
    window.draw(piece);
}

void ChessUIController::setTexturesOfFigures() {
    pawnWTexture.loadFromFile("images/pionekW.png");
    rookWTexture.loadFromFile("images/wiezaW.png");
    knightWTexture.loadFromFile("images/konikW.png");
    bishopWTexture.loadFromFile("images/lauferW.png");
    queenWTexture.loadFromFile("images/krolowaW.png");
    kingWTexture.loadFromFile("images/krolW.png");
    pawnBTexture.loadFromFile("images/pionekB.png");
    rookBTexture.loadFromFile("images/wiezaB.png");
    knightBTexture.loadFromFile("images/konikB.png");
    bishopBTexture.loadFromFile("images/lauferB.png");
    queenBTexture.loadFromFile("images/krolowaB.png");
    kingBTexture.loadFromFile("images/krolB.png");
    boardTexture.loadFromFile("images/Board.png");

    pawnWSprite.setTexture(pawnWTexture);
    rookWSprite.setTexture(rookWTexture);
    knightWSprite.setTexture(knightWTexture);
    bishopWSprite.setTexture(bishopWTexture);
    queenWSprite.setTexture(queenWTexture);
    kingWSprite.setTexture(kingWTexture);

    pawnBSprite.setTexture(pawnBTexture);
    rookBSprite.setTexture(rookBTexture);
    knightBSprite.setTexture(knightBTexture);
    bishopBSprite.setTexture(bishopBTexture);
    queenBSprite.setTexture(queenBTexture);
    kingBSprite.setTexture(kingBTexture);

    boardSprite.setTexture(boardTexture);

    font.loadFromFile("arial.ttf");
    title.setFont(font);
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setPosition(840, 10);

    timerInformation.setFont(font);
    timerInformation.setCharacterSize(40);
    timerInformation.setFillColor(sf::Color::White);
    timerInformation.setPosition(840, 100);
}

void ChessUIController::printBoardDebug(int board[][8]) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

sf::Sprite ChessUIController::getMovedFigureSprite(int movedFigure) {
    switch (movedFigure) {
    case -1:
        return pawnWSprite;
    case -2:
        return rookWSprite;
    case -3:
        return knightWSprite;
    case -4:
        return bishopWSprite;
    case -5:
        return queenWSprite;
    case -6:
        return kingWSprite;
    case 1:
        return pawnBSprite;
    case 2:
        return rookBSprite;
    case 3:
        return knightBSprite;
    case 4:
        return bishopBSprite;
    case 5:
        return queenBSprite;
    case 6:
        return kingBSprite;
    default:
        break;
    }
}

void ChessUIController::redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, int movedFigure) {
    if (movedFigure == 0) return;
    sf::Sprite movedSprite = getMovedFigureSprite(movedFigure);
    movedSprite.setPosition(mousePos.x - 50, mousePos.y -50);
    window.draw(movedSprite);
}

void ChessUIController::setTurnInfoText(sf::RenderWindow& window, Player* currentPlayer) {
    title.setString(currentPlayer->getColor() + " Player Turn");
    timerInformation.setString("Remaining Time: ");
    window.draw(timerInformation);
    window.draw(title);
}

//dziêki & mamy dostêp nie do kopii, a do prawdziwego obiektu
void ChessUIController::redrawBoard(sf::RenderWindow& window, sf::Vector2i mousePos, int board[][8], int movedFigure, Player* currentPlayer) {
    window.draw(boardSprite);
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {

            if (board[i][j] == 0) continue;
            switch (board[i][j]) {
            case -1:
                drawPiece(window, pawnWSprite, j, i);
                break;
            case -2:
                drawPiece(window, rookWSprite, j, i);
                break;
            case -3:
                drawPiece(window, knightWSprite, j, i);
                break;
            case -4:
                drawPiece(window, bishopWSprite, j, i);
                break;
            case -5:
                drawPiece(window, queenWSprite, j, i);
                break;
            case -6:
                drawPiece(window, kingWSprite, j, i);
                break;
            case 1:
                drawPiece(window, pawnBSprite, j, i);
                break;
            case 2:
                drawPiece(window, rookBSprite, j, i);
                break;
            case 3:
                drawPiece(window, knightBSprite, j, i);
                break;
            case 4:
                drawPiece(window, bishopBSprite, j, i);
                break;
            case 5:
                drawPiece(window, queenBSprite, j, i);
                break;
            case 6:
                drawPiece(window, kingBSprite, j, i);
                break;
            default:
                break;
            }
        }
    }

    //rysowanie wlasnie poruszanej przez gracza figury
    redrawChessMove(window, mousePos, movedFigure);
    setTurnInfoText(window, currentPlayer);
}