#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


/**
 * @brief A GUI component representing a clickable button.
 *
 * This class manages the visual appearance and behavior of a button.
 */
class Button
{
private:
    /**
     * @brief Represents the shape of the button.
     */
    sf::RectangleShape shape;

    /**
     * @brief The text displayed on the button.
     */
    sf::Text text;

public:
    /**
     * @brief Constructs a Button object.
     *
     * @param position Coordinates where the corner of the button should be located.
     * @param size Dimensions of the button.
     * @param font The font used to render the button's text.
     * @param buttonText The string to be displayed on the button.
     * @param characterSize The font size of the text displayed on the button.
     */
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Font& font, const std::string& buttonText, int characterSize);

    /**
     * @brief Destroys the Button object.
     */
    ~Button();

    /**
     * @brief Draws the button onto the provided render window.
     *
     * @param window The SFML render window where the button should be displayed.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Checks if the mouse cursor is currently over the button.
     *
     * @param mousePosition The current position of the mouse cursor.
     * @return true if the mouse is over the button, false otherwise.
     */
    bool isMouseOver(const sf::Vector2i& mousePosition);
};

