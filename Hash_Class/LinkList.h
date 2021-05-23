//
// Created by SUBHADEEP DUTTA on 11-04-2021.
//

#ifndef PROJ1_LINKLIST_H
#define PROJ1_LINKLIST_H

#include <iostream>

template<class T>
class Node {
public:
    std::string name;
    std::string regNumber;
    Node<T> *next;
};

template<class T>
class LinkList {
    Node<T> *first;
    unsigned size;

public:
    LinkList();
    ~LinkList();

    Node<T> *createNode();
    void insertBeginning(T, T);
    unsigned getSize();

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, LinkList<U> const &);
};


#endif //PROJ1_LINKLIST_H
