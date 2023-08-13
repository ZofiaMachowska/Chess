#include "LoadingState.h"

LoadingState::LoadingState() {
    initialize();
}

LoadingState::~LoadingState() {
}

void LoadingState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        uiLoadingController.handleButtonPress(window);
    }
}

void LoadingState::render(sf::RenderWindow& window) {
    uiLoadingController.redrawWindow(window);
}

void LoadingState::initialize() {
    uiLoadingController.getSavedGames(Application::getSavedGamesValues());
    uiLoadingController.setReturnToMenuCallback([this]() {
        Application::changeAppState(std::make_unique<MenuState>());
        });

    uiLoadingController.setLoadThisGameCallback([this]() {
        Application::setGameIndexToLoad(uiLoadingController.gameToLoadNext);
        Application::changeAppState(std::make_unique<GameState>());
        });
}
