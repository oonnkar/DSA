#include <iostream>
using namespace std;
// Nested Recursion:
// The function calls itself inside another recursive call.
// Example: fun(fun(n + 11))
// Recursive calls continue until the base condition is satisfied.
int fun(int n)
{
    if (n > 100)
        return n - 10;

    return fun(fun(n + 11));
}
int main()
{
    int x = fun(200);
    cout << x;
    return 0;
}