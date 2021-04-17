#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex z1, z2, z3;

    cout << "Enter a complex number:\n";
    cin >> z1;
    cout << "z1 = " << z1 << endl;

    cout << "\nEnter another complex number:\n";
    cin >> z2;
    cout << "z2 = " << z2 << endl;

    z3 = z1 + z2;
    cout << "\nz1 + z2 = " << z3 << endl;

    z3 = z1 - z2;
    cout << "z1 - z2 = " << z3 << endl;

    z3 = z1 * z2;
    cout << "z1 * z2 = " << z3 << endl;

    z3 = z1 / z2;
    cout << "z1 / z2 = " << z3 << endl;

    z3 = !z1;
    cout << "z3 = conj(z1) = " << z3 << endl;

    cout << "\nz1 == z2 -> " << boolalpha << (z1 == z2) << endl;
    cout << "z1 != z2 -> " << boolalpha << (z1 != z2) << endl;

    cout << "\nRe(z1): " << z1[0] <<"\nIm(z1): " << z1[1] << endl;
    cout << "\nRe(z2): " << z2[0] <<"\nIm(z2): " << z2[1] << endl;

    return 0;
}