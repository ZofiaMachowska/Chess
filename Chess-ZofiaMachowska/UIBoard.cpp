#include "UIBoard.h"

UIBoard::UIBoard() {
    setFiguresVisuals();
}

UIBoard::~UIBoard() {
    delete saveButton;
    delete backButton;
}

void UIBoard::setFiguresVisuals() {
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
    timerInformation.setCharacterSize(30);
    timerInformation.setFillColor(sf::Color::White);
    timerInformation.setPosition(840, 100);

    saveButton = new Button(sf::Vector2f(870, 600), sf::Vector2f(280, 70), font, "Save Game", 36);
    backButton = new Button(sf::Vector2f(870, 700), sf::Vector2f(280, 70), font, "Back", 36);
}

void UIBoard::drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i) {
    piece.setPosition(j * SQUARE_SIZE, i * SQUARE_SIZE);
    window.draw(piece);
}

sf::Sprite UIBoard::getWhiteFigure(ChessPiece* selectedPiece) {
    std::string type = selectedPiece->type();

    if (type == "P") {
        return pawnWSprite;
    }
    else if (type == "R") {
        return rookWSprite;
    }
    else if (type == "N") {
        return knightWSprite;
    }
    else if (type == "B") {
        return bishopWSprite;
    }
    else if (type == "Q") {
        return queenWSprite;
    }
    else if (type == "K") {
        return kingWSprite;
    }
}


sf::Sprite UIBoard::getBlackFigure(ChessPiece* selectedPiece) {
    std::string type = selectedPiece->type();

    if (type == "P") {
        return pawnBSprite;
    }
    else if (type == "R") {
        return rookBSprite;
    }
    else if (type == "N") {
        return knightBSprite;
    }
    else if (type == "B") {
        return bishopBSprite;
    }
    else if (type == "Q") {
        return queenBSprite;
    }
    else if (type == "K") {
        return kingBSprite;
    }
}

sf::Sprite UIBoard::getFigureSprite(ChessPiece* selectedPiece) {
    if (selectedPiece->getColor() == "W") {
        return getWhiteFigure(selectedPiece);
    }
    else {
        return getBlackFigure(selectedPiece);
    }
}

void UIBoard::redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, ChessPiece* selectedPiece) {
    if (selectedPiece == nullptr) return;
    sf::Sprite movedSprite = getFigureSprite(selectedPiece);
    movedSprite.setPosition(mousePos.x - 50, mousePos.y -50);
    window.draw(movedSprite);
}

void UIBoard::calculateTimer(std::pair<int, int> time) {
    std::string minutes, seconds;
    minutes = std::to_string(time.first);
    seconds = time.second == 0 ? "00" : std::to_string(time.second);
    if (time.second < 10) {
        seconds = '0' + std::to_string(time.second);
    }
    timerInformation.setString("Remaining Time: " + minutes + ':' + seconds);
}

void UIBoard::redrawInfoPannel(sf::RenderWindow& window, Player* currentPlayer, bool gameOver) {
    if (!gameOver) {
        title.setString(currentPlayer->getColor() + " Player Turn");
        calculateTimer(currentPlayer->getTimer()->getTime());
        window.draw(timerInformation);
    }
    else {
        title.setString(currentPlayer->getColor() + " Player Lost");
    }
    window.draw(title);
    saveButton->draw(window);
    backButton->draw(window);
}

void UIBoard::redrawBoard(sf::RenderWindow& window, Game& game) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    window.draw(boardSprite);
    
    ChessPiece* (&board)[8][8] = game.getChessBoard();

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            ChessPiece* piece = board[row][col];
            if (piece != nullptr) {
                sf::Sprite figureSprite = getFigureSprite(piece);
                drawPiece(window, figureSprite, col, row);
            }
        }
    }
    redrawChessMove(window, mousePos, game.getSelectedPiece());
    redrawInfoPannel(window, game.getCurrentPlayer(), game.isGameOver());
}