#include <iostream>
#include "LinkList.h"

using namespace std;

int main()
{
    int s1{}, s2{};
    LinkList L1, L2;
    cout << "Enter for LinkList 1:\n";
    cout << "Enter size of LL: ";   cin >> s1;

    for(int i=0; i<s1; i++)
        cin >> L1;

    cout << "L1:\n" << L1 << endl;

    cout << "\nEnter for LinkList 2:\n";
    cout << "Enter size of LL: ";   cin >> s2;

    for(int i=0; i<s2; i++)
        cin >> L2;

    cout << "L2:\n" << L2 <<endl;

    LinkList L3;
    L3 = L1 + L2;
    cout << "\nL1 + L2 = " << L3 << endl;
    L3 = !L1;
    cout << "!L1 = " << L3 << endl;

    cout << "\nL1 == L2 -> " << boolalpha << (L1 == L2) << endl;

    cout << "\nDisplaying L1 using [] operator:\n";

    for(int i=0; i<s1; i++)
        cout << L1[i] << endl;

    return 0;
}
