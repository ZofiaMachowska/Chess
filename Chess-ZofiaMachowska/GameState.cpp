#include "GameState.h"

GameState::GameState() : board(), uiController(), event() {
}

void GameState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i boardPosition(mousePos.x / 100, mousePos.y / 100);

    if (event.type == sf::Event::Closed)
    {
        window.close();
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        board.onBoardClicked(boardPosition);
        if (uiController.saveButton->isMouseOver(mousePos)) {
            std::cout << "Save button klikniety"  << std::endl;
        }
        if (uiController.backButton->isMouseOver(mousePos)) {
            std::cout << "back button klikniety" << std::endl;
            Application::changeAppState(std::make_unique<MenuState>());
        }
        uiController.printBoardDebug(board.getBoard());
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        board.onBoardReleased(boardPosition);
        uiController.printBoardDebug(board.getBoard());
    }
}

void GameState::initialize() {
    board.startNewGame();
}

void GameState::render(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    uiController.redrawBoard(window, mousePos, board.getBoard(), board.getMovedFigure(), board.getCurrentPlayer(), board.isGameOver());
}