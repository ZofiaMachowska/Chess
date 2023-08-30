#include "MenuState.h"

MenuState::MenuState() {
    initialize();
}

MenuState::~MenuState() {
}

void MenuState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
       uiMenu.handleButtonPress(window);
    }
}

void MenuState::render(sf::RenderWindow& window) {
    uiMenu.redrawWindow(window);
}

void MenuState::initialize() {
    uiMenu.setNewGameCallback([this]() {
        Application::changeAppState(std::make_unique<GameState>());
        });

    uiMenu.setLoadGameCallback([this]() {
        Application::changeAppState(std::make_unique<LoadingState>());
        });

    uiMenu.setOptionsCallback([this]() {
        Application::changeAppState(std::make_unique<OptionsState>());
        });
}