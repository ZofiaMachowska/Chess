#include "UIOptionsController.h"

UIOptionsController::UIOptionsController() {
    player1CheckBox = new Checkbox(font, "Artificial", 24, sf::Vector2f(50.f, 80.f));
}

void UIOptionsController::redrawWindow(sf::RenderWindow& window) {
    window.draw(timerText);
    window.draw(player1AIText);
    window.draw(player2AIText);
    window.draw(inputBox);
    player1CheckBox->draw(window);
}

void UIOptionsController::initializeVisuals() {
    font.loadFromFile("arial.ttf");
    if (!font.loadFromFile("arial.ttf")) {
        // Obs³uga b³êdu wczytywania czcionki
    }

    const int fontSize = 60; // Wielkoœæ czcionki
    const int spacingY = 150; // Odstêp w pionie miêdzy elementami

    timerText.setFont(font);
    timerText.setString("Timer: ");
    timerText.setCharacterSize(fontSize);
    timerText.setPosition(310.f, 180.f);

    player1AIText.setFont(font);
    player1AIText.setString("Player 1: ");
    player1AIText.setCharacterSize(fontSize);
    player1AIText.setPosition(310.f, timerText.getPosition().y + spacingY);

    player2AIText.setFont(font);
    player2AIText.setString("Player 2: ");
    player2AIText.setCharacterSize(fontSize);
    player2AIText.setPosition(310.f, player1AIText.getPosition().y + spacingY);

    inputBox.setSize(sf::Vector2f(200.f, 30.f));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setPosition(250.f, timerText.getPosition().y + 20.f);
}

void UIOptionsController::handleButtonPress(sf::RenderWindow& window) {
   
}