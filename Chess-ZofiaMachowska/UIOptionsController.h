#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Checkbox.h"
#include <iostream>

class UIOptionsController
{
public:
	UIOptionsController();
	void redrawWindow(sf::RenderWindow& window);
	void initializeVisuals();
	void handleButtonPress(sf::RenderWindow& window);
	Checkbox* player1CheckBox;

private:
	sf::Text timerText, timerTimeText, player1AIText, player2AIText;
	sf::RectangleShape inputBox;
	sf::Font font;
};
