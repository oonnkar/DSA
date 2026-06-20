#include <iostream>
using namespace std;

int area(int x, int y)
{
    return x * y;
}
int perimeter(int x, int y)
{
    return 2 * (x + y);
}
int main()
{
    // This is a modular approach, where the code is broken into smaller, manageable functions. Each function performs a specific task, making the code easier to read and maintain.
    // In this example, we have two functions: area() and perimeter(), which perform area and perimeter calculations respectively. The main() function handles user input and output, while the logic for the operations is encapsulated in separate functions.
    int length, breadth;
    cout << "Enter length and breadth: ";
    cin >> length >> breadth;
    int area_result = area(length, breadth);
    cout << "The area of " << length << " and " << breadth << " is " << area_result << endl;
    int perimeter_result = perimeter(length, breadth);
    cout << "The perimeter of " << length << " and " << breadth << " is " << perimeter_result << endl;
    return 0;
}