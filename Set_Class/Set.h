#ifndef PROJ1_SET_H
#define PROJ1_SET_H
#include <iostream>

class Set {
    int* ptr;
    int size;

public:
    Set();
    Set(const int*, int);
    Set(const Set&);
    ~Set();

    void sort_set();

    Set operator+ (const Set&);
    Set operator- (const Set&);
    Set operator* (const Set&);
    Set &operator= (const Set&);

    bool operator< (const Set&);
    bool operator<= (const Set&);
    bool operator> (const Set&);
    bool operator>= (const Set&);

    bool operator== (const Set&);
    bool operator!= (const Set&);

    friend std::ostream &operator<<(std::ostream &output, Set const&);

    friend std::istream &operator>>(std::istream &input, Set&);
};

#endif //PROJ1_SET_H