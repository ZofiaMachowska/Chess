#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Checkbox
{
public:
    Checkbox(const sf::Font& font, const std::string& label, unsigned int characterSize, sf::Vector2f position);

    bool isMouseOver(const sf::RenderWindow& window) const;

    void handleEvent(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window) const;

    bool isCheckedStatus() const;

private:
    sf::Font font;
    bool isChecked;
    sf::RectangleShape checkboxBox;
    sf::Text checkboxText;
};

