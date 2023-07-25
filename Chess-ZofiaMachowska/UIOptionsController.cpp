#include "UIOptionsController.h"

UIOptionsController::UIOptionsController() {
    initializeVisuals();
}

void UIOptionsController::redrawWindow(sf::RenderWindow& window) {
    window.draw(player1AIText);
    window.draw(player2AIText);
    player1CheckBox->draw(window);
    player2CheckBox->draw(window);
    backButton->draw(window);
}

void  UIOptionsController::setOptionsReturnCallback(std::function<void()> callback) {
    optionsReturnCallback = std::move(callback);
}

void UIOptionsController::initializeVisuals() {
    font.loadFromFile("arial.ttf");
    const int fontSize = 60; 

    player1AIText.setFont(font);
    player1AIText.setString("Player 1: ");
    player1AIText.setCharacterSize(fontSize);
    player1AIText.setPosition(310.f, 250.f);

    player2AIText.setFont(font);
    player2AIText.setString("Player 2: ");
    player2AIText.setCharacterSize(fontSize);
    player2AIText.setPosition(310.f, player1AIText.getPosition().y + 150);

    player1CheckBox = new Checkbox(font, "Artificial", 40, sf::Vector2f(600.f, 280.f));
    player2CheckBox = new Checkbox(font, "Artificial", 40, sf::Vector2f(600.f, 430.f));
    backButton = new Button(sf::Vector2f(20, 20), sf::Vector2f(180, 70), font, "Return", 36);
}

void UIOptionsController::handleButtonPress(sf::RenderWindow& window) {
    player1CheckBox->handleEvent(window);
    player2CheckBox->handleEvent(window);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (backButton->isMouseOver(mousePosition)) {
        if (optionsReturnCallback) {
            optionsReturnCallback();
        }
    }
}