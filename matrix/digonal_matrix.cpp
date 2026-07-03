#include <iostream>
using namespace std;
// Diagonal matrix stores only diagonal elements in a 1-D array.
class Digonal_Matrix
{
public:
    int n;
    int *arr;
    // Default constructor creates a 10 x 10 diagonal matrix.
    Digonal_Matrix()
    {
        this->n = 10;
        arr = new int[n];
    }
    // Parameterized constructor creates an n x n diagonal matrix.
    Digonal_Matrix(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    // Stores x only if the position is on the main diagonal.
    void set(int i, int j, int x)
    {
        if (i == j)
        {
            arr[i - 1] = x;
        }
    }
    // Returns the stored value if it is a diagonal element, otherwise returns 0.
    int get(int i, int j)
    {
        if (i == j)
            return arr[i - 1];
        return 0;
    }
    // Displays the complete diagonal matrix.
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
    // Destructor releases the allocated memory.
    ~Digonal_Matrix()
    {
        delete[] arr;
        arr = nullptr;
    }
};
// Lower triangular matrix stores only lower triangular elements in a 1-D array.
class Lower_Tringular_Matrix
{
public:
    int n;
    int *arr;
    // Default constructor creates a 10 x 10 lower triangular matrix.
    Lower_Tringular_Matrix()
    {
        this->n = 10;
        arr = new int[this->n * (this->n + 1) / 2];
    }
    // Parameterized constructor creates an n x n lower triangular matrix.
    Lower_Tringular_Matrix(int n)
    {
        this->n = n;
        arr = new int[this->n * (this->n + 1) / 2];
    }
    // Stores x only if the element belongs to the lower triangle.
    void set(int i, int j, int x)
    {
        if (i >= j)
        {
            arr[i * (i - 1) / 2 + (j - 1)] = x;
        }
    }
    // Returns the stored value if it belongs to the lower triangle, otherwise returns 0.
    int get(int i, int j)
    {
        if (i >= j)
            return arr[i * (i - 1) / 2 + (j - 1)];
        return 0;
    }
    // Displays the complete lower triangular matrix.
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    cout << arr[i * (i - 1) / 2 + (j - 1)] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    // Destructor releases the allocated memory.
    ~Lower_Tringular_Matrix()
    {
        delete[] arr;
        arr = nullptr;
    }
};
int main()
{
    int x;
    Lower_Tringular_Matrix lm(4);
    // Read matrix elements from the user.
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> x;
            lm.set(i, j, x);
        }
        cout << endl;
    }
    // Display the matrix.
    lm.display();
    return 0;
}