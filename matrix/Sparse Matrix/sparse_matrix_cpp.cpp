#include <iostream>
using namespace std;
// Class to represent a Sparse Matrix using Coordinate List (COO) representation
class Sparse_Matrix
{
private:
    // Nested class representing an individual non-zero element with row index (i), column index (j), and value (x)
    class Element
    {
    public:
        int i, j, x;
    };
    int m, n, num_of_non_zero_elements; // Dimensions (m x n) and count of non-zero elements
    struct Element *arr;                // Dynamic array to store the coordinates and values of non-zero elements
public:
    // Constructor to initialize matrix dimensions and allocate dynamic memory for elements
    Sparse_Matrix(int m, int n, int num_of_non_zero_elements)
    {
        this->m = m;
        this->n = n;
        this->num_of_non_zero_elements = num_of_non_zero_elements;
        this->arr = new Element[num_of_non_zero_elements];
    }
    // Member function to read non-zero element coordinates and values from the user
    void read()
    {
        cout << "Enter all coordinates" << endl;
        for (int i = 0; i < num_of_non_zero_elements; i++)
        {
            cout << "Enter " << i << "th co-ordinate: ";
            cin >> arr[i].i >> arr[i].j >> arr[i].x;
            cout << endl;
        }
    }
    // Member function to reconstruct and display the sparse matrix in its original 2D dense grid layout
    void display()
    {
        int k = 0; // Index pointer for iterating through the non-zero elements array
        // Nested loop iterating through every position of the dense m x n grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the current coordinate matches the stored non-zero element, print its value
                if (i == arr[k].i && j == arr[k].j)
                {
                    cout << arr[k].x << " "; // Print non-zero value
                    k++;                     // Advance to the next element in the array
                }
                else
                {
                    cout << "0 "; // Print zero for empty positions
                }
            }
            cout << endl; // Move to the next row
        }
    }
    // Member function to add the current sparse matrix object with another sparse matrix passed as parameter
    Sparse_Matrix *sparse_matrix_addition(Sparse_Matrix mtrx2)
    {
        // Addition requires identical matrix dimensions
        if (m == mtrx2.m && n == mtrx2.n)
        {
            // Dynamically instantiate the resulting third sparse matrix on the heap
            Sparse_Matrix *mtrx3 = new Sparse_Matrix(m, n, m + mtrx2.n);
            // Re-assign explicit dimensions to the result matrix
            mtrx3->m = m;
            mtrx3->n = n;
            // Overwrite result array with maximum possible size (sum of non-zero elements from both matrices)
            mtrx3->arr = new Element[num_of_non_zero_elements + mtrx2.num_of_non_zero_elements];
            // b: tracker for current object (mtrx1), c: tracker for parameter (mtrx2), k: tracker for result (mtrx3)
            int b, c, k;
            b = c = k = 0;
            // Merge-sort logic loop traversing both arrays concurrently until one is completely exhausted
            while (b < num_of_non_zero_elements && c < mtrx2.num_of_non_zero_elements)
            {
                // Case 1: Current object's element row comes earlier. Copy it to result.
                if (arr[b].i < mtrx2.arr[c].i)
                {
                    mtrx3->arr[k] = arr[b];
                    b++, k++;
                }
                // Case 2: Parameter matrix's element row comes earlier. Copy it to result.
                else if (mtrx2.arr[c].i < arr[b].i)
                {
                    mtrx3->arr[k] = mtrx2.arr[c];
                    c++, k++;
                }
                // Case 3: Same row, but current object's element column comes earlier. Copy it to result.
                else if (arr[b].j < mtrx2.arr[c].j)
                {
                    mtrx3->arr[k] = arr[b];
                    b++, k++;
                }
                // Case 4: Same row, but parameter matrix's element column comes earlier. Copy it to result.
                else if (mtrx2.arr[c].j < mtrx2.arr[b].j)
                {
                    mtrx3->arr[k] = mtrx2.arr[c];
                    c++, k++;
                }
                // Case 5: Exact same row and column coordinates. Add values together into result.
                else
                {
                    {
                        mtrx3->arr[k].i = arr[b].i,
                        mtrx3->arr[k].j = arr[b].j,
                        mtrx3->arr[k].x = arr[b].x + mtrx2.arr[b].x;
                        b++, c++, k++;
                    }
                }
            }
            // Flush remaining leftover non-zero elements from the current object (mtrx1)
            while (b < num_of_non_zero_elements)
            {
                mtrx3->arr[k].i = arr[b].i,
                mtrx3->arr[k].j = arr[b].j,
                mtrx3->arr[k].x = arr[b].x;
                b++, k++;
            }
            // Flush remaining leftover non-zero elements from the parameter object (mtrx2)
            while (c < mtrx2.num_of_non_zero_elements)
            {
                mtrx3->arr[k].i = mtrx2.arr[c].i,
                mtrx3->arr[k].j = mtrx2.arr[c].j,
                mtrx3->arr[k].x = mtrx2.arr[c].x;
                c++, k++;
            }
            // Update the result matrix's internal count with the total number of populated elements
            mtrx3->num_of_non_zero_elements = k;
            return mtrx3;
        }
        // Return nullptr if matrix addition rule is violated due to dimension mismatch
        return nullptr;
    }
};
int main()
{
    // Instantiate, read coordinates for, and print the first Sparse_Matrix object
    Sparse_Matrix mtrx1(5, 5, 5);
    mtrx1.read();
    mtrx1.display();
    // Instantiate, read coordinates for, and print the second Sparse_Matrix object
    Sparse_Matrix mtrx2(5, 5, 5);
    mtrx2.read();
    mtrx2.display();
    // Invoke addition on mtrx1 passing mtrx2 as an argument, receiving back the heap pointer to the result matrix
    Sparse_Matrix *mtrx3 = mtrx1.sparse_matrix_addition(mtrx2);
    // Display the newly calculated result matrix by dereferencing its pointer
    (*mtrx3).display();
    return 0;
}