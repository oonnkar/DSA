#include <iostream>
using namespace std;
// Indirect Recursion:
// fun1() calls fun2(), and fun2() calls fun1().
void fun2(int n);
// fun1 prints n and calls fun2 with (n - 1),
// reducing the value by 1 on each call.
void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun2(n - 1);
    }
}
// fun2 prints n and calls fun1 with (n / 2),
// reducing the value by half on each call.
void fun2(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        fun1(n / 2);
    }
}
int main()
{
    fun1(20);
    return 0;
}
