//
// Created by SUBHADEEP DUTTA on 11-04-2021.
//

#include "LinkList.h"
#include <iostream>


using namespace std;

// Node Class

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



// LinkList Class

template<typename T>
LinkList<T>::LinkList(): first{nullptr}, size{0} {}

template<typename T>
LinkList<T>::LinkList(const LinkList<T> &obj) {
    size = obj.size;

    first = createNode();
    Node<T> *temp1 = first, *temp2 = obj.first;

    while (temp2) {
        temp1->data = temp2->data;

        temp2 = temp2->next;

        if (temp2) {
            temp1->next = createNode();
            temp1 = temp1->next;
        }
    }
}

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

    ptr->data = 0;
    ptr->next = nullptr;

    return ptr;
}

template<typename T>
Node<T> *LinkList<T>::search(T element) {
    if (first == nullptr)
        return nullptr;
    else {
        Node<T> *trav = first;

        if (trav->data == element)
            return trav;

        while (trav->next) {
            if (trav->next->data == element)
                return trav;
            trav = trav->next;
        }

        return nullptr;
    }
}


template<typename T>
LinkList<T> LinkList<T>::operator+(const LinkList<T> &obj) {
    LinkList<T> L;

    Node<T> *temp1 = createNode(), *temp2 = first;

    L.first = temp1;
    L.size = size + obj.size;

    while (temp2) {
        temp1->data = temp2->data;

        temp1->next = createNode();
        temp1 = temp1->next;

        temp2 = temp2->next;
    }

    temp2 = obj.first;

    while (temp2) {
        temp1->data = temp2->data;

        temp2 = temp2->next;

        if (temp2) {
            temp1->next = createNode();
            temp1 = temp1->next;
        }
    }

    return L;
}

template<typename T>
LinkList<T> LinkList<T>::operator-(T element) {
    LinkList<T> L(*this);
    Node<T> *ptr = L.search(element);

    if (ptr) {
        if (ptr == L.first) {
            L.first = ptr->next;
            delete ptr;
            return L;
        }

        Node<T> *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }

    return L;
}


template<typename T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &obj) {
    if (this != &obj) {
        if (!first)                          // Deallocating an existing LL
        {
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


        size = obj.size;

        first = createNode();
        Node<T> *temp1 = first, *temp2 = obj.first;

        while (temp2) {
            temp1->data = temp2->data;

            temp2 = temp2->next;

            if (temp2) {
                temp1->next = createNode();
                temp1 = temp1->next;
            }
        }
    }

    return *this;
}


template<typename T>
Node<T> *LinkList<T>::operator[](int i) const {
    if (i >= size or i < -size) {
        cout << "Array index out of bounds" << endl;
        return nullptr;
    } else {
        int index{};
        Node<T> *trav = first;

        if (i < 0)                   // For negative indexing
            i = size + i;

        while (index != i) {
            trav = trav->next;
            index++;
        }

        return trav;
    }
}


template<typename T>
ostream &operator<<(ostream &output, LinkList<T> const &L) {
    Node<T> *trav = L.first;

    output << "[ ";
    while (trav->next) {
        output << trav->data << "-->";
        trav = trav->next;
    }

    output << trav->data << " ]";

    return output;
}

template<typename T>
istream &operator>>(istream &input, LinkList<T> &L) {
    T e{};
    cout << "Enter the element:";
    input >> e;

    if (L.first) {
        Node<T> *trav = L.first;

        while (trav->next)
            trav = trav->next;

        trav->next = L.createNode();

        trav->next->data = e;

        L.size++;
    } else {
        L.first = L.createNode();
        L.first->data = e;

        L.size++;
    }

    return input;
}