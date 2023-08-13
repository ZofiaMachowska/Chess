#include "MenuState.h"

MenuState::MenuState() {
    initialize();
}

void MenuState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
       uiMenuController.handleButtonPress(window);
    }
}

void MenuState::render(sf::RenderWindow& window) {
    uiMenuController.redrawWindow(window);
}

void MenuState::initialize() {
    uiMenuController.setNewGameCallback([this]() {
        Application::changeAppState(std::make_unique<GameState>());
        });

    uiMenuController.setLoadGameCallback([this]() {
        Application::changeAppState(std::make_unique<LoadingState>());
        });

    uiMenuController.setOptionsCallback([this]() {
        Application::changeAppState(std::make_unique<OptionsState>());
        });
}