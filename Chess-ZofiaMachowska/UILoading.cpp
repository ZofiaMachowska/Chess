#include "UILoading.h"

UILoading::UILoading() {
    initializeVisuals();
}

UILoading::~UILoading() {
}

void  UILoading::setReturnToMenuCallback(std::function<void()> callback) {
    returnToMenuCallback = std::move(callback);
}

void UILoading::setLoadThisGameCallback(std::function<void()> callback) {
    loadThisGameCallback = std::move(callback);
}

void UILoading::getSavedGames(std::vector<GameSaveLoad> games) {
    gamesLoading.clear();
    gamesLoading = games;
    buttons.clear();
    int gameIndex = games.size();
    int i = 1;
    for (GameSaveLoad game : gamesLoading) {
       std::string buttonText = "Zapis " + std::to_string(gameIndex) + ": " + game.timeOfSaving;
       Button* button = new Button(sf::Vector2f(350, i*100), sf::Vector2f(550, 80), font, buttonText, 36);
       buttons.push_back(button);
       i++;
       gameIndex--;
    }
}

void UILoading::redrawWindow(sf::RenderWindow& window) {
    backButton->draw(window);  
    for (Button* button : buttons) {
        button->draw(window);
    }
}

void UILoading::initializeVisuals() {
    font.loadFromFile("arial.ttf");
    backButton = new Button(sf::Vector2f(20, 20), sf::Vector2f(180, 70), font, "Return", 36);
}

void UILoading::handleButtonPress(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (backButton->isMouseOver(mousePosition)) {
        if (returnToMenuCallback) {
            returnToMenuCallback();
        }
    }
    int i = 0;
    for (Button* button : buttons) {
        if (button->isMouseOver(mousePosition)) {
            gameToLoadNext = i;
            if (loadThisGameCallback) {
                loadThisGameCallback();
            }
        }
        i++;
    }
}