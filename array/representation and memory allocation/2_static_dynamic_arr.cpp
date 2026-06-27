#include <iostream>
using namespace std;
// array creation in side stack and heap
void static_dynamic_array(int n)
{
    int arr[n];     // array of size will be created in heap
    int *p;         // pointer to integer will be created in heap
    p = new int[n]; // array of 5 integers will be created in heap and add of first element arr[0] will be stored in p
    // intitilization/access elements of array
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        p[i] = i + 1;
    }

    delete[] p; // after using p if we dont want array in heap we can delete and that solves memory leak
}
int main()
{
    static_dynamic_array(5);
    return 0;
}