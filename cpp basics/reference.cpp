#include <iostream>
using namespace std;

int main() {
    // reference is an alias/nickname for another variable. it is not a new variable, but rather another name for an existing variable.
    int x = 10;
    int& ref = x; // ref is a reference to x
    cout << "Value of x: " << x << endl;     // 10
    cout << "Value of ref: " << ref << endl; // 10
    cout << "Address of x: " << &x << endl;  // address of x
    cout << "Address of ref: " << &ref << endl; // address of x (same as x)
    // references must be initialized when they are declared and cannot be null. They cannot be reassigned to refer to another variable after initialization.
    // references does not consume additional memory, as they are just another name for an existing variable. They are often used to pass variables to functions without making a copy of the variable, which can improve performance.

    int y = 20;
    ref = y; // this does not change the reference to refer to y, it changes the value of x to be equal to y
    cout << "Value of x after ref = y: " << x << endl; // 20
    cout << "Value of ref after ref = y: " << ref << endl; // 20
    cout << "Address of x after ref = y: " << &x << endl; // address of x
    cout << "Address of ref after ref = y: " << &ref << endl; // address of x (same as x)   
    return 0;
}