#include <iostream>
using namespace std;

int main()
{
    // monolithic approach is  when all the code is written in a single function, which can make it difficult to read and maintain. In this example, we will calculate the sum and product of two numbers using a monolithic approach.
    // This code is not modular and can be difficult to read and maintain, especially as the program grows in complexity. It is generally recommended to use a more modular approach, such as breaking the code into functions, to improve readability and maintainability.
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int sum = a + b;
    cout << "The sum is: " << sum << endl;

    int product = a * b;
    cout << "The product is: " << product << endl;

    return 0;
}