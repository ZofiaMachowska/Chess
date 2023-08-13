#pragma once
#include "UIMenuController.h"
#include "AppState.h"
#include "Application.h"
#include "GameState.h"

class MenuState : public AppState {
private:
	UIMenuController uiMenuController;
	
public:
	MenuState();
	~MenuState();
	void handleEvent(sf::Event event, sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	void initialize() override;
};


