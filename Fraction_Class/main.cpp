#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction A;

    cout << "Enter a fraction:\n";
    cin >> A;
    cout << "A = " << A << " = " << A.frac_val() << endl;


    cout << "\nEnter another fraction:\n";
    int n, d;
    cout << "Enter numerator: ";    cin >> n;
    cout << "Enter denominator: ";  cin>>d;
    Fraction B(n, d);
    cout << "B = " << B << " = " << B.frac_val() << endl;

    Fraction C;

    C = A + B;
    cout << "\nA + B = " << C << " = " << C.frac_val() << endl;
    C = A - B;
    cout << "A - B = " << C << " = " << C.frac_val() << endl;
    C = A * B;
    cout << "A * B = " << C << " = " << C.frac_val() << endl;
    C = A / B;
    cout << "A / B = " << C << " = " << C.frac_val() << endl;

    cout << "\nEnter again another fraction:\n";
    cin >> C;
    cout << "Normalized result = " << *C << endl;

    cout << "\nA == B -> " << boolalpha << (A == B) << endl;
    cout << "A != B -> " << boolalpha << (A != B) << endl;
    cout << "A < B -> " << boolalpha << (A < B) << endl;
    cout << "A > B -> " << boolalpha << (A > B) << endl;

    cout << "\nNumerator of fraction A is: " << A[0] << endl;
    cout << "Denominator of fraction A is: " << A[1] << endl;

    cout << "\nNumerator of fraction B is: " << B[0] << endl;
    cout << "Denominator of fraction B is: " << B[1] << endl;

    return 0;
}