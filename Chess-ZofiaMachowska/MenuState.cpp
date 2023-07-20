#include "MenuState.h"

MenuState::MenuState() {
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
    uiMenuController.initializeVisuals();

    uiMenuController.setNewGameCallback([this]() {
        std::cout << "udany callback dla setNewGame" << std::endl;
        Application::changeAppState(std::make_unique<GameState>());
        });
}