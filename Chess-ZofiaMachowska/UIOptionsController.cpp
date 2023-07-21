#include "UIOptionsController.h"

UIOptionsController::UIOptionsController() {
    player1CheckBox = new Checkbox(font, "Artificial", 40, sf::Vector2f(600.f, 280.f));
    player2CheckBox = new Checkbox(font, "Artificial", 40, sf::Vector2f(600.f, 430.f));
}

void UIOptionsController::redrawWindow(sf::RenderWindow& window) {
    window.draw(player1AIText);
    window.draw(player2AIText);
    window.draw(returnText);
    player1CheckBox->draw(window);
    player2CheckBox->draw(window);
}

void UIOptionsController::initializeVisuals() {
    font.loadFromFile("arial.ttf");
    if (!font.loadFromFile("arial.ttf")) {
        // Obs³uga b³êdu wczytywania czcionki
    }

    const int fontSize = 60; 
    const int spacingY = 150; 

    player1AIText.setFont(font);
    player1AIText.setString("Player 1: ");
    player1AIText.setCharacterSize(fontSize);
    player1AIText.setPosition(310.f, 250.f);

    returnText.setFont(font);
    returnText.setString("Return");
    returnText.setCharacterSize(40);
    returnText.setPosition(20.f, 20.f);

    player2AIText.setFont(font);
    player2AIText.setString("Player 2: ");
    player2AIText.setCharacterSize(fontSize);
    player2AIText.setPosition(310.f, player1AIText.getPosition().y + spacingY);
}

void UIOptionsController::handleButtonPress(sf::RenderWindow& window) {
   
}