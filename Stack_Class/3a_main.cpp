/* C++ program to implement basic stack
operations */

#include <bits/stdc++.h>

using namespace std;

class Stack
{
    int top;
    int *a;
    int max;

public:
    Stack(int size)
    {
        a = new int[size];
        max = size;
        top = -1;
    }
    ~Stack()
    {
        delete[] a;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isempty();
    bool isfull();
};

bool Stack::isempty()
{
    return (top < 0);
}

bool Stack::isfull()
{
    return (top >= max);
}

bool Stack::push(int x)
{
    if (isfull())
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into the Stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (isempty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack::peek()
{
    if (isempty())
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}


int main()
{
    cout << "Enter Stack size: ";
    int size;
    cin >> size;
    class Stack s(size);
    s.push(5);
    s.push(8);
    s.push(6);
    cout << s.pop() << " popped from the Stack\n";
    cout << s.peek() << " is at the top of the Stack\n";

    s.~Stack();
    cout << "\n\nStack is deallocated\n";

    return 0;
}