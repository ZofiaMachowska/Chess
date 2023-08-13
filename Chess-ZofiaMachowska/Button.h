#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Font& font, const std::string& buttonText, int characterSize);
    ~Button();
    void draw(sf::RenderWindow& window);
    bool isMouseOver(const sf::Vector2i& mousePosition);
};

