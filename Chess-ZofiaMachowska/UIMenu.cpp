#include "UIMenu.h"

UIMenu::UIMenu() {
    initializeVisuals();
}

UIMenu::~UIMenu() {
}

void UIMenu::redrawWindow(sf::RenderWindow& window) {
    window.draw(titleText);
    newGameButton->draw(window);
    loadGameButton->draw(window);
    optionsButton->draw(window);
    exitButton->draw(window);
}

void UIMenu::initializeVisuals() {
    font.loadFromFile("arial.ttf"); 
    titleText.setFont(font);
    titleText.setString("Chess");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(1200 / 2 - titleText.getLocalBounds().width / 2, 50);

    newGameButton = new Button(sf::Vector2f(450, 150), sf::Vector2f(300, 100), font, "New Game", 36);
    loadGameButton = new Button(sf::Vector2f(450, 300), sf::Vector2f(300, 100), font, "Load Game", 36);
    optionsButton = new Button(sf::Vector2f(450, 450), sf::Vector2f(300, 100), font, "Options", 36);
    exitButton = new Button(sf::Vector2f(450, 600), sf::Vector2f(300, 100), font, "Exit", 36);
}

void  UIMenu::setNewGameCallback(std::function<void()> callback) {
    newGameCallback = std::move(callback);
}

void  UIMenu::setLoadGameCallback(std::function<void()> callback) {
    loadGameCallback = std::move(callback);
}

void  UIMenu::setOptionsCallback(std::function<void()> callback) {
    optionsCallback = std::move(callback);
}

void UIMenu::handleButtonPress(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (newGameButton->isMouseOver(mousePosition)) {
        if (newGameCallback) {
            newGameCallback();
        }
    }
    else if (loadGameButton->isMouseOver(mousePosition)) {
        if (loadGameCallback) {
            loadGameCallback();
        }
    }
    else if (optionsButton->isMouseOver(mousePosition)) {
        if (optionsCallback) {
            optionsCallback();
        }
    }
    else if (exitButton->isMouseOver(mousePosition)) {
        exit(0);
    }
}