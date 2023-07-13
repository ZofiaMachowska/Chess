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
        menuController.handleButtonPress(window);
    }
}

void MenuState::render(sf::RenderWindow& window) {
    menuController.redrawWindow(window);
}

void MenuState::setTextures() {
    menuController.setTextures();

    //obsluga eventow na klikniecie buttona
    menuController.setNewGameCallback([this]() {
        std::cout << "udany callback dla setNewGame" << std::endl;
        Application::changeAppState(std::make_unique<GameState>());
        });
}