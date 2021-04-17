#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix M1, M2;

    cout << "Enter for Matrix M1:" << endl;
    cin >> M1 ;
    cout << endl << "M1 = \n" << M1 <<endl;

    cout << "Enter for Matrix M2:" << endl;
    cin >> M2 ;
    cout << endl << "M2 = \n" << M2 << endl;

    Matrix M3;
    M3 = M1 + M2;
    cout << "M1 + M2 =\n" << M3 << endl;
    M3 = M1 - M2;
    cout << "M1- M2 =\n" << M3 <<endl;
    M3 = M1 * M2;
    cout << "M1 * M2 =\n" << M3 << endl;
    M3 = M1 / M2;
    cout << "M1 / M2 =\n" << M3 <<endl;
    M3 = !M1;
    cout << "Inv(M1) =\n" << M3 << endl << endl;

    int r, c;

    cout << "Enter any row for M1: ";   cin >> r;
    cout << "Enter any column for M1: ";    cin >> c;

    pair<int, int> p(r-1, c-1);
    cout << "M1[" << r << "][" << c << "] = " << M1[p];

    return 0;
}