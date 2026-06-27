#include <iostream>
using namespace std;
// we want to store collection of element's. we need space to store collection of elements and we need size and length.
// we created structure and combine all of these in one structure
//
// structure array contains pointer to array. it's size and length(how many valid elements are present int array)
struct Array
{
    int A[10];
    int size;
    int length;
};
// diplay elements inside array
void display(struct Array arr)
{
    cout << "Displaying elements of list" << endl;
    for (int i = 0; i < arr.length; i++)
    {

        cout << arr.A[i] << " ";
    }
    cout << endl;
}
// append element in array
void append(struct Array *arr, int x)
{
    if (arr->size > arr->length)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
    else
    {
        cout << "Array is full. Delete element and retry." << endl;
    }
}
// insert at specific index
void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
// delete elements in array
int del_at_index(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];

        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
// Linear Search:
// Best case (successful search): Element is found at index 0.
// Number of comparisons = 1.
//
// Worst case (successful search): Element is found at the last index (n - 1).
// Number of comparisons = n.
//
// Worst case (unsuccessful search): Element is not present in the array.
// Number of comparisons = n.
//
// Time Complexity:
// Best Case: O(1)
// Worst Case: O(n)
int linear_search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return 0;
}
//
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    cout << "Searching for element 4 using linear search and element i found at index ";
    cout << linear_search(arr, 4);
    return 0;
}