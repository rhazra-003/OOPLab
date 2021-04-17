#include "Fraction.h"
#include <iostream>
#include <algorithm>

using namespace std;

Fraction::Fraction(): Fraction(0, 1)
{}

Fraction::Fraction(int n, int d): num{n}, den{d}
{
    if(den == 0)
    {
        cout << "Denominator cannot be ZERO!" << endl;
        den = 1;
        num = 0;
    }

    val = static_cast<float>(num) / static_cast<float>(den);
}



Fraction Fraction::operator+(const Fraction &obj) const
{
    Fraction F;

    F.den = (den * obj.den) / __gcd(den, obj.den);
    F.num = (F.den/den) * num + (F.den/obj.den) * obj.num;

    F.val = val + obj.val;

    return F;
}

Fraction Fraction::operator-(const Fraction &obj) const
{
    Fraction F;

    F.den = (den * obj.den) / __gcd(den, obj.den);
    F.num = (F.den/den) * num - (F.den/obj.den) * obj.num;

    F.val = val - obj.val;

    return F;

}

Fraction Fraction::operator*(const Fraction &obj) const
{
    Fraction F;

    F.num = num * obj.num;
    F.den = den * obj.den;

    F.val = val * obj.val;

    return F;
}

Fraction Fraction::operator/(const Fraction &obj) const
{
    Fraction F;

    F.num = num * obj.den;
    F.den = den * obj.num;

    F.val = val / obj.val;

    return F;
}

Fraction Fraction::operator*() const
{
    Fraction F;

    F.num = num / __gcd(num, den);
    F.den = den / __gcd(num, den);

    return F;
}



bool Fraction::operator==(const Fraction &obj) const
{
    int lcm = (den * obj.den) / __gcd(den, obj.den);

    int num_this = (lcm / den) * num;
    int num_obj = (lcm / obj.den) * obj.num;

    return num_this == num_obj;
}

bool Fraction::operator!=(const Fraction &obj) const
{
    return !(operator==(obj));
}

bool Fraction::operator<(const Fraction &obj) const
{
    int lcm = (den * obj.den) / __gcd(den, obj.den);

    int num_this = (lcm / den) * num;
    int num_obj = (lcm / obj.den) * obj.num;

    return num_this < num_obj;
}

bool Fraction::operator>(const Fraction &obj) const
{
    return !(operator<(obj));
}



Fraction &Fraction::operator=(const Fraction &obj)
{
    if(this != &obj)
    {
        num = obj.num;
        den = obj.den;
        val = obj.val;
    }

    return *this;
}

int Fraction::operator[](int i) const
{
    if(i == 0)
        return num;
    else
        return den;
}



ostream &operator<<(ostream &output, const Fraction &F)
{
    if(F.den == 1)
        output << F.num;
    else
        output << F.num << "/" << F.den;

    return output;
}

istream &operator>>(istream &input, Fraction &obj)
{
    cout << "Enter numerator: " ;  input >> obj.num;
    cout << "Enter denominator: ";  input >> obj.den;

    return input;
}