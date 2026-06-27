#include <iostream>
using namespace std;
void declare_initilize_arr_methods()
{
    // declare and initilize array
    int arr1[5];                   // at runtime array of 5 integers will be created in side stack and since we have not intilized garbage values will be inside array
    int arr2[5] = {1, 2, 3, 4, 5}; // array of 5 integers will be created at runtime and and intilized with mention values
    int arr3[5] = {1, 2};          // array of 5 integers will be created at runtime and first 2 values are 1 and 2 and rest of values will be 0 once initilzation process starts it'll initilize all the elements
    int arr4[] = {1, 2, 3, 4, 5};  // whatever number's mentiond in list that size array created inside stack and initilized with those values
    // access elements of array
    for (int i = 0; i < 5; i++)
    {
        cout << arr4[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << i[arr4];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr4 + i);
    }
}
int main()
{
    declare_initilize_arr_methods();
    return 0;
}