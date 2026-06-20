#include <iostream>
using namespace std;

// monolithic programming style: all code is in a single file, with no separation of concerns or modularity.
// modular programming style: code is organized into separate functions and structures, promoting reusability and maintainability.
// struct and functions programming style: code is organized into structures and functions, allowing for better data encapsulation and abstraction.

// Define a structure to represent a rectangle
struct Rectangle
{
    int length;
    int breadth;
};

// intialize the rectangle structure with length and breadth
void initRectangle(Rectangle &r, int l, int b)
{
    r.length = l;
    r.breadth = b;
}

// Function to calculate the area of a rectangle
int area(Rectangle r)
{
    return r.length * r.breadth;
}

// Function to calculate the perimeter of a rectangle
int perimeter(Rectangle r)
{
    return 2 * (r.length + r.breadth);
}

int main()
{
    Rectangle rect;
    cout << "Enter length and breadth: ";
    cin >> rect.length >> rect.breadth;
    initRectangle(rect, rect.length, rect.breadth);
    cout << "The area of the rectangle is " << area(rect) << endl;
    cout << "The perimeter of the rectangle is " << perimeter(rect) << endl;
    return 0;
}