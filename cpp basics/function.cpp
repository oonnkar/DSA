#include <iostream>
using namespace std;

// function is set of instructions that performs a specific task instead of writing the same code again and again, we can write a function and call it whenever we need it. that will save time and make the code more readable and maintainable and reduce load on single function.
// a and b are called formal parameters or parameters. they are used to receive values from the calling function. when we call the function add, we pass two values num1 and num2 as arguments to the function add, and they are called actual parameters or arguments. the function add takes two parameters a and b, which are called formal parameters or parameters.
int add(int a, int b)
{
    return a + b;
}

// parameter passing is the process of passing values to a function when we call it.
// there are three types of parameter passing in C++: pass by value, pass by reference, and pass by address.

// 1. Pass by value: in this method, a copy of the actual parameter is passed to the function. any changes made to the formal parameter inside the function do not affect the actual parameter outside the function.
void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    // this will not swap the values of x and y in the calling function, because we are working with copies of the actual parameters.
}

// 2. Pass by reference: in this method, a reference to the actual parameter is passed to the function. any changes made to the formal parameter inside the function will affect the actual parameter outside the function.
// this might be internally using inline functions or pointers, that depends on the compiler and the implementation.
void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    // this will swap the values of x and y in the calling function, because we are working with references to the actual parameters.
}

// pass by address: in this method, a pointer to the actual parameter is passed to the function. any changes made to the formal parameter inside the function will affect the actual parameter outside the function.
void swapByAddress(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // this will swap the values of x and y in the calling function, because we are working with pointers to the actual parameters.
}

// passing array to function: when we pass an array to a function, we are actually passing a pointer to the first element of the array. so any changes made to the array inside the function will affect the original array outside the function.
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// creating array in heap and returning pointer to the array from function
int* createArray(int size)
{
    int* arr = new int[size]; // dynamically allocating an array of integers in the heap
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1; // initializing the array with values from 1

    }

    return arr; // returning pointer to the array
}

// passing structure to function: when we pass a structure to a function, we are actually passing a copy of the structure. so any changes made to the structure inside the function will not affect the original structure outside the function.
struct Rectangle
{
    int length;
    int breadth;
};  

// passing structure to function by value. this will make copies of the structure and any changes made to the structure inside the function will not affect the original structure outside the function.
// even if we pass array in the structure, it will still be passed by value, because the structure is passed by value.
void printRectangle(Rectangle r)
{
    r.length = 20; // this will not affect the original structure outside the function, because we are working with a copy of the structure.
    cout << "Pass by value: " << "Length: " << r.length << ", Breadth: " << r.breadth << endl;
}

// pass by reference to structure: this will make references to the structure and any changes made to the structure inside the function will affect the original structure outside the function.
void printRectangleByReference(Rectangle &r)
{
    r.length = 20; // this will affect the original structure outside the function, because we are working with a reference to the structure.
    cout << "Pass by reference: " << "Length: " << r.length << ", Breadth: " << r.breadth << endl;
}

// pass by address to structure: this will make pointers to the structure and any changes made to the structure inside the function will affect the original structure outside the function.
void printRectangleByAddress(Rectangle *r)
{
    r->length = 20; // this will affect the original structure outside the function, because we are working with a pointer to the structure.
    cout << "Pass by address: "<<"Length: " << r->length << ", Breadth: " << r->breadth << endl;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    // calling the function add with user input

    int result = add(num1, num2); // num1 and num2 are passed as arguments to the function add, and the return value is stored in result and they are called actual parameters or arguments. The function add takes two parameters a and b, which are called formal parameters or parameters.
    cout << "Sum: " << result << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    // passing array to function
    // when we pass an array to a function, we are actually passing a pointer to the first element of the array. so any changes made to the array inside the function will affect the original array outside the function.

    printArray(arr, 5);

    // creating array in heap and returning pointer to the array from function
    int* heapArray = createArray(5);
    printArray(heapArray, 5);

    // don't forget to free the dynamically allocated memory
    delete[] heapArray;

    Rectangle r1 = {5, 10};
    printRectangle(r1);

    cout << "Length: " << r1.length << ", Breadth: " << r1.breadth << endl; // this will print the original values of the structure, because we are working with a copy of the structure.

    printRectangleByReference(r1);
    cout << "Length: " << r1.length << ", Breadth: " << r1.breadth << endl; // this will print the modified values of the structure, because we are working with a reference to the structure.

    printRectangleByAddress(&r1);
    cout << "Length: " << r1.length << ", Breadth: " << r1.breadth << endl; // this will print the modified values of the structure, because we are working with a pointer to the structure.

    return 0;
}   