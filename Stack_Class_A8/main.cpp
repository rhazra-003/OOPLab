#include <iostream>
#include "myStack.h"
#include "myStack.cpp"

using namespace std;

template<typename T=int>
void pushElement(myStack<T> &S) {

    T element{};
    cout << "Enter the element:";
    cin >> element;

    try {
        S.push(element);
    }
    catch (string &ex) {
        cerr << ex << endl;
    }
}

template<typename T=int>
void popElement(myStack<T> &S) {

    try {
        S.pop();
    }
    catch (string &ex) {
        cerr << ex << endl;
    }
}


template<typename T=int>
void displayStack(const myStack<T> &S) {

    try {
        S.display();
    }
    catch (string &ex) {
        cerr << ex << endl;
    }
}

int main() {

    int size{};
    while (true) {
        try {
            cout << "\nEnter the size of stack:";
            cin >> size;
            if (size <= 0)
                throw std::string{"Stack size invalid"};
        }
        catch (string &ex) {
            cerr << ex << "\n\n";
            continue;
        }
        break;
    }

    myStack S(size);
//    myStack<float> S(size);
//    myStack<char> S(size);

    while (true) {
        int choice{};

        cout << "\n\t\tMENU\n";
        cout << "1. Push element\n2. Pop element\n3. Display Stack\n4. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                pushElement(S);
                break;
            case 2:
                popElement(S);
                break;
            case 3:
                displayStack(S);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

    }
}