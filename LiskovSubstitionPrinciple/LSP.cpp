// Liskov Substitution Principle
// Objects in a program should be replaceable with instances of their subtypes w/o altering the correctness of the program

#include <iostream>

class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(const int width, const int height)
        : width{width},
          height{height}
    {
    }

    virtual int GetWidth() const { return width; }
    virtual void SetWidth(const int width) { this->width = width; }
    virtual int GetHeight() const { return height; }
    virtual void SetHeight(const int height) { this->height = height; }
    int Area() const { return width * height; }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle{size, size} {}
    virtual void SetWidth(const int width) override
    {
        this->width = width;
        this->height = width;
    }
    virtual void SetHeight(const int height) override
    {
        this->height = height;
        this->width = height;
    }
    //it is specific to the square, hence would not be possible to be used in void process(Rectangle &r)
    void SetSize(const int size)
    {
        this->height = size;
        this->width = size;
    }
};

void process(Rectangle &r)
{
    int w = r.GetWidth();
    r.SetHeight(10);
    std::cout << "expect area to be " << (w * 10) << ", got " << r.Area() << std::endl;
}

struct RectangleFactory
{
    static Rectangle CreateRectangle(int w, int h);
    static Rectangle CreateSquare(int w);
};
int main()
{
    Rectangle r{5, 5};
    process(r);

    // better not to have this class at all, better to have rectangle factory
    // Square s{5};
    // process(s);

    return 0;
}