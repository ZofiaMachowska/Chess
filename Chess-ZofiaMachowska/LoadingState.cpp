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
        uiLoading.handleButtonPress(window);
    }
}

void LoadingState::render(sf::RenderWindow& window) {
    uiLoading.redrawWindow(window);
}

void LoadingState::initialize() {
    uiLoading.getSavedGames(Application::saveLoadManager.getGames());

    uiLoading.setReturnToMenuCallback([this]() {
        Application::changeAppState(std::make_unique<MenuState>());
        });

    uiLoading.setLoadThisGameCallback([this]() {
        Application::saveLoadManager.setFlagToLoadGame(uiLoading.gameToLoadNext);
        Application::changeAppState(std::make_unique<GameState>());
        });
}
