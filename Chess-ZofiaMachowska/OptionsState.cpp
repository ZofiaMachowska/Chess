#include "OptionsState.h"

OptionsState::OptionsState() {
}

void OptionsState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        uiOptionsController.handleButtonPress(mousePosition);
    }
}

void OptionsState::render(sf::RenderWindow& window) {
	uiOptionsController.redrawWindow(window);
}

void OptionsState::initialize() {
    uiOptionsController.setCheckboxLastValue(Application::getAiPlayerOptionsValue());
    uiOptionsController.setOptionsReturnCallback([this]() {
        Application::changeAppState(std::make_unique<MenuState>());
        });
    uiOptionsController.setOptionsAiChangesCallback([this]() {
        Application::setOptionsChoice(uiOptionsController.aiOptionsChoice);
        });
}
 