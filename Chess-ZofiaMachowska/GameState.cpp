#include "GameState.h"

GameState::GameState() : game(Application::savedAiOptions.getFirstPlayerAi(), Application::savedAiOptions.getSecondPlayerAi()) {
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
        game.onBoardClicked(boardPosition.x, boardPosition.y);
        if (uiBoard.saveButton->isMouseOver(mousePos)) {
            Application::saveLoadManager.addNewGameToHistory(game);
            Application::saveLoadManager.saveGameToFile();
        }
        if (uiBoard.backButton->isMouseOver(mousePos)) {
            Application::changeAppState(std::make_unique<MenuState>());
            Application::saveLoadManager.setFlagToLoadGame(-1);
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
       game.onBoardReleased(boardPosition.x, boardPosition.y);
    }
}

void GameState::initialize() {
    if (Application::saveLoadManager.shouldLoadAGame()) {
        game.loadGame(Application::saveLoadManager.getGameToLoad());
    }
    else {
        game.start();
    }
}

void GameState::render(sf::RenderWindow& window) {
    uiBoard.redrawBoard(window, game);
}