#include <iostream>
using namespace std;
// static variable inside a function is declared as static, it is initialized only once and keeps its value across function calls.
int static_var_rec(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return static_var_rec(n - 1) + x;
    }
    return 0;
}
//
int main()
{
    int x  = static_var_rec(5);
    cout << x << endl; 

    return 0;
}