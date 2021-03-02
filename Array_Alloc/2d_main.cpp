#include <bits/stdc++.h>
#include "array_alloc.h"
using namespace std;

struct Maxmarks
{
    int *dept_topper;
    int batch_topper;
};

// Function declaration
void display(int **arr, int row, int col[], struct Maxmarks pair);

// To input random values in the 2D array
void random_number_generator(int **arr, int row, int col[])
{
    cout << "Using random number generator(Linear Congruential Method) for getting values\n\n";
    int x, a, c, m;
    cout << "Enter seed value(X0) :- ";
    cin >> x;
    cout << "Enter the multiplier(a) :- ";
    cin >> a;
    cout << "Enter the increment(c) :- ";
    cin >> c;
    cout << "Enter the modulus(m) :- ";
    cin >> m;

    // Storing default values to each element
    struct Maxmarks pair;

    pair.dept_topper = new int[row];
    for (int i = 0; i < row; i++)
        pair.dept_topper[i] = INT_MIN;

    pair.batch_topper = INT_MIN;

    // Entering values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            x = (a * x + c) % m;
            arr[i][j] = x;

            // Storing max of each dept
            if (arr[i][j] > pair.dept_topper[i])
                pair.dept_topper[i] = arr[i][j];
        }
        // Storing max of the whole batch
        if (pair.dept_topper[i] > pair.batch_topper)
            pair.batch_topper = pair.dept_topper[i];
    }

    // Displaying the contents of the database and toppers
    display(arr, row, col, pair);
}

void display(int **arr, int row, int col[], struct Maxmarks pair)
{
    // Displaying the data
    for (int i = 0; i < row; i++)
    {
        cout << "The marks of students in " << (i + 1) << "th department are :- \n";
        for (int j = 0; j < col[i]; j++)
            cout << arr[i][j] << " ";

        cout << "\nMaximum marks obtained in " << (i + 1) << "th dept :- " << pair.dept_topper[i];
        cout << "\n\n\n";
    }
}

int main()
{
    int **arr, row;
    cout << "Enter number of departments :- ";
    cin >> row;

    int col[row];
    arr = alloc2DArray(arr, row, col);

    random_number_generator(arr, row, col);

    return 0;
}


