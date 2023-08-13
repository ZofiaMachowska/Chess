#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Checkbox
{
public:
    Checkbox(const sf::Font& font, const std::string& label, unsigned int characterSize, sf::Vector2f position);
    ~Checkbox();
    bool isMouseOver(const sf::Vector2i& mousePosition);
    void draw(sf::RenderWindow& window) const;
    void setStatus(bool aiActive);
    bool isCheckedStatus() const;

private:
    bool isChecked;
    sf::Font font;
    sf::RectangleShape checkboxBox;
    sf::Text checkboxText;
};

