#include<iostream> 
using namespace std; 


int main() 
{ 
    // array : collection of elements of the same data type stored in contiguous memory locations
    // creating an array of integers of size 5 and initializing it with values
    int arr[5] = {1, 2, 3, 4, 5}; 
    cout << "The elements of the array are: "; 
    for(int i = 0; i < 5; i++) 
    { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 

    // we can also create an array without initializing it, in which case the elements will have garbage values
    int arr2[5]; 
    cout << "The elements of the uninitialized array are: "; 
    for(int i = 0; i < 5; i++) 
    { 
        cout << arr2[i] << " "; 
    } 
    cout << endl;


    // variable length array (VLA) - not standard in C++, but supported by some compilers
    int n; 
    cin >> n;
    int arr3[n]; 
    cout << "Enter " << n << " elements: "; 
    for(int i = 0; i < n; i++) 
    { 
        cin >> arr3[i]; 
    }
    cout << "The elements of the array are: "; 
    for(int i = 0; i < n; i++) 
    { 
        cout << arr3[i] << " ";  
    }
    cout << endl;

    return 0; 
}