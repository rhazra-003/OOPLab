#include <iostream>
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

using namespace std;

int main() {

    Scissors s1(5);

    Paper p1(7);

    Rock r1(15);

    cout << boolalpha << s1.fight(p1) << " " << p1.fight(s1) << endl;

    cout << boolalpha << p1.fight(r1) << " " << r1.fight(p1) << endl;

    cout << boolalpha << r1.fight(s1) << " " << s1.fight(r1) << endl;

    return 0;

}