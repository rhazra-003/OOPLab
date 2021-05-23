//
// Created by SUBHADEEP DUTTA on 19-05-2021.
//

#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
Node<T>::Node() : Node(0) {}

template<typename T>
Node<T>::Node(T val):data{val}, next{nullptr} {}

template<typename T>
ostream &operator<<(ostream &output, Node<T> *const &N_ptr) {
    if (N_ptr)
        output << N_ptr->data;
    else
        output << "Null Pointer error!";

    return output;
}

template<typename T>
istream &operator>>(istream &input, Node<T> *N_ptr) {
    if (N_ptr) {
        cout << "Enter data: ";
        input >> N_ptr->data;
    } else {
        cout << "Null Pointer error!";
    }

    return input;
}
