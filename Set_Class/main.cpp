#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
    Set S1, S2;
    cout << "Enter for set 1" << endl;
    cin >> S1;

    cout << "\nEnter for set 2" << endl;
    cin >> S2;

    Set S3;
    S3 = S1 + S2;
    cout << "\nS1 + S2 = " << S3 << endl;
    S3 = S1 * S2;
    cout << "S1 * S2 = " << S3 << endl;
    S3 = S1 - S2;
    cout << "S1 - S2 = " << S3 << endl;

    cout << "\nRenter the sets again:\n";
    cout << "S1:\n";
    cin >> S1;
    cout << "S2:\n";
    cin >> S2;

    cout << "\nS1 < S2 -> " << boolalpha << (S1 < S2) << endl;
    cout << "S1 <= S2 -> " << boolalpha << (S1 <= S2) << endl;
    cout << "S1 > S2 -> " << boolalpha << (S1 > S2) << endl;
    cout << "S1 >= S2 -> " << boolalpha << (S1 >= S2) << endl;

    cout << "\nS1 == S2 -> " << boolalpha << (S1 == S2) << endl;
    cout << "S1 != S2 -> " << boolalpha << (S1 != S2) << endl;

    return 0;
}