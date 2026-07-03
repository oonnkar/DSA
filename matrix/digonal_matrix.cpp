#include <iostream>
using namespace std;
// Digonal Matrix
// Digonal matrix is square matrix where all nondigonal elements are zero.
// Digonal matrix takes lots of space for 0. We can store digonal matrix into single dimention array
class Digonal_Matrix
{
public:
    int n;
    int *arr;
    Digonal_Matrix()
    {
        this->n = 10;
        arr = new int[n];
    }
    Digonal_Matrix(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    void set(int i, int j, int x)
    {
        if (i == j)
        {
            arr[i - 1] = x;
        }
    }
    int get(int i, int j)
    {
        if (i == j)
            return arr[i - 1];
        return 0;
    }
    // display digonal matrix
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << arr[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    // destroctur
    ~Digonal_Matrix()
    {
        delete[] arr;
        arr=nullptr;
    }
};
// 
int main()
{
    Digonal_Matrix dm(4);
    dm.set(1, 1, 1);
    dm.set(2, 2, 2);
    dm.set(3, 3, 3);
    dm.set(4, 4, 4);
    dm.display();
    return 0;
}