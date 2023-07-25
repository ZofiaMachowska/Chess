#include "UILoadingController.h"

UILoadingController::UILoadingController() {
    initializeVisuals();
}

void  UILoadingController::setReturnToMenuCallback(std::function<void()> callback) {
    returnToMenuCallback = std::move(callback);
}

void UILoadingController::redrawWindow(sf::RenderWindow& window) {
    backButton->draw(window);
}

void UILoadingController::initializeVisuals() {
    font.loadFromFile("arial.ttf");
    backButton = new Button(sf::Vector2f(20, 20), sf::Vector2f(180, 70), font, "Return", 36);
}

void UILoadingController::handleButtonPress(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (backButton->isMouseOver(mousePosition)) {
        if (returnToMenuCallback) {
            returnToMenuCallback();
        }
    }
}