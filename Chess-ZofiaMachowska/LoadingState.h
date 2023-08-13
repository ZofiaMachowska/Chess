#pragma once
#include "AppState.h"
#include "Application.h"
#include "UILoadingController.h"

class LoadingState : public AppState {
private:
	UILoadingController uiLoadingController;

public:
	LoadingState();
	void handleEvent(sf::Event event, sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	void initialize() override;
};

