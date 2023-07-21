#include "OptionsState.h"

OptionsState::OptionsState() {
}

void OptionsState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        uiOptionsController.handleButtonPress(window);
        uiOptionsController.player1CheckBox->handleEvent(window);
        uiOptionsController.player2CheckBox->handleEvent(window);
    }
}

void OptionsState::render(sf::RenderWindow& window) {
	uiOptionsController.redrawWindow(window);
}

void OptionsState::initialize() {
	uiOptionsController.initializeVisuals();
}
