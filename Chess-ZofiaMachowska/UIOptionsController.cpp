#include "UIOptionsController.h"

UIOptionsController::UIOptionsController() {
    initializeVisuals();
}

UIOptionsController::~UIOptionsController() {
}

void UIOptionsController::redrawWindow(sf::RenderWindow& window) {
    window.draw(player1AIText);
    window.draw(player2AIText);
    player1CheckBox->draw(window);
    player2CheckBox->draw(window);
    backButton->draw(window);
}

void UIOptionsController::setCheckboxLastValue(Options lastOptionsValue) {
    player1CheckBox->setStatus(lastOptionsValue.firstPlayerAi);
    player2CheckBox->setStatus(lastOptionsValue.secondPlayerAi);
}

void UIOptionsController::setAiOptionsChoice() {
    aiOptionsChoice.firstPlayerAi = player1CheckBox->isCheckedStatus();
    aiOptionsChoice.secondPlayerAi = player2CheckBox->isCheckedStatus();
}

void  UIOptionsController::setOptionsAiChangesCallback(std::function<void()> callback) {
    aiChangesCallback = std::move(callback);
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

void UIOptionsController::handleButtonPress(const sf::Vector2i& mousePosition) {
    if (player1CheckBox->isMouseOver(mousePosition) || player2CheckBox->isMouseOver(mousePosition)) {
        setAiOptionsChoice();
        if (aiChangesCallback) {
            aiChangesCallback();
        }
    }
    if (backButton->isMouseOver(mousePosition) && optionsReturnCallback) {
        optionsReturnCallback();
    }
}