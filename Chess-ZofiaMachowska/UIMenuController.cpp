#include "UIMenuController.h"

void UIMenuController::redrawWindow(sf::RenderWindow& window) {
    window.draw(titleText);
    window.draw(newGameButton);
    window.draw(newGameText);
    window.draw(loadGameButton);
    window.draw(loadGameText);
    window.draw(optionsButton);
    window.draw(optionsText);
    window.draw(exitButton);
    window.draw(exitText);
}

void UIMenuController::initializeVisuals() {
    if (!font.loadFromFile("arial.ttf")) {
        // Obs³uga b³êdu wczytywania czcionki
    }

    sf::Color backgroundColor = sf::Color::Black;
    sf::Color buttonColor = sf::Color(149, 191, 156); 

    titleText.setFont(font);
    titleText.setString("Chess");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(1200 / 2 - titleText.getLocalBounds().width / 2, 50);

    newGameButton.setSize(sf::Vector2f(300, 100));
    newGameButton.setPosition(1200 / 2 - newGameButton.getSize().x / 2, 150);
    newGameButton.setFillColor(buttonColor);

    newGameText.setFont(font);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(36);
    newGameText.setFillColor(sf::Color::White);
    newGameText.setStyle(sf::Text::Bold);
    newGameText.setPosition(newGameButton.getPosition().x + newGameButton.getSize().x / 2 - newGameText.getLocalBounds().width / 2,
        newGameButton.getPosition().y + newGameButton.getSize().y / 2 - newGameText.getLocalBounds().height / 2);

    loadGameButton.setSize(sf::Vector2f(300, 100));
    loadGameButton.setPosition(1200 / 2 - loadGameButton.getSize().x / 2, 300);
    loadGameButton.setFillColor(buttonColor);

    loadGameText.setFont(font);
    loadGameText.setString("Load Game");
    loadGameText.setCharacterSize(36);
    loadGameText.setFillColor(sf::Color::White);
    loadGameText.setStyle(sf::Text::Bold);
    loadGameText.setPosition(loadGameButton.getPosition().x + loadGameButton.getSize().x / 2 - loadGameText.getLocalBounds().width / 2,
        loadGameButton.getPosition().y + loadGameButton.getSize().y / 2 - loadGameText.getLocalBounds().height / 2);

    optionsButton.setSize(sf::Vector2f(300, 100));
    optionsButton.setPosition(1200 / 2 - optionsButton.getSize().x / 2, 450);
    optionsButton.setFillColor(buttonColor);

    optionsText.setFont(font);
    optionsText.setString("Options");
    optionsText.setCharacterSize(36);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setStyle(sf::Text::Bold);
    optionsText.setPosition(optionsButton.getPosition().x + optionsButton.getSize().x / 2 - optionsText.getLocalBounds().width / 2,
        optionsButton.getPosition().y + optionsButton.getSize().y / 2 - optionsText.getLocalBounds().height / 2);

    exitButton.setSize(sf::Vector2f(300, 100));
    exitButton.setPosition(1200 / 2 - exitButton.getSize().x / 2, 600);
    exitButton.setFillColor(buttonColor);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(36);
    exitText.setFillColor(sf::Color::White);
    exitText.setStyle(sf::Text::Bold);
    exitText.setPosition(exitButton.getPosition().x + exitButton.getSize().x / 2 - exitText.getLocalBounds().width / 2,
        exitButton.getPosition().y + exitButton.getSize().y / 2 - exitText.getLocalBounds().height / 2);
}

void  UIMenuController::setNewGameCallback(std::function<void()> callback) {
    newGameCallback = std::move(callback);
}

void  UIMenuController::setLoadGameCallback(std::function<void()> callback) {
    loadGameCallback = std::move(callback);
}

void  UIMenuController::setOptionsCallback(std::function<void()> callback) {
    optionsCallback = std::move(callback);
}

void UIMenuController::handleButtonPress(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (newGameButton.getGlobalBounds().contains(mousePositionFloat)) {
        if (newGameCallback) {
            newGameCallback();
        }
    }
    else if (loadGameButton.getGlobalBounds().contains(mousePositionFloat)) {
        if (loadGameCallback) {
            loadGameCallback();
        }
    }
    else if (optionsButton.getGlobalBounds().contains(mousePositionFloat)) {
        if (optionsCallback) {
            optionsCallback();
        }
    }
    else if (exitButton.getGlobalBounds().contains(mousePositionFloat)) {
        exit(0);
    }
}