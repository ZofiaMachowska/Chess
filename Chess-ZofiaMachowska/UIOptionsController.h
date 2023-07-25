#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Checkbox.h"
#include <iostream>
#include "Button.h"

class UIOptionsController
{
public:
	UIOptionsController();
	void redrawWindow(sf::RenderWindow& window);
	void initializeVisuals();
	void handleButtonPress(sf::RenderWindow& window);
	void setOptionsReturnCallback(std::function<void()> callback);

private:
	std::function<void()> optionsReturnCallback;

	Checkbox* player1CheckBox;
	Checkbox* player2CheckBox;
	Button* backButton;
	sf::Text player1AIText, player2AIText;
	sf::Font font;
};
