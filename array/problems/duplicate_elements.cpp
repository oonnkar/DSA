#include <iostream>
using namespace std;
// Finds duplicate elements in a sorted array.
// Approach:
// - Compare adjacent elements.
// - Count consecutive occurrences.
// Time Complexity: O(n)
// Space Complexity: O(1)
void find_duplicates(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            int j = i + 1;
            while (j < n && arr[j] == arr[i])
                j++;
            cout << arr[i] << " is " << j - i << " times" << endl;
            i = j - 1;
        }
    }
}
// Finds duplicate elements using a hash table.
// Assumptions:
// - Array elements are non-negative.
// - Maximum element is arr[n-1].
// Approach:
// - Store frequencies in a hash table.
// - Print elements whose frequency is greater than 1.
// Time Complexity: O(n)
// Space Complexity: O(max element)
void find_duplicates_using_hash_table(int *arr, int n)
{
    int *p = new int[arr[n - 1] + 1];
    for (int i = 0; i <= arr[n - 1]; i++)
        p[i] = 0;
    for (int i = 0; i < n; i++)
        p[arr[i]]++;
    for (int i = 0; i <= arr[n - 1]; i++)
    {
        if (p[i] > 1)
            cout << i << " is " << p[i] << " times." << endl;
    }
    delete[] p;
}
int main()
{
    int arr[] = {0, 1, 1, 2, 2, 2, 3};
    find_duplicates_using_hash_table(arr, 7);
    return 0;
}