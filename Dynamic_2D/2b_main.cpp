#include <bits/stdc++.h>
#include "myMatrix.h"
using namespace std;

// Dimension of input square matrix
#define N 4

// Driver program to test above functions
int main()
{
    int **mat;

    int row, col;
    cout << "Enter number of rows of the 1st matrix :-\n";
    cin >> row;
    cout << "Enter number of columns of the 1st matrix :-\n";
    cin >> col;

    // Allocate 2D Array
    mat = alloc2DArray(mat, row, col);

    // Display 2D Array/Matrix
    cout << "The 1st Matrix is :-\n";
    display2DArray(mat, row, col);

    //
    //
    // Multiplication of 2 matrices
    cout << "\n\n\nMultiplication of 2 Matrices\n";
    int row_2, col_2;
    cout << "Enter number of rows of the 2nd matrix :-\n";
    cin >> row_2;
    cout << "Enter number of columns of the 2nd matrix :-\n";
    cin >> col_2;
    int **mat_2;
    // Allocate 2D Array
    mat_2 = alloc2DArray(mat_2, row_2, col_2);
    // Display 2D Array/Matrix
    cout << "The 2nd Matrix is :-\n";
    display2DArray(mat_2, row_2, col_2);
    if (col == row_2)
    {
        // A 2D Array to store the result
        int **res;
        // Dymnamic Allocation of 2D Resultant Array
        res = new int *[row];
        for (int i = 0; i < row; i++)
            res[i] = new int[col_2];

        res = multMatrix(mat, mat_2, res, row, col, row_2, col_2);
        cout << "\nThe resultant Array after multiplication is :-\n";
        display2DArray(res, row, col_2);
        // Deallocating the result matrix
        dealloc2DArray(res, row, col_2);
    }
    else
    {
        cout << "\nMultiplication not Possible\n";
    }
    // Deallocating the 2nd matrix
    dealloc2DArray(mat_2, row_2, col_2);

    //
    //
    // Getting determinant of the matrix
    cout << "\n\n\nGetting the determinant of the 1st Matrix :-\n";
    if (row == col)
        cout << "\nThe determinant of the matrix :- " << detMatrix(mat, row) << "\n\n";
    else
        cout << "\nNot possible to find determinant since no. of row != columns\n";

    // Deallocating 2D Array
    dealloc2DArray(mat, row, col);
    cout << "\n\nAll matrices are deallocated";

    return 0;
}
