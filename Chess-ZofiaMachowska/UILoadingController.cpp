#include "UILoadingController.h"

UILoadingController::UILoadingController() {
    initializeVisuals();
}

void  UILoadingController::setReturnToMenuCallback(std::function<void()> callback) {
    returnToMenuCallback = std::move(callback);
}

void UILoadingController::setLoadThisGameCallback(std::function<void()> callback) {
    loadThisGameCallback = std::move(callback);
}

void UILoadingController::getSavedGames(std::vector<Game> games) {
    gamesLoading.clear();
    gamesLoading = games;

    buttons.clear();
    int i = 1;
    for (Game game : gamesLoading) {
       Button* button = new Button(sf::Vector2f(450, i*100), sf::Vector2f(300, 80), font, "Zapis " + std::to_string(i), 36);
       buttons.push_back(button);
       i++;
    }
}

void UILoadingController::redrawWindow(sf::RenderWindow& window) {
    backButton->draw(window);
    for (Button* button : buttons) {
        button->draw(window);
    }
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
    int i = 0;
    for (Button* button : buttons) {
        if (button->isMouseOver(mousePosition)) {
            std::cout << "Wybrany do wczytania " <<  i << std::endl;
            gameToLoadNext = i;
            if (loadThisGameCallback) {
                loadThisGameCallback();
            }
        }
        i++;
    }
}