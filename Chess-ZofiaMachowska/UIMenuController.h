#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>

class UIMenuController
{
public:
   void redrawWindow(sf::RenderWindow& window);
   void initializeVisuals();
   void handleButtonPress(sf::RenderWindow& window);

   void setNewGameCallback(std::function<void()> callback);
   void setLoadGameCallback(std::function<void()> callback);
   void setOptionsCallback(std::function<void()> callback);

private:
	sf::Text titleText, newGameText, loadGameText, optionsText, exitText;
	sf::RectangleShape newGameButton, loadGameButton, optionsButton, exitButton;
	sf::Font font;
	std::function<void()> newGameCallback, loadGameCallback, optionsCallback;
};
