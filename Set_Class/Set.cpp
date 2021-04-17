#include "Set.h"
#include <iostream>
#include <algorithm>

using namespace std;

Set::Set(): ptr{nullptr}, size{}
{}

Set::Set(const int *p, int s)
{
    size = s;
    ptr = new int[size];

    for(int i=0; i<s; i++)
        ptr[i] = p[i];
}

Set::Set(const Set &obj)
{
    size = obj.size;
    ptr = new int[size];

    for(int i=0; i<size; i++)
        ptr[i] = *(obj.ptr + i);
}

Set::~Set()
{
    delete[] ptr;
}

void Set::sort_set()
{
    sort(ptr, ptr+size);
}

Set Set::operator+(const Set &obj)
{
    int common{};

    for(int i=0; i<size; i++)               //Check number of common elements
    {
        for(int j=0; j<obj.size; j++)
            if(ptr[i] == *(obj.ptr + j))
            {
                common++;
                break;
            }
    }

    if(common)
    {
        int *t_ptr = new int[size + obj.size - common];

        for(common=0; common < size; common++)
            t_ptr[common] = ptr[common];

        bool flag = true;

        for(int i=0; i<obj.size; i++)
        {
            for(int j=0; j < common; j++)
                if(*(obj.ptr + i) == t_ptr[j])
                {
                    flag = false;
                    break;
                }

            if(flag)
                t_ptr[common++] = *(obj.ptr + i);

            flag = true;
        }

        Set S(t_ptr, common);
        S.sort_set();

        delete[] t_ptr;

        return S;
    }
    else
    {
        int *t_ptr = new int[size + obj.size];
        int c{};

        for(int i=0; i<size; i++)
            t_ptr[c++] = ptr[i];

        for(int i=0; i<obj.size; i++)
            t_ptr[c++] = *(obj.ptr + i);

        Set S(t_ptr, c);
        S.sort_set();

        delete[] t_ptr;

        return S;
    }
}

Set Set::operator-(const Set &obj)
{
    int common{};

    for(int i=0; i<size; i++)           //Check number of common elements
    {
        for(int j=0; j<obj.size; j++)
            if(ptr[i] == *(obj.ptr + j))
            {
                common++;
                break;
            }
    }

    if(common)
    {
        //If *this has no elements left
        if(size == common)
        {
            int ar[] = {0};
            Set S(ar, 1);
            return S;
        }


        int *t_ptr = new int[size - common];

        common = 0;
        bool flag = true;

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<obj.size; j++)
                if(ptr[i] == *(obj.ptr + j))
                {
                    flag = false;
                    break;
                }

            if(flag)
                t_ptr[common++] = ptr[i];

            flag = true;
        }

        Set S(t_ptr, common);
        S.sort_set();

        delete[] t_ptr;

        return S;
    }
    else
    {
        Set S = *this;
        return S;
    }

}

Set Set::operator*(const Set &obj)
{
    int common{};

    for(int i=0; i<size; i++)           //Check number of common elements
    {
        for(int j=0; j<obj.size; j++)
            if(ptr[i] == *(obj.ptr + j))
            {
                common++;
                break;
            }
    }

    if(common)
    {
        int *t_ptr = new int[common];
        int c{};

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<obj.size; j++)
                if(ptr[i] == *(obj.ptr + j))
                {
                    t_ptr[c++] = ptr[i];
                    break;
                }
        }

        Set S(t_ptr, common);
        S.sort_set();

        delete[] t_ptr;

        return S;
    }
    else
    {
        int ar[] = {0};
        Set S(ar, 1);
        return S;
    }
}

Set& Set::operator=(const Set &obj)
{
    if(this != &obj)
    {
        delete[] ptr;
        ptr = nullptr;

        size = obj.size;

        ptr = new int[size];

        for(int i=0; i<size; i++)
            ptr[i] = *(obj.ptr + i);

    }

    return *this;
}

bool Set::operator<(const Set &obj)
{
    bool flag = false;

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<obj.size; j++)
            if(ptr[i] == *(obj.ptr + j))
            {
                flag = true;
                break;
            }
        if(!flag)
        {
            flag = true;
            break;
        }
        else
            flag = false;
    }

    return !flag;
}

bool Set::operator<=(const Set &obj)
{
    return operator<(obj);
}

bool Set::operator>(const Set &obj)
{
    bool flag = false;

    for(int i=0; i<obj.size; i++)
    {
        for(int j=0; j<size; j++)
            if(*(obj.ptr + i) == ptr[j])
            {
                flag = true;
                break;
            }

        if(!flag)
        {
            flag = true;
            break;
        }
        else
            flag = false;
    }

    return !flag;
}

bool Set::operator>=(const Set &obj)
{
    return operator>(obj);
}

bool Set::operator==(const Set &obj)
{
    return operator<(obj) and operator>(obj);
}

bool Set::operator!=(const Set &obj)
{
    return !operator==(obj);
}

ostream &operator<<(ostream &output, Set const&S)
{
    output << "{";
    for(int i=0; i<S.size - 1; i++)
        output << *(S.ptr + i) << " ,";
    output << *(S.ptr + S.size - 1) << "}";

    return output;
}

istream &operator>>(istream &input, Set &S)
{
    cout << "Enter the size of the set: ";    input >> S.size;

    if(S.ptr)
    {
        delete [] S.ptr;
        S.ptr = nullptr;
    }

    S.ptr = new int[S.size];

    cout<<"Enter values for the set without any repetition of elements:\n";

    for(int i=0; i<S.size; i++)
    {
        input >> *(S.ptr + i);
    }

    return input;
}