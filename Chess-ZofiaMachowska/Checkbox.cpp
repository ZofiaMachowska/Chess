#include "Checkbox.h"

Checkbox::Checkbox(const sf::Font& font, const std::string& label, unsigned int characterSize, sf::Vector2f position)
    : font(font), isChecked(false)
{
    checkboxText.setFont(font);
    checkboxText.setString(label);
    checkboxText.setCharacterSize(characterSize);
    checkboxText.setPosition(position + sf::Vector2f(40.f, -10.f));

    checkboxBox.setSize(sf::Vector2f(30.f, 30.f));
    checkboxBox.setOutlineThickness(2.f);
    checkboxBox.setOutlineColor(sf::Color::Black);
    checkboxBox.setPosition(position);
}

Checkbox::~Checkbox() {

}

bool Checkbox::isMouseOver(const sf::Vector2i& mousePosition) {
    bool isClicked = checkboxBox.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
    if (isClicked) {
        isChecked = !isChecked;
    }
    return isClicked;
}

void Checkbox::draw(sf::RenderWindow& window) const {
    window.draw(checkboxBox);
    if (isChecked) {
        sf::RectangleShape checkmark(sf::Vector2f(checkboxBox.getSize().x - 8.f, checkboxBox.getSize().y - 8.f));
        checkmark.setPosition(checkboxBox.getPosition() + sf::Vector2f(4.f, 4.f));
        checkmark.setFillColor(sf::Color::Black);
        window.draw(checkmark);
    }
    window.draw(checkboxText);
}

bool Checkbox::isCheckedStatus() const {
    return isChecked;
}

void Checkbox::setStatus(bool aiActive) {
    isChecked = aiActive;
}
