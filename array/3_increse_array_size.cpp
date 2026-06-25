#include <iostream>
using namespace std;

// Function to demonstrate dynamic array resizing
void resize(int n)
{
    // 1. Static Array Limitation
    int arr[5];
    // int arr[20]; // Error: Cannot redefine a static array with the same name.
    // 2. Initial Heap Allocation
    // Create an array of 5 integers on the heap
    int *p = new int[5];
    // Initialize array elements with their index values
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    // 3. Dynamic Resizing Process
    // To expand size without losing data, we use a temporary pointer
    int *q = p;
    // Allocate a larger array of 20 integers for p
    p = new int[20];
    // Copy elements from the old array (q) to the new array (p)
    for (int i = 0; i < n; i++)
    {
        p[i] = q[i];
    }
    // Free the old array memory to avoid a memory leak
    delete[] q;
    q = nullptr;
    // 4. Memory Cleanup
    // Free the newly allocated array before exiting the function
    delete[] p;
}

int main()
{
    resize(5);
    return 0;
}