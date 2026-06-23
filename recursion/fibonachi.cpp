#include <iostream>
using namespace std;
// Problem: compute the n-th Fibonacci number using a straightforward recursive strategy.
// Approach: solve by definition with base cases for n=0 and n=1, and recursively compute
// n-1 and n-2. This is correct but not optimal due to repeated subproblem computation.
int rec_fibonachi(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return rec_fibonachi(n - 2) + rec_fibonachi(n - 1);
}
// Problem: compute the n-th Fibonacci number using an iterative approach.
// Approach: use bottom-up computation with two variables to avoid recursion overhead.
// This is more optimal than plain recursion because it runs in linear time and constant space.
int iter_fibonachi(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {

        int t0 = 0, t1 = 1, result = 0;
        for (int i = 2; i <= n; i++)
        {
            result = t0 + t1;
            t0 = t1;
            t1 = result;
        }
        return result;
    }
}
// Problem: compute the n-th Fibonacci number efficiently while avoiding redundant recursion.
// Approach: use memoization to cache results of previously computed Fibonacci values.
// This turns exponential recursive time into linear time by reusing subproblem results.
int fibonachi_using_memoization(int n)
{
    static int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    if (n == 0)
    {
        arr[0] = 0;
        return 0;
    }
    else if (n == 1)
    {
        arr[1] = 1;
        return 1;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    arr[n] = fibonachi_using_memoization(n - 1) + fibonachi_using_memoization(n - 2);
    return arr[n];
}
// Entry point for the program; can be extended to call Fibonacci functions or run examples.
int main()
{
    cout << rec_fibonachi(5);
    cout << iter_fibonachi(5);
    cout << fibonachi_using_memoization(6);

    return 0;
}