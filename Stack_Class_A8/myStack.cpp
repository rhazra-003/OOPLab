//
// Created by SUBHADEEP DUTTA on 17-02-2021.
//
#include <iostream>
#include "myStack.h"

using namespace std;


template<typename T>
myStack<T>::myStack() : myStack<T>(5) {}

template<typename T>
myStack<T>::myStack(int n) {
    size = n;
    top = 0;
    ptr = new T[n];
}

template<typename T>
myStack<T>::~myStack() {
    delete[] ptr;
}

template<typename T>
void myStack<T>::push(T element) {
    if (isfull())
        throw std::string{"STACK OVERFLOW"};

    ptr[top++] = element;
    cout << "ELEMENT PUSHED: " << element << endl;
}

template<typename T>
void myStack<T>::pop() {
    if (isempty())
        throw std::string{"STACK UNDERFLOW"};
    else
        cout << "ELEMENT POPPED: " << ptr[--top] << endl;
}

template<typename T>
void myStack<T>::display() const {
    if (isempty())
        throw std::string{"STACK EMPTY"};
    else {
        for (int i = top - 1; i >= 0; i--)
            cout << "[ " << ptr[i] << " ]" << endl;
    }
}

template<typename T>
bool myStack<T>::isempty() const {
    return top == 0;
}

template<typename T>
bool myStack<T>::isfull() const {
    return top == size;
}