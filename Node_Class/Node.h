//
// Created by SUBHADEEP DUTTA on 19-05-2021.
//

#ifndef PROJ1_NODE_H
#define PROJ1_NODE_H

#include <iostream>

template<class T = int>
class Node {
public:
    T data;
    Node<T> *next;

    Node();
    Node(T);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, Node<U> *const &);

    template<typename U>
    friend std::istream &operator>>(std::istream &input, Node<U> *);
};


#endif //PROJ1_NODE_H
