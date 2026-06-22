#include <iostream>
using namespace std;

// Total calls = 2^(n+1)-1, max activation records = n+1, Time = O(2^n), Space = O(n)
// For n=3: Total calls = 15, max activation records = 4, Time = O(2^3), Space = O(3)
void fun(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    fun(3);
    return 0;
}