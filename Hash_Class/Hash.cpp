//
// Created by SUBHADEEP DUTTA on 09-03-2021.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "Hash.h"


using namespace std;

template<typename T>
Hash<T>::Hash(unsigned size) {
    tableSize = size;
    arr = new LinkList<T>[size];

    srand(time(nullptr));
}

template<typename T>
Hash<T>::~Hash() {
    for (int i = 0; i < tableSize; i++)
        arr[i].~LinkList();

    delete[] arr;
}

template<typename T>
unsigned Hash<T>::hashFunc(T name) {

    unsigned k = name.length();
    unsigned long h{0};

    for (unsigned i = 0; i < k; i++) {
        unsigned long x = rand();
        h += (x % tableSize) * name[i];
    }

    h = h % tableSize;
    return h;
}

template<typename T>
void Hash<T>::insert(T name, T regNumber) {
    arr[hashFunc(name)].insertBeginning(name, regNumber);
}

template<typename T>
void Hash<T>::display() {
    for (int i = 0; i < tableSize; i++)
        cout << arr[i] << endl;
}

template<typename T>
void Hash<T>::tableLoadDistribution() {

    unsigned totalEntries{};
    for (unsigned i = 0; i < tableSize; i++) {
        totalEntries += arr[i].getSize();
    }

    double mean = static_cast<double>(totalEntries) / tableSize;

    double squareSum = {};

    for (unsigned i = 0; i < tableSize; i++) {
        squareSum += pow(arr[i].getSize() - mean, 2);
    }

    double std = sqrt(squareSum / tableSize);


    cout << "MEAN: " << mean << endl;
    cout << "STANDARD DEVIATION: " << std << endl << endl;
}
