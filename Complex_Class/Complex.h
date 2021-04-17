#ifndef PROJ1_COMPLEX_H
#define PROJ1_COMPLEX_H

#include <iostream>

class Complex {
    float x;
    float y;

public:
    Complex();
    Complex(float, float);

    Complex operator+ (const Complex&) const;
    Complex operator- (const Complex&) const;
    Complex operator* (const Complex&) const;
    Complex operator/ (const Complex&) const;
    Complex operator! () const;

    bool operator== (const Complex&) const;
    bool operator!= (const Complex&) const;

    Complex &operator= (const Complex&);
    float operator[] (int i) const;

    friend std::ostream &operator<<(std::ostream &output, Complex const&);
    friend std::istream &operator>>(std::istream &input, Complex &);

};

#endif //PROJ1_COMPLEX_H