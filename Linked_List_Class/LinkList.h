#ifndef PROJ1_LINKLIST_H
#define PROJ1_LINKLIST_H
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    friend std::ostream &operator<<(std::ostream &output, Node* const&);
    friend std::istream &operator>>(std::istream &input, Node* );
};

class LinkList {
    Node *first;
    int size;

public:
    LinkList();
    LinkList(const LinkList&);
    ~LinkList();

    Node* createNode();

    LinkList operator+ (const LinkList&);
    LinkList operator! ();
    LinkList &operator= (const LinkList&);

    bool operator== (const LinkList&) const;

    Node* operator[] (int i) const;

    friend std::ostream &operator<<(std::ostream &output, LinkList const&);
    friend std::istream &operator>>(std::istream &input, LinkList &);
};

#endif //PROJ1_LINKLIST_H