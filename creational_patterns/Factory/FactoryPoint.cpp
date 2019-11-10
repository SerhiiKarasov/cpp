#include <cmath>
#include <iostream>
//the example to show why we need to use factory method

class Point
{
private:
    Point(const float x, const float y) : x{x}, y{y}
    {
    }

public:
    float x, y;

    friend std::ostream &operator<<(std::ostream &os, const Point &obj)
    {
        return os << "x: " << obj.x << " y: " << obj.y << std::endl;
    }

    friend class PointFactory;
};

//generally factory methods are just copied to the separate class
class PointFactory
{
public:
    static Point NewCartesian(const float x, const float y)
    {
        return {x, y};
    }
    static Point NewPolar(const float r, const float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main()
{
    //Point p{1, 2}; cannot use as constructor is private
    auto pc = PointFactory::NewCartesian(1, 2);
    std::cout << pc << std::endl;
    auto pp = PointFactory::NewPolar(1, 2);
    std::cout << pp << std::endl;
}