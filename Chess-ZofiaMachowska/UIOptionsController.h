#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Checkbox.h"
#include <iostream>
#include "Button.h"
#include "chessStructures.h"

class UIOptionsController
{
public:
	UIOptionsController();
	void redrawWindow(sf::RenderWindow& window);
	void initializeVisuals();
	void handleButtonPress(const sf::Vector2i& mousePosition);
	void setOptionsReturnCallback(std::function<void()> callback);
	void setOptionsAiChangesCallback(std::function<void()> callback);
	void setCheckboxLastValue(Options lastOptionsValue);
	Options aiOptionsChoice;

private:
	void setAiOptionsChoice();
	std::function<void()> optionsReturnCallback, aiChangesCallback;
	Button* backButton;
	sf::Text player1AIText, player2AIText;
	sf::Font font;
	Checkbox* player1CheckBox;
	Checkbox* player2CheckBox;
};
