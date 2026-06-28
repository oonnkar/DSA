#include <iostream>
using namespace std;
// we want to store collection of element's. we need space to store collection of elements and we need size and length.
// we created structure and combine all of these in one structure
//
// structure array contains pointer to array. it's size and length(how many valid elements are present int array)
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    // default constructor/non paramatarized constructor
    Array();
    // default constructor/non paramatarized constructor
    Array(int length);
    // create structure array in heap
    Array(int *arr, int size);
    // diplay elements inside array
    void display();
    // append element in array
    void append(int x);
    // insert at specific index
    void insert(int index, int x);
    // delete elements in array
    int del_at_index(int index);
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
    int linear_search(int key);
    // Binary Search
    // Note:
    // - The array must be sorted in ascending order.
    //
    // Best Case:
    // - The key is found at the middle element.
    // - Comparisons = 1.
    // - Time Complexity = O(1).
    //
    // Worst Case:
    // - The key is found after repeatedly dividing the search space,
    //   or the key is not present.
    // - Maximum comparisons ≈ log2(n) + 1.
    // - Time Complexity = O(log n).
    //
    // Space Complexity:
    // - Iterative Binary Search: O(1)
    // - Recursive Binary Search: O(log n) due to the recursion stack.
    int iter_binary_search(int key);
    // Recursive Binary Search
    // The array must be sorted in ascending order.
    //
    // Best Case:
    // - The key is found at the middle element.
    // - Comparisons = 1.
    // - Time Complexity = O(1).
    //
    // Worst Case:
    // - The key is found after repeatedly dividing the search space,
    //   or the key is not present in the array.
    // - Maximum comparisons = log2(n) + 1.
    // - Time Complexity = O(log n).
    //
    // Space Complexity:
    // - O(log n) due to recursive function calls (call stack).
    int rec_binary_search_helper(int key, int l, int h);
    // Wrapper function to start the recursive binary search
    int rec_binary_search(int key)
    {
        return rec_binary_search_helper(key, 0, length - 1);
    }
    // get element at a particular index
    // Returns the value at index if valid; otherwise returns 0.
    int get(int index);
    // set element at a particular index
    // Updates the value at index when the index is valid.
    void set(int index, int x);
    // sum of all elements in array
    int sum_of_all_elements();
    // average of all elements in array
    float average();
    // search for maximum element in array
    int max();
    // minimum element in aarray
    int min();
    /* Reverse Array
    two methods of reverse array
    1.using auxaliry array
    2.using two pointer
    */
    void reverse_array_using_auxaliry_array();
    // reverse array using two pointer
    void reverse_array_using_two_pointer(struct Array *arr);
    // check array is sorted or not
    int isSorted(struct Array arr);
    // add number into sorted position in sorted array
    void addNumberToSorted(int x);
    // merge is process of combining two sorted lists into single sorted lists
    Array *merge(struct Array arr2);
};
//
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    Array arr2(arr, size);
    int ch = 0;
    do
    {

        int index, x;
        cout << "1. Display Array" << endl;
        cout << "2. Insert Element in array" << endl;
        cout << "3. Delete Element in array" << endl;
        cout << "4. Find minimum element in array" << endl;
        cout << "5. Find maximum element in array" << endl;
        cout << "6. Searching element in array" << endl;

        cout << "Enter our choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Displaying elements of list: ";
            arr2.display();
            cout << endl;
            break;
        case 2:

            cout << "Insert Index and element: ";
            cin >> index >> x;
            arr2.insert(index, x);
            break;
        case 3:
            cout << "Deletion Index: ";
            cin >> index;
            arr2.del_at_index(index);
            break;
        case 4:
            cout << "Minimum element in array is " << arr2.min() << endl;
            break;
        case 5:
            cout << "Maximum element in array is " << arr2.max() << endl;
            break;
        case 6:
            cout << "Enter element which you want to search in array" << endl;
            cin >> x;
            cout << "Element found at index" << arr2.linear_search(2) << endl;
            break;
        }
    } while (ch < 7 && ch > 0);
    return 0;
}
Array::Array()
{

    A = new int[10];
    length = 0;
    size = 0;
}

Array::Array(int length)
{

    A = new int[length];
    this->length = length;
    size = length;
}
Array::Array(int *arr, int size)
{
    A = new int[size * 2];
    length = size;
    size = size * 2;
    for (int i = 0; i < size; i++)
    {
        A[i] = arr[i];
    }
}
void Array::display()
{
    for (int i = 0; i < length; i++)
    {

        cout << A[i] << " ";
    }
}
void Array::append(int x)
{
    if (size > length)
    {
        A[length] = x;
        length++;
    }
    else
    {
        cout << "Array is full. Delete element and retry." << endl;
    }
}

void Array::insert(int index, int x)
{
    if (index >= 0 && index < length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}
int Array::del_at_index(int index)
{
    if (index >= 0 && index < length)
    {
        int x = A[index];

        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}
int Array::linear_search(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
            return i;
    }
    return 0;
}
int Array::iter_binary_search(int key)
{
    int l = 0, h = length, mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (key < A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int Array::rec_binary_search_helper(int key, int l, int h)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;

        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            return rec_binary_search_helper(key, l, mid - 1);
        else
            return rec_binary_search_helper(key, mid + 1, h);
    }
    // Key not found
    return -1;
}
int Array::get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return 0;
}
void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}
int Array::sum_of_all_elements()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += A[i];
    }
    return total;
}
float Array::average()
{
    return (float)sum_of_all_elements() / length;
}
int Array::max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
int Array::min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}
void Array::reverse_array_using_auxaliry_array()
{
    int *p;
    p = new int[length];

    for (int i = 0, j = length - 1; j >= 0; i++, j--)
    {
        p[i] = A[j];
    }
    for (int i = 0; i < length; i++)
    {
        A[i] = p[i];
    }
}
void Array::reverse_array_using_two_pointer(struct Array *arr)
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}
int Array::isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)

    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
void Array::addNumberToSorted(int x)
{
    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
}
Array * Array::merge(struct Array arr2)
{
    Array *arr3 = new Array(length + arr2.length);

    int i, j, k;
    i = j = k = 0;
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    return arr3;
}