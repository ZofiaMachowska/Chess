#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include "Checkbox.h"
#include <iostream>
#include "Button.h"

class UIModule {
public:
	virtual void redrawWindow(sf::RenderWindow& window) = 0;
	virtual void initializeVisuals() = 0;
	virtual void handleButtonPress(const sf::Vector2i& mousePosition) = 0;
};
