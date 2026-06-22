#include <iostream>
using namespace std;
// head recursion is a type of recursion where the recursive call is made before any other operations in the function. In this case, the function needs to keep track of additional information after the recursive call, which can lead to increased memory usage. head recursion cannot easily converted as loop like tail recursion but it can just it doesn't look similar to head recursion.
void headRecursion(int n)
{
    if (n > 0)
    {
        headRecursion(n - 1);
        cout << n << " ";
    }
}
// tail recursion is a type of recursion where the recursive call is the last statement in the function. In this case, the function does not need to keep track of any additional information after the recursive call, which allows for optimizations by the compiler. tail recursion can be easily converted as loop because it doesn't have to process anything at returning time.
void tailRecursion(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        tailRecursion(n - 1);
    }
}
// main function to demonstrate head and tail recursion
int main()
{
    cout << "Head Recursion: ";
    headRecursion(5);
    cout << "\nTail Recursion: ";
    tailRecursion(5);
    return 0;
}
