#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>

class MenuController
{
public:

   void redrawWindow(sf::RenderWindow& window);
   void handleButtonPress(sf::RenderWindow& window);
   void setTextures();
   void handleLoadButtonPressed();
   void handleNewGameButtonPressed();
   void handleExitButtonPressed();
   void setNewGameCallback(std::function<void()> callback);

private:
	sf::Text titleText, newGameText, loadGameText, exitText;
	sf::RectangleShape newGameButton, loadGameButton, exitButton;
	sf::Font font;
	std::function<void()> newGameCallback;
};
