#include <iostream>
using namespace std;

int main()
{
    // pointer is a variable that stores the memory address of another variable
    int a = 10;
    int *p = &a;                                     // p is a pointer to an integer, it stores the address of a
    cout << "Value of a: " << a << endl;             // 10
    cout << "Address of a: " << &a << endl;          // address of a
    cout << "Value of p: " << p << endl;             // address of a
    cout << "Value pointed to by p: " << *p << endl; // dereferencing p, gives the value of a, which is 10

    *p = 20;                                                            // changing the value pointed to by p
    cout << "Value of a after changing through pointer: " << a << endl; // 20

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;                                            // we do not need to use & because arr is already a pointer to the first element
    cout << "First element of array: " << *ptr << endl;        // 1
    cout << "Second element of array: " << *(ptr + 1) << endl; // 2
    cout << "Third element of array: " << *(ptr + 2) << endl;  // 3

    // pointer arithmetic: adding an integer to a pointer moves the pointer by that many elements
    ptr += 2;                                                             // move the pointer to the third element
    cout << "Current element after pointer arithmetic pointer pointing is: " << *ptr << endl; // 3

    // no matter what data type the pointer is, it will always take up the same amount of memory (4 or 8 bytes depending on the system)
    cout << "Size of pointer: " << sizeof(ptr) << " bytes" << endl;

    return 0;
}