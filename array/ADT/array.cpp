#include <iostream>
using namespace std;
// we want to store collection of element's. we need space to store collection of elements and we need size and length.
// we created structure and combine all of these in one structure
//
// structure array contains pointer to array. it's size and length(how many valid elements are present int array)
struct Array
{
    int *A;
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
//
int main()
{
    // user input size of array
    int size = 0, length = 0;
    cout << "enter size of array: ";
    cin >> size;
    cout << endl;
    cout << "enter length of array: ";
    cin >> length;
    cout << endl;
    // vairable of
    struct Array arr;
    // create array of mentioned size and assign first element's address to A
    arr.A = new int[size];
    arr.size = size;
    arr.length = length;
    // assgin values to elements inside array
    cout << "Enter elements inside array" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "enter " << i << "th element: ";
        cin >> arr.A[i];
    }
    // display all elements inside array
    display(arr);
    // append elements in array
    append(&arr, 4);
    // display elements of array
    display(arr);
    // insert at specific index in array
    insert(&arr, 0, 2);
    display(arr);
    // delete at index in array
    del_at_index(&arr, 2);
    display(arr);
    return 0;
}