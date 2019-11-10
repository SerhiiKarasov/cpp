#include <cmath>
#include <iostream>
//the example to show why we need to use factory

enum class PointType{
    cartesian, 
    polar
};

class Point
{
public:
    float x, y;

    Point(const float x, const float y, PointType type)
    {
        if(type == PointType::cartesian)
        {
            this->x = x;
            this->y = y;
        }
        else
        {
            this->x = x* cos(y);
            this->y = x*sin(y);
        }
        
    }
    
    Point(const float r, const float theta)
        : x{r}, y{theta}
    {
    }
};

int main()
{
    Point p{1, 2, PointType::polar};
}