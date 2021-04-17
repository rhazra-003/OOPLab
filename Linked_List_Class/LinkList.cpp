#include "LinkList.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &output, Node* const &N_ptr)
{
    if(N_ptr)
        output << N_ptr->data;
    else
        output << "Null Pointer error!";

    return output;
}

istream &operator>>(istream &input, Node* N_ptr)
{
    if(N_ptr)
    {
        cout<<"Enter data: ";
        input >> N_ptr->data;
    }
    else
    {
        cout<<"Null Pointer error!";
    }

    return input;
}

LinkList::LinkList(): first{nullptr}, size{0}
{}

LinkList::LinkList(const LinkList &obj)
{
    size = obj.size;

    first = createNode();
    Node *temp1 = first, *temp2 = obj.first;

    while(temp2)
    {
        temp1->data = temp2->data;

        temp2 = temp2->next;

        if(temp2)
        {
            temp1->next = createNode();
            temp1 = temp1->next;
        }
    }
}

LinkList::~LinkList()
{
    Node* current = first;
    Node* next;

    while(current!= nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    first = nullptr;
    size = 0;
}

Node* LinkList::createNode()
{
    Node *ptr = new Node;

    ptr->data = 0;
    ptr->next = nullptr;

    return ptr;
}

LinkList LinkList::operator+(const LinkList &obj)
{
    LinkList L;

    Node *temp1 = createNode(), *temp2 = first;

    L.first = temp1;
    L.size = size + obj.size;

    while(temp2)
    {
        temp1->data = temp2->data;

        temp1->next = createNode();
        temp1 = temp1->next;

        temp2 = temp2->next;
    }

    temp2 = obj.first;

    while(temp2)
    {
        temp1->data = temp2->data;

        temp2 = temp2->next;

        if(temp2)
        {
            temp1->next = createNode();
            temp1 = temp1->next;
        }
    }

    return L;
}

LinkList LinkList::operator!()
{
    LinkList L(*this);

    Node *current = L.first;
    Node *prev = nullptr, *next;

    while(current)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    L.first = prev;

    return L;
}

LinkList& LinkList::operator    =(const LinkList &obj)
{
    if(this != &obj)
    {
        if(!first)                          // Deallocating an existing LL
        {
            Node *current = first;
            Node *next;

            while(current!= nullptr)
            {
                next = current->next;
                delete current;
                current = next;
            }

            first = nullptr;
            size = 0;
        }

        size = obj.size;

        first = createNode();
        Node *temp1 = first, *temp2 = obj.first;

        while(temp2)
        {
            temp1->data = temp2->data;

            temp2 = temp2->next;

            if(temp2)
            {
                temp1->next = createNode();
                temp1 = temp1->next;
            }
        }
    }

    return *this;
}

bool LinkList::operator==(const LinkList &obj) const
{
    if(size == obj.size)
    {
        Node *trav1 = first, *trav2 = obj.first;

        while(trav1)
        {
            if(trav1->data != trav2->data)
                return false;

            trav1 = trav1->next;
            trav2 = trav2->next;
        }

        return true;
    }
    else
        return false;
}

Node* LinkList::operator[](int i) const
{
    if(i >= size or i < -size)
    {
        cout << "Array index out of bounds" << endl;
        return nullptr;
    }
    else
    {
        int index{};
        Node* trav = first;

        if(i < 0)                   // For negative indexing
            i = size + i;

        while(index != i)
        {
            trav = trav->next;
            index++;
        }

        return trav;
    }
}

ostream &operator<<(ostream &output, LinkList const &L)
{
    Node *trav = L.first;

    output << "[ ";
    while(trav->next)
    {
        output << trav->data << "-->";
        trav = trav->next;
    }

    output << trav->data << " ]";

    return output;
}

istream &operator>>(istream &input, LinkList &L)
{
    int e{};
    cout << "Enter the element: ";   input >> e;

    if(L.first)
    {
        Node* trav = L.first;

        while(trav->next)
            trav = trav->next;

        trav->next = L.createNode();

        trav->next->data = e;

        L.size++;
    }
    else
    {
        L.first = L.createNode();
        L.first->data = e;

        L.size++;
    }

    return input;
}