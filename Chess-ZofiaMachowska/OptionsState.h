#pragma once
#include <SFML/Graphics.hpp>
#include "AppState.h"
#include "UIOptionsController.h"


class OptionsState : public AppState {
private:
    UIOptionsController uiOptionsController;

public:
    OptionsState();
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void initialize() override;
};
