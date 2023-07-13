#pragma once
#include "MenuController.h"
#include "AppState.h"
#include "Application.h"
#include "GameState.h"

class MenuState : public AppState {
private:
	MenuController menuController;
	
public:
	MenuState();
	void handleEvent(sf::Event event, sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	void setTextures() override;
};


