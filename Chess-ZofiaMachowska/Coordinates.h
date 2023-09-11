template <typename T>
class Coordinates {
private:
    T x, y;
public:
    Coordinates(T x, T y) : x(x), y(y) {}
    T getX() const { return x; }
    T getY() const { return y; }
    void setX(T newX) { x = newX; }
    void setY(T newY) { y = newY; }
};
