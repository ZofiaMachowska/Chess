/**
 * @class Coordinates
 * @brief Represents 2D coordinates with generic data types.
 *
 * This template class provides a way to manipulate
 * 2D coordinates with generic data types.
 *
 * @tparam T The data type for the coordinates
 */
template <typename T>
class Coordinates {
private:
    T x; /**< The X-coordinate. */
    T y; /**< The Y-coordinate. */

public:
    /**
     * @brief Constructor for Coordinates.
     * @param x The X-coordinate.
     * @param y The Y-coordinate.
     */
    Coordinates(T x, T y) : x(x), y(y) {}

    /**
     * @brief Get the X-coordinate.
     * @return The X-coordinate value.
     */
    T getX() const { return x; }

    /**
     * @brief Get the Y-coordinate.
     * @return The Y-coordinate value.
     */
    T getY() const { return y; }

    /**
     * @brief Set the X-coordinate.
     * @param newX The new X-coordinate value.
     */
    void setX(T newX) { x = newX; }

    /**
     * @brief Set the Y-coordinate.
     * @param newY The new Y-coordinate value.
     */
    void setY(T newY) { y = newY; }
};
