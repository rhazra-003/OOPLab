#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;

int main() {
    int s1{}, s2{};

    LinkList<int> L1, Li;
    cout << "Enter size of LL-1:";
    cin >> s1;

    cout << "Enter integer values for LL-1:\n";
    for (int i = 0; i < s1; i++)
        cin >> L1;

    cout << "L1:\n" << L1 << endl;

    int integer{};
    cout << "Enter a integer to delete from LL-1:";
    cin >> integer;

    Li = L1 - integer;

    cout << "\nDisplaying L-int using [] operator:\n";

    for (int i = 0; i < s1 - 1; i++)
        cout << Li[i] << endl;


    LinkList<char> L2, Lc;
    cout << "\nEnter size of LL-2:";
    cin >> s2;

    cout << "Enter character values for LL-2:\n";
    for (int i = 0; i < s2; i++)
        cin >> L2;

    cout << "L2:\n" << L2 << endl;

    char character{};
    cout << "Enter a character to delete from LL-2:";
    cin >> character;

    Lc = L2 - character;

    cout << "\nDisplaying L-char using [] operator:\n";

    for (int i = 0; i < s2 - 1; i++)
        cout << Lc[i] << endl;

    return 0;
}
