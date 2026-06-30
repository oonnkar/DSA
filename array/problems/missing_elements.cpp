#include <iostream>
using namespace std;
// Finds the single missing element in a sorted sequence of
// natural numbers starting from 1.
//
// Assumptions:
// - The array is sorted in ascending order.
// - The sequence starts from 1.
// - Exactly one element is missing.
//
// Approach:
// 1. Find the last element (n).
// 2. Calculate the expected sum of numbers from 1 to n.
// 3. Calculate the actual sum of the array elements.
// 4. The difference between the two sums is the missing element.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
int find_single_missing_element_from_first_n_natural_nums(int *arr, int array_size)
{
    int n = arr[array_size - 1];
    int sum_of_first_n_natural_nums = n * (n + 1) / 2;
    int sum_of_elements_in_array = 0;

    for (int i = 0; i < array_size; i++)
    {
        sum_of_elements_in_array += arr[i];
    }

    return sum_of_first_n_natural_nums - sum_of_elements_in_array;
}
// Finds the single missing element in a sorted sequence of
// natural numbers starting from 1.
//
// Assumptions:
// - The array is sorted in ascending order.
// - The sequence starts from 1.
// - Exactly one element is missing.
//
// Approach:
// 1. Find the last element (n).
// 2. Calculate the expected sum of numbers from 1 to n.
// 3. Calculate the actual sum of the array elements.
// 4. The difference between the two sums is the missing element.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// Finds all missing elements in a sorted sequence that may
// start from any number (not necessarily 1).
//
// Assumptions:
// - The array is sorted in ascending order.
// - One or more elements may be missing.
//
// Approach:
// - In a perfectly consecutive sequence,
//   arr[i] - i remains constant.
// - Store this constant as 'diff'.
// - Whenever arr[i] - i becomes greater than diff,
//   one or more elements are missing.
// - Print the missing elements and update diff.
//
// Example:
// Input : {6, 7, 8, 11, 12, 15}
// Output: 9 10 13 14
//
// Time Complexity: O(n)
// Space Complexity: O(1)
void find_missing_element_any_sequence(int *arr, int n)
{
    int diff = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (diff != arr[i] - i)
        {
            while (diff < arr[i] - i)
            {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 7, 6};
    find_missing_element_any_sequence(arr, 5);

    return 0;
}