#include <iostream>
using namespace std;

class Rectangle
{
private:
    // data members of the class
    int length;
    int breadth;

public:
    // member functions of the class
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b);
    void setLength(int l)
    {
        length = l;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }
    int area();
    int perimeter();
    ~Rectangle();
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
Rectangle::~Rectangle()
{
    cout << "Destructor called for Rectangle with length: " << length << " and breadth: " << breadth << endl;
}

int main()
{
    Rectangle r1(10, 5);
    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;
    return 0;
}