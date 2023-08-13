#include "GameState.h"

SavingGameController GameState::saveController;

GameState::GameState() : board(), uiController(), event() {
    initialize();
}

GameState::~GameState() {
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
            saveController.addNewGameToHistory(board.getBoard(), board.getCurrentPlayers(), board.isGameOver());
            saveController.saveGameToFile();
        }
        if (uiController.backButton->isMouseOver(mousePos)) {
            Application::setGameIndexToLoad(-1);
            Application::changeAppState(std::make_unique<MenuState>());
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        board.onBoardReleased(boardPosition);
    }
}

void GameState::initialize() {
    saveController.setSaveNewGameCallback([this]() {
        Application::setSavedGames(saveController.getGames());
        });

    if (Application::gameToLoad >= 0) {
        board.loadGame(Application::getGameToLoad());
    }
    else {
        board.startNewGame(Application::getAiPlayerOptionsValue());
    }
}

void GameState::render(sf::RenderWindow& window) {
    uiController.redrawBoard(window, board.getBoard(), board.getMovedFigure(), board.getCurrentPlayer(), board.isGameOver());
}