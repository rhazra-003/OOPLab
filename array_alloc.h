#include <bits/stdc++.h>
using namespace std;

// function to allocate 2D Array
int **alloc2DArray(int **arr, int row, int col[])
{
    // Dymnamic Allocation of 2D Array
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        // Asking the user for students in each dept.
        int n;
        cout << "Enter number of students in " << (i+1) << "th department\n";
        cin >> n;
        arr[i] = new int[n];
        // Storing the data for number of students in each dept.
        col[i] = n;
    }

    return arr;
}
