#ifndef PROJ1_FRACTION_H
#define PROJ1_FRACTION_H

#include <iostream>


class Fraction {
    int num, den;
    float val;

public:
    Fraction();
    Fraction(int, int);

    Fraction operator+ (const Fraction&) const;
    Fraction operator- (const Fraction&) const;
    Fraction operator* (const Fraction&) const;
    Fraction operator/ (const Fraction&) const;
    Fraction operator* () const;

    bool operator== (const Fraction&) const;
    bool operator!= (const Fraction&) const;
    bool operator< (const Fraction&) const;
    bool operator> (const Fraction&) const;

    Fraction &operator= (const Fraction&);
    int operator[] (int i) const;

    friend std::ostream &operator<<(std::ostream &output, const Fraction&);
    friend std::istream &operator>>(std::istream &input, Fraction &);
};


#endif //PROJ1_FRACTION_H
