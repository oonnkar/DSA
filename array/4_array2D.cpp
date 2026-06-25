#include <iostream>
using namespace std;

void array2D(int n)
{
    // 1. Stack-Allocated 2D Array
    // Create a 2x3 2D array on the stack and initialize it
    int arr[2][3] = {{1, 2, 3}, {1, 2, 3}};
    // Print the stack-allocated 2D array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // 2. Heap-Allocated 2D Array
    // Declare a pointer to a pointer (stored on the stack)
    int **p;
    // Allocate an array of 2 integer pointers on the heap
    p = new int *[2];
    // Allocate an array of 3 integers for each row on the heap
    p[0] = new int[3];
    p[1] = new int[3];
    // Initialize the heap-allocated array with some values
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            p[i][j] = (i + 1) * (j + 1);
        }
    }
    // Print the heap-allocated 2D array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    // 3. Memory Cleanup
    // Delete each individual row allocated on the heap
    delete[] p[0];
    delete[] p[1];
    // Delete the array of pointers
    delete[] p;
    p = nullptr;
}

int main()
{
    array2D(5);
    return 0;
}