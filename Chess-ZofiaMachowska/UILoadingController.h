#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include <iostream>
#include "Button.h"
#include "chessStructures.h"

class UILoadingController
{
public:
	UILoadingController();
	void redrawWindow(sf::RenderWindow& window);
	void initializeVisuals();
	void handleButtonPress(sf::RenderWindow& window);
	void setReturnToMenuCallback(std::function<void()> callback);
	void setLoadThisGameCallback(std::function<void()> callback);
	void getSavedGames(std::vector<Game> games);
	int gameToLoadNext = -1;

private:
	Button* backButton;
	sf::Font font;
	std::function<void()> returnToMenuCallback, loadThisGameCallback;
    std::vector<Game> gamesLoading;
	std::vector<Button*> buttons;
};

