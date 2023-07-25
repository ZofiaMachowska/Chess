#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Button.h"

class UIMenuController
{
public:
	UIMenuController();
   void redrawWindow(sf::RenderWindow& window);
   void initializeVisuals();
   void handleButtonPress(sf::RenderWindow& window);

   void setNewGameCallback(std::function<void()> callback);
   void setLoadGameCallback(std::function<void()> callback);
   void setOptionsCallback(std::function<void()> callback);

private:
	sf::Text titleText;
	sf::Font font;
	std::function<void()> newGameCallback, loadGameCallback, optionsCallback;
	Button* newGameButton;
	Button* loadGameButton;
	Button* optionsButton;
	Button* exitButton;
};
