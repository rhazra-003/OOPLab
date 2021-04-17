#include "Complex.h"
#include <iostream>
#include <iomanip>

using namespace std;

Complex::Complex(): Complex(0, 0)
{}

Complex::Complex(float x, float y): x{x}, y{y}
{}

Complex Complex::operator+(const Complex &obj) const
{
    Complex z;

    z.x = x + obj.x;
    z.y = y + obj.y;

    return z;
}

Complex Complex::operator-(const Complex &obj) const
{
    Complex z;

    z.x = x - obj.x;
    z.y = y - obj.y;

    return z;
}

Complex Complex::operator*(const Complex &obj) const
{
    Complex z;

    z.x = x*obj.x - y*obj.y;
    z.y = x*obj.y + y*obj.x;

    return z;
}

Complex Complex::operator/(const Complex &obj) const
{
    Complex z;

    z.x = x*obj.x + y*obj.y;
    z.y = y*obj.x - x*obj.y;

    float mod_obj = obj.x*obj.x + obj.y*obj.y;

    z.x = z.x / mod_obj;
    z.y = z.y / mod_obj;


    return z;
}

Complex Complex::operator!() const
{
    Complex z;
    z.x = x;
    z.y = -y;

    return z;
}

bool Complex::operator==(const Complex &obj) const
{
    return (x == obj.x) and (y == obj.y);
}

bool Complex::operator!=(const Complex &obj) const
{
    return !(this->operator==(obj));
}


Complex &Complex::operator=(const Complex &obj)
{
    if(this != &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    return *this;
}

float Complex::operator[](int i) const
{
    if(i)
        return y;
    else
        return x;
}



ostream &operator<<(ostream &output, Complex const &z)
{

    if(z.x == 0)
    {
        if(z.y == 0)
            output << "0";
        else if (z.y == 1)
            output << "i";
        else if (z.y == -1)
            output << "-i";
        else
            output << fixed << setprecision(2) << z.y << "i";
    }
    else if(abs(z.y) == 1 or z.y == 0)
    {
        if (z.y == 1)
            output << fixed << setprecision(2) << z.x << "+i";
        else if (z.y == -1)
            output << fixed << setprecision(2) << z.x << "-i";
        else
            output << fixed << setprecision(2) << z.x;
    }
    else
    {
        if(z.y < 0)
            output << fixed << setprecision(2) << z.x << z.y << "i";
        else
            output << fixed << setprecision(2) << z.x << "+" << z.y << "i";
    }

    return output;
}

istream &operator>>(istream &input, Complex &z)
{
    cout << "Enter real part: ";    input >> z.x;
    cout << "Enter imaginary part: ";   input >> z.y;

    return input;
}