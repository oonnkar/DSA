#include <iostream>
using namespace std;
// Power function: m^n
//
// Mathematical recursive definition:
// P(m, 0) = 1                         (base case)
// P(m, n) = m * P(m, n - 1), n > 0    (recursive case)
//
// Explanation:
// To compute m^n, multiply m by m^(n-1).
//
// Example:
// 2^5
// = 2 * 2^4
// = 2 * 2 * 2^3
// = 2 * 2 * 2 * 2^2
// = 2 * 2 * 2 * 2 * 2^1
// = 2 * 2 * 2 * 2 * 2 * 2^0
// = 32
//
// Conversion to a recursive function:
// - P(m,0)=1 becomes:
//       if (n == 0) return 1;
// - P(m,n)=m*P(m,n-1) becomes:
//       return m * power(m,n-1);
int power(int m, int n)
{
    if (n == 0) // Base case
        return 1;

    return power(m, n - 1) * m; // Recursive case
}
// Optimized Power Function (Exponentiation by Squaring)
//
// Mathematical observations:
//
// If n is even:
//     m^n = (m^2)^(n/2)
//
// If n is odd:
//     m^n = m * (m^2)^((n-1)/2)
//
// These formulas reduce the exponent by half in each recursive call,
// resulting in O(log n) recursive calls instead of O(n).
//
// Example: 2^8
// = (2^2)^4
// = (4^2)^2
// = (16^2)^1
// = 256
//
// Example: 2^5
// = 2 * (2^2)^2
// = 2 * (4^2)^1
// = 2 * 16
// = 32
//
// Conversion to a recursive function:
// - Base case:
//       if (n == 0) return 1;
// - Even exponent:
//       power(m*m, n/2)
// - Odd exponent:
//       m * power(m*m, n/2)
int power_with_reduced_multiplications(int m, int n)
{
    if (n == 0) // Base case
        return 1;

    if (n % 2 == 0) // n is even
    {
        return power_with_reduced_multiplications(m * m, n / 2);
    }
    else // n is odd
    {
        return m * power_with_reduced_multiplications(m * m, n / 2);
    }
}
int main()
{
    cout << power(2, 9) << endl;
    cout << power_with_reduced_multiplications(2, 9) << endl;
    return 0;
}