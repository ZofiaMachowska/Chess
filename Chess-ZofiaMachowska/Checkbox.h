#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief A GUI component representing a checkbox.
 *
 * This class manages the visual appearance and behavior of a checkbox,
 * allowing users to select or deselect an option.
 */
class Checkbox
{
public:
    /**
     * @brief Constructs a Checkbox object with a given label and position.
     *
     * @param font The font used to render the checkbox's label.
     * @param label The text to be displayed next to the checkbox.
     * @param characterSize The font size of the label text.
     * @param position Coordinates where the corner of the checkbox should be located.
     */
    Checkbox(const sf::Font& font, const std::string& label, unsigned int characterSize, sf::Vector2f position);

    /**
     * @brief Destroys the Checkbox object.
     */
    ~Checkbox();

    /**
     * @brief Checks if the mouse cursor is currently over the checkbox.
     *
     * @param mousePosition The current position of the mouse cursor.
     * @return true if the mouse is over the checkbox, false otherwise.
     */
    bool isMouseOver(const sf::Vector2i& mousePosition);

    /**
     * @brief Draws the checkbox and its label onto the provided render window.
     *
     * @param window The SFML render window where the checkbox should be displayed.
     */
    void draw(sf::RenderWindow& window) const;

    /**
     * @brief Set the status of the checkbox.
     *
     * @param aiActive If true, the checkbox will be marked as checked, otherwise unchecked.
     */
    void setStatus(bool aiActive);

    /**
     * @brief Determines the current checked status of the checkbox.
     *
     * @return true if the checkbox is checked, false otherwise.
     */
    bool isCheckedStatus() const;

private:
    /**
     * @brief Indicates whether the checkbox is currently checked.
     */
    bool isChecked;

    /**
     * @brief The font used to render the checkbox's label.
     */
    sf::Font font;

    /**
     * @brief Represents the shape of the checkbox.
     */
    sf::RectangleShape checkboxBox;

    /**
     * @brief The text displayed next to the checkbox.
     */
    sf::Text checkboxText;
};

