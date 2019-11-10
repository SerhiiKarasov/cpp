#include <cmath>
#include <iostream>
//the example to show why we need to use factory method

class Point
{
private:
    Point(const float x, const float y) : x{x}, y{y}
    {
    }
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

public:
    float x, y;

    friend std::ostream &operator<<(std::ostream &os, const Point &obj)
    {
        return os << "x: " << obj.x << " y: " << obj.y << std::endl;
    }

    static PointFactory pf;
};

int main()
{
    //Point p{1, 2}; cannot use as constructor is private
    auto pc = Point::pf.NewCartesian(1, 2);
    std::cout << pc << std::endl;
    auto pp = Point::pf.NewPolar(1, 2);
    std::cout << pp << std::endl;
}