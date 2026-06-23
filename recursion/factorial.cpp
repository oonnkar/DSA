#include <iostream>
using namespace std;
// Sum of first n natural numbers:
//
// Mathematical recursive definition:
// S(0) = 0                      (base case)
// S(n) = n + S(n - 1), n > 0    (recursive case)
//
// Explanation:
// The sum of the first n natural numbers can be obtained by
// adding n to the sum of the first (n - 1) natural numbers.
//
// Example:
// S(5)
// = 5 + S(4)
// = 5 + 4 + S(3)
// = 5 + 4 + 3 + S(2)
// = 5 + 4 + 3 + 2 + S(1)
// = 5 + 4 + 3 + 2 + 1 + S(0)
// = 15
//
// Conversion to a recursive function:
// - The mathematical base case S(0) = 0 becomes:
//       if (n == 0) return 0;
// - The recursive formula S(n) = n + S(n - 1) becomes:
//       return n + sum(n - 1);
int sum(int n)
{
    if (n == 0) // Base case
        return 0;

    return n + sum(n - 1); // Recursive case
}
int recFact(int n)
{

    if (n == 0)
        return 1;
    return recFact(n - 1) * n;
}
int iterFact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    // function calls
    int recFactResult = recFact(3);
    int iterFactResult = iterFact(3);
    // function output
    cout << "result of recursive function is " << recFactResult << ", and iterative factorial result is " << iterFactResult;
    return 0;
}