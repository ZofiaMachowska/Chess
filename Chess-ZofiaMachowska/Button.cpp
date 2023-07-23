#include "Button.h"

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Font& font, const std::string& buttonText, int characterSize) {
    sf::Color buttonColor = sf::Color(149, 191, 156);

    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(buttonColor);

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(characterSize);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(position.x  + 20, position.y + 10);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isMouseOver(const sf::Vector2i& mousePosition) {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}