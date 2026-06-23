#include <iostream>
using namespace std;
/*
    Taylor Series for e^x

    e^x = 1 + x/1! + x²/2! + x³/3! + ... + xⁿ/n!

    This version uses recursion and static variables.

    Recursive definition:
    T(x, n) = T(x, n-1) + xⁿ/n!

    Base Case:
    T(x, 0) = 1

    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
*/
double taylor_series_recursive(int x, int n)
{
    static double p = 1, f = 1;

    if (n == 0)
        return 1;

    double result = taylor_series_recursive(x, n - 1);

    p = p * x; // x^n
    f = f * n; // n!

    return result + p / f;
}
/*
    Iterative Version

    Directly computes each term of the series
    and accumulates the result.

    Formula:
    e^x = Σ (x^i / i!)

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
double taylor_series_iterative(int x, int n)
{
    double sum = 1;
    double p = 1;
    double f = 1;

    for (int i = 1; i <= n; i++)
    {
        p *= x; // x^i
        f *= i; // i!

        sum += p / f;
    }

    return sum;
}
/*
    Recursive Version with Reduced Multiplications
    (Horner's Rule)

    Original Taylor Series:

    e^x = 1 + x/1(1 + x/2(1 + x/3(1 + ... )))

    Recursive Definition:

    T(x,n) = 1 + (x/n) * T(x,n-1)

    Implemented from highest denominator
    to lowest denominator using a static variable.

    This version requires fewer multiplications
    than the standard recursive method.

    Time Complexity: O(n)
    Space Complexity: O(n)

    It is considered the most efficient recursive
    implementation of Taylor Series.
*/
double taylor_series_horner(int x, int n)
{
    static double s = 1;

    if (n == 0)
        return s;

    s = 1 + (double)x / n * s;

    return taylor_series_horner(x, n - 1);
}

int main()
{
    cout << "Recursive: "
         << taylor_series_recursive(3, 4) << endl;

    cout << "Iterative: "
         << taylor_series_iterative(3, 4) << endl;

    cout << "Horner's Recursive: "
         << taylor_series_horner(3, 4) << endl;

    return 0;
}