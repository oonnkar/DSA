#include <iostream>
using namespace std;

// object-oriented programming style: code is organized into classes and objects, allowing for better data encapsulation, abstraction, and reusability.

// Define a class to represent a rectangle.
class Rectangle
{
private:
    int length;
    int breadth;

public:
    // Constructor to initialize the rectangle with length and breadth
    Rectangle(int l, int b) : length(l), breadth(b) {}
    // Function to calculate the area of the rectangle
    int area()
    {
        return length * breadth;
    }
    // Function to calculate the perimeter of the rectangle
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main()
{

    int length, breadth;
    cout << "Enter length and breadth: ";
    cin >> length >> breadth;
    Rectangle rect(length, breadth);
    cout << "The area of the rectangle is " << rect.area() << endl;
    cout << "The perimeter of the rectangle is " << rect.perimeter() << endl;
    return 0;
}