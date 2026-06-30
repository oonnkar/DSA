#include <iostream>
using namespace std;
// Find all pairs whose sum is equal to the given value using
// the brute-force approach.
//
// Approach:
// - Compare every element with every other element.
// - If the sum of a pair equals the given sum, print the pair.
//
// Time Complexity : O(n²)
// Space Complexity: O(1)
void find_pairs_with_given_sum_bruteforce(int *arr, int array_size, int sum)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        for (int j = i + 1; j < array_size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " + " << arr[j]
                     << " = " << sum << endl;
            }
        }
    }
}
// Returns the maximum element present in the array.
//
// Time Complexity : O(n)
// Space Complexity: O(1)
int find_max_element(int *arr, int array_size)
{
    int max = arr[0];

    for (int i = 1; i < array_size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}
// Find all pairs whose sum is equal to the given value using
// a hash table.
//
// Assumptions:
// - All array elements are non-negative.
// - The hash table stores the frequency of elements already seen.
//
// Approach:
// - Traverse the array once.
// - For every element x, check whether (sum - x) has already
//   been encountered.
// - If yes, print the pair.
// - Otherwise, insert x into the hash table.
//
// Time Complexity : O(n)
// Space Complexity: O(max_element)
void find_pairs_with_given_sum_hashing(int *arr, int array_size, int sum)
{
    int max = find_max_element(arr, array_size);
    // Hash table to store frequencies
    int *hash = new int[max + 1];
    // Initialize hash table
    for (int i = 0; i <= max; i++)
        hash[i] = 0;
    for (int i = 0; i < array_size; i++)
    {
        int complement = sum - arr[i];

        if (complement >= 0 && complement <= max && hash[complement] > 0)
        {
            cout << arr[i] << " + "
                 << complement << " = "
                 << sum << endl;
        }

        hash[arr[i]]++;
    }
    delete[] hash;
}
int main()
{
    int arr[] = {1, 4, 6, 2, 3, 0, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 5;
    cout << "Pairs using Brute Force:\n";
    find_pairs_with_given_sum_bruteforce(arr, size, sum);
    cout << "\nPairs using Hashing:\n";
    find_pairs_with_given_sum_hashing(arr, size, sum);
    return 0;
}