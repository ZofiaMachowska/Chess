#include "OptionsState.h"

OptionsState::OptionsState() {
    initialize();
}

OptionsState::~OptionsState() {
}

void OptionsState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        uiOptions.handleButtonPress(mousePosition);
    }
}

void OptionsState::render(sf::RenderWindow& window) {
	uiOptions.redrawWindow(window);
}

void OptionsState::initialize() {
    //uiOptionsController.setCheckboxLastValue(Application::getAiPlayerOptionsValue());
    uiOptions.setOptionsReturnCallback([this]() {
        Application::changeAppState(std::make_unique<MenuState>());
        });
    //uiOptionsController.setOptionsAiChangesCallback([this]() {
    //    Application::setOptionsChoice(uiOptionsController.aiOptionsChoice);
    //    });
}
 