// C++ program to find Determinant of a matrix
#include <bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 4

// function to allocate 2D Array
int **alloc2DArray(int **mat, int row, int col)
{
    // Dymnamic Allocation of 2D Array
    mat = new int *[row];
    for (int i = 0; i < row; i++)
        mat[i] = new int[col];

    cout << "Enter Array elements\n";
    for (int i = 0; i < row; i++)
    {
        cout << "Enter " << col << " elements of the " << i << "th row :-\n";
        for (int j = 0; j < col; j++)
            cin >> mat[i][j];

        cout << "\n";
    }

    return mat;
}

// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
int **cofactor(int **m, int index, int s) // function to extarct the minor of m[0][index]
{
    int **c;
    c = alloc2DArray(c, (s - 1), (s - 1)); //space allocation for minor matrix

    int ci = 0, cj = 0; //  indices for the minor matrix c
    int i, j;           // indices for orginal martix m

    // copying suitable eles from m to c excluding 0th row & (index) cloumn
    for (i = 1; i < s; i++)
    {
        cj = 0;
        for (j = 0; j < s; j++)
        {
            if (j != index)
                c[ci][cj++] = m[i][j];
        }
        ci++;
    }
    return c;
}

int detMatrix(int **m, int n)
{
    if (n == 1)
        return m[0][0];
    else if (n == 2)
        return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
    else
    {
        int res = 0, i = 0; // row is always fixed

        for (int j = 0; j < n; j++)
        {
            int **cofMat = cofactor(m, j, n); // function to extract the minor of m[0][j]
            res += (pow(-1, (i + j)) * m[0][j] * detMatrix(cofMat, (n - 1)));
        }
        return res;
    }
}

/* function for displaying the matrix */
void display2DArray(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
int **multMatrix(int **mat1,
                 int **mat2,
                 int **res, int r1, int c1, int r2, int c2)
{
    int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < r2; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return res;
}

// Function to deallocate a 2D Array
void dealloc2DArray(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
        delete[] mat[i];

    delete[] mat;
}
