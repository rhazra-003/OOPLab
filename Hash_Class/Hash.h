//
// Created by SUBHADEEP DUTTA on 09-03-2021.
//

#ifndef PROJ1_MYHASHING_H
#define PROJ1_MYHASHING_H

#include "LinkList.h"
#include "LinkList.cpp"


template<typename T>
class Hash {
    LinkList<T> *arr;
    unsigned tableSize;

    unsigned hashFunc(T);      //hash->modular method

public:
    Hash(unsigned);         //parameterized constructor
    ~Hash();           //explicit default destructor
    void insert(T, T);       //insert for modular method
    void display();         //display method
    void tableLoadDistribution();   //shows mean and STD
};


#endif //PROJ1_MYHASHING_H
