//
// Created by SUBHADEEP DUTTA on 11-04-2021.
//

#ifndef PROJ1_LINKLIST_H
#define PROJ1_LINKLIST_H

#include <iostream>

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, Node<U> *const &);

    template<typename U>
    friend std::istream &operator>>(std::istream &input, Node<U> *);
};

template<class T>
class LinkList {
    Node<T> *first;
    int size;

public:
    LinkList();
    LinkList(const LinkList<T> &);
    ~LinkList();

    Node<T> *createNode();
    Node<T> *search(T);

    LinkList operator+(const LinkList<T> &);
    LinkList operator-(T);
    LinkList &operator=(const LinkList<T> &);


    Node<T> *operator[](int i) const;

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, LinkList<U> const &);

    template<typename U>
    friend std::istream &operator>>(std::istream &input, LinkList<U> &);
};


#endif //PROJ1_LINKLIST_H
