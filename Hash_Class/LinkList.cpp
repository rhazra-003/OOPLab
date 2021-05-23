//
// Created by SUBHADEEP DUTTA on 11-04-2021.
//

#include "LinkList.h"
#include <iostream>

using namespace std;

template<typename T>
LinkList<T>::LinkList(): first{nullptr}, size{0} {}

template<typename T>
LinkList<T>::~LinkList() {
    Node<T> *current = first;
    Node<T> *next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    first = nullptr;
    size = 0;
}


template<typename T>
Node<T> *LinkList<T>::createNode() {
    Node<T> *ptr = new Node<T>;

    ptr->name = "";
    ptr->regNumber = "";
    ptr->next = nullptr;

    return ptr;
}

template<typename T>
void LinkList<T>::insertBeginning(T name, T regNumber) {

    if (first) {
        Node<T> *temp = createNode();
        temp->name = name;
        temp->regNumber = regNumber;
        temp->next = first;
        first = temp;

        size++;
    } else {
        first = createNode();
        first->name = name;
        first->regNumber = regNumber;

        size++;
    }
}

template<typename T>
unsigned LinkList<T>::getSize() {
    return size;
}

template<typename T>
ostream &operator<<(ostream &output, LinkList<T> const &L) {
    Node<T> *trav = L.first;

    if (trav) {
        while (trav->next) {
            output << "[" << trav->name << ", " << trav->regNumber << " ] --> ";
            trav = trav->next;
        }

        output << "[" << trav->name << ", " << trav->regNumber << " ]";

        return output;
    } else {
        output << "[ NULL ]";
        return output;
    }

}