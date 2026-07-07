#include <iostream>
using namespace std;
// Structure to represent an individual non-zero element in the sparse matrix
// Holds the row index, column index, and the actual value of the element
struct Element
{
    int i, j, x;
};
// Structure to represent the complete sparse matrix
// Holds the matrix dimensions (m x n), the total count of non-zero elements,
// and a dynamic array containing all non-zero elements
struct Sparse_Matrix
{
    int m, n, num_of_non_zero_elements;
    struct Element *arr;
};
// Function to take input and initialize a sparse matrix
void create(struct Sparse_Matrix *s)
{
    // 1. Get matrix dimensions from the user
    cout << "Enter dimentions of sparse matrix: ";
    cin >> s->m >> s->n;
    cout << endl;
    // 2. Get the number of non-zero elements to allocate memory
    cout << "Enter num of non zero elements ";
    cin >> s->num_of_non_zero_elements;
    cout << endl;
    // 3. Dynamically allocate memory for the array of non-zero elements
    s->arr = new Element[s->num_of_non_zero_elements];
    // 4. Input the row index, column index, and value for each non-zero element
    cout << "Enter all coordinates" << endl;
    for (int i = 0; i < s->num_of_non_zero_elements; i++)
    {
        cout << "Enter " << i << "th co-ordinate: ";
        cin >> s->arr[i].i >> s->arr[i].j >> s->arr[i].x;
        cout << endl;
    }
}
// Function to reconstruct and display the sparse matrix in its original 2D grid form
void display(struct Sparse_Matrix s)
{
    int k = 0; // Pointer index for traversing the stored non-zero elements array
    // Loop through every possible row and column of the matrix
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            // Check if the current grid position matches the coordinates of the next non-zero element
            if (i == s.arr[k].i && j == s.arr[k].j)
            {
                cout << s.arr[k].x << " "; // Print the non-zero element
                k++;                       // Move to the next non-zero element in the array
            }
            else
            {
                cout << "0 "; // Print 0 for empty positions
            }
        }
        cout << endl; // Move to the next row
    }
}
// Function to add two sparse matrices using coordinate representation in memory
struct Sparse_Matrix *sparse_matrix_addition(struct Sparse_Matrix mtrx1, struct Sparse_Matrix mtrx2)
{
    // Matrix addition is only possible if both matrices have the same dimensions (m x n)
    if (mtrx1.m == mtrx2.m && mtrx1.n == mtrx2.n)
    {
        // Allocate memory for the resulting third sparse matrix on the heap
        struct Sparse_Matrix *mtrx3 = new Sparse_Matrix;
        // The resulting matrix will have the exact same dimensions as the input matrices
        mtrx3->m = mtrx1.m;
        mtrx3->n = mtrx1.n;
        // Allocate maximum possible size for the new array (sum of non-zero elements of both matrices)
        mtrx3->arr = new Element[mtrx1.num_of_non_zero_elements + mtrx2.num_of_non_zero_elements];
        // b: index tracker for mtrx1, c: index tracker for mtrx2, k: index tracker for mtrx3
        int b, c, k;
        b = c = k = 0;
        // Core loop: Traverse both coordinate arrays simultaneously until one of them runs out of elements
        while (b < mtrx1.num_of_non_zero_elements && c < mtrx2.num_of_non_zero_elements)
        {
            // Case 1: The row index of mtrx1's element is smaller.
            // Copy mtrx1's element to mtrx3 and advance mtrx1's tracker.
            if (mtrx1.arr[b].i < mtrx2.arr[c].i)
            {
                mtrx3->arr[k] = mtrx1.arr[b];
                b++, k++;
            }
            // Case 2: The row index of mtrx2's element is smaller.
            // Copy mtrx2's element to mtrx3 and advance mtrx2's tracker.
            else if (mtrx2.arr[c].i < mtrx1.arr[b].i)
            {
                mtrx3->arr[k] = mtrx2.arr[c];
                c++, k++;
            }
            // Case 3: Both elements are in the same row, but mtrx1's column index is smaller.
            // Copy mtrx1's element to mtrx3 and advance mtrx1's tracker.
            else if (mtrx1.arr[b].j < mtrx2.arr[c].j)
            {
                mtrx3->arr[k] = mtrx1.arr[b];
                b++, k++;
            }
            // Case 4: Both elements are in the same row, but mtrx2's column index is smaller.
            // Copy mtrx2's element to mtrx3 and advance mtrx2's tracker.
            else if (mtrx2.arr[c].j < mtrx2.arr[b].j)
            {
                mtrx3->arr[k] = mtrx2.arr[c];
                c++, k++;
            }
            // Case 5: Both elements share the exact same row and column coordinates.
            // Add their values together, store the result in mtrx3, and advance all trackers.
            else
            {
                {
                    mtrx3->arr[k].i = mtrx1.arr[b].i,
                    mtrx3->arr[k].j = mtrx1.arr[b].j,
                    mtrx3->arr[k].x = mtrx1.arr[b].x + mtrx2.arr[b].x;
                    b++, c++, k++;
                }
            }
        }
        // Loop to copy any leftover elements from mtrx1 if mtrx2 finished traversing first
        while (b < mtrx1.num_of_non_zero_elements)
        {
            mtrx3->arr[k].i = mtrx1.arr[b].i,
            mtrx3->arr[k].j = mtrx1.arr[b].j,
            mtrx3->arr[k].x = mtrx1.arr[b].x;
            b++, k++;
        }
        // Loop to copy any leftover elements from mtrx2 if mtrx1 finished traversing first
        while (c < mtrx2.num_of_non_zero_elements)
        {
            mtrx3->arr[k].i = mtrx2.arr[c].i,
            mtrx3->arr[k].j = mtrx2.arr[c].j,
            mtrx3->arr[k].x = mtrx2.arr[c].x;
            c++, k++;
        }
        // Record the actual count of valid non-zero elements generated in the result matrix
        mtrx3->num_of_non_zero_elements = k;
        return mtrx3;
    }
    // Return a null pointer if dimensions do not match
    return nullptr;
}
int main()
{
    // Create, initialize, and display the first sparse matrix
    struct Sparse_Matrix mtrx1;
    create(&mtrx1);
    display(mtrx1);
    // Create, initialize, and display the second sparse matrix
    struct Sparse_Matrix mtrx2;
    create(&mtrx2);
    display(mtrx2);
    // Perform addition on the two matrices and retrieve the pointer to the result matrix
    Sparse_Matrix *mtrx3 = sparse_matrix_addition(mtrx1, mtrx2);
    // Display the final combined sparse matrix
    display(*mtrx3);
    return 0;
}