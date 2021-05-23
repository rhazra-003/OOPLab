//
// Created by SUBHADEEP DUTTA on 17-02-2021.
//

#ifndef PROJ1_MYSTACK_H
#define PROJ1_MYSTACK_H


template<typename T=int>
class myStack {
    T *ptr;
    int size, top;

public:
    myStack();                  // explicit default constructor
    myStack(int n);             // parameterised constructor
    ~myStack();                 // explicit destructor
    void push(T);             // stack push method
    void pop();                 // stack pop method
    void display() const;             // stack display method
    bool isempty() const;       // check for empty stack
    bool isfull() const;        // check for full stack


};


#endif //PROJ1_MYSTACK_H
