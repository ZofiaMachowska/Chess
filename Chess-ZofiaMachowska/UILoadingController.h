#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include <iostream>
#include "Button.h"

class UILoadingController
{
public:
	UILoadingController();
	void redrawWindow(sf::RenderWindow& window);
	void initializeVisuals();
	void handleButtonPress(sf::RenderWindow& window);
	void setReturnToMenuCallback(std::function<void()> callback);

private:
	Button* backButton;
	sf::Font font;
	std::function<void()> returnToMenuCallback;
};

