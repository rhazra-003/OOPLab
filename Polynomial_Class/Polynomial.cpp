#include <iostream>
#include <cmath>

using namespace std;

class Node
{
	public:
    	int exponent;
    	int coefficient;
    	Node* next;
};


class myPolynomial 
{

    Node* first;

	public:
    	myPolynomial();
    	~myPolynomial();
    	myPolynomial(const myPolynomial&);
    	Node* createNode();
    	void insertTerm(int, int);
    	void deleteTerm(int);
    	void displayPoly();
    	void evalPoly(int);
    	myPolynomial addPoly(const myPolynomial&);
    	Node * searchTerm(int) const;

};

myPolynomial::myPolynomial()
{
	first=NULL;
}

myPolynomial::~myPolynomial()
{
    Node* current = first;
    Node* next = NULL;

    while(current!= NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }

    first = NULL;
}

myPolynomial::myPolynomial(const myPolynomial& P)
{
	first=NULL;
    Node* trav1 = P.first;
    Node* trav2=NULL;


    while(trav1 != NULL)
    {
        Node* temp = createNode();
        temp->coefficient = trav1->coefficient;
        temp->exponent = trav1->exponent;

        if(first == NULL)
        {
            first = temp;
            trav2 = first;
            trav1 = trav1->next;
            continue;
        }

        trav2->next = temp;
        trav2 = temp;

        trav1 = trav1->next;
    }

}

Node* myPolynomial::createNode()
{
    Node* ptr = new Node;
    ptr->exponent = 0;
    ptr->coefficient = 0;
    ptr->next = NULL;
    return ptr;
}

void myPolynomial::insertTerm(int coefficient, int exponent)
{
    if(searchTerm(exponent))
    {
        Node* ptr = searchTerm(exponent);
        ptr->coefficient += coefficient;
    }
    else if(first == NULL or first->exponent < exponent)
    {
        Node* temp = createNode();
        temp->exponent = exponent;
        temp->coefficient = coefficient;

        temp->next = first;
        first = temp;
    }
    else if(first->exponent > exponent and first->next == NULL)
    {
        Node* temp = createNode();
        temp->exponent = exponent;
        temp->coefficient = coefficient;

        first->next = temp;
    }
    else
    {
        Node* before = first;
        Node* current = first->next;

        while(current->next != NULL)
        {
            if(before->exponent > exponent and current->exponent < exponent)
            {
                Node* temp = createNode();
                temp->exponent = exponent;
                temp->coefficient = coefficient;

                before->next = temp;
                temp->next = current;
                return;
            }

            before = current;
            current = current->next;
        }

        if(current->exponent < exponent)
        {
            Node* temp = createNode();
            temp->exponent = exponent;
            temp->coefficient = coefficient;

            before->next = temp;
            temp->next = current;
        }
        else
        {
            Node* temp = createNode();
            temp->exponent = exponent;
            temp->coefficient = coefficient;

            current->next = temp;
        }
    }
}

void myPolynomial::deleteTerm(int exponent)
{
    if(!searchTerm(exponent))
        cout<<"Term with x^"<<exponent<<" is not found!"<<endl;
    else if(first->exponent == exponent)
    {
        Node* temp = first;
        first = first->next;

        cout<<"DELETED TERM: "<<temp->coefficient<<"x^"<<temp->exponent<<endl;

        delete temp;

    }
    else
    {
        Node* trav = first;

        while(trav != NULL)
        {
            if(trav->next->exponent == exponent)
            {
                Node* temp = trav->next;
                trav->next = trav->next->next;


                cout<<"DELETED TERM: "<<temp->coefficient<<"x^"<<temp->exponent<<endl;
                delete temp;
                break;
            }
            trav = trav->next;
        }
    }
}

void myPolynomial::displayPoly()
{
    if(first == NULL)
        cout<<"0"<<endl;
    else if(first->next == NULL)
    {
        if(first->exponent == 0)
            cout<<first->coefficient<<endl;
        else
        {
            if(first->coefficient == 0)
                return;
            else if(first->coefficient == 1)
                cout<<"x^"<<first->exponent<<endl;
            else
                cout<<first->coefficient<<"x^"<<first->exponent<<endl;
        }
    }
    else
    {
        Node* trav = first;

        while(trav->next != NULL)
        {
            if(trav->coefficient == 0)
            {
                trav = trav->next;
                continue;
            }
            if(trav->coefficient == 1)
                cout<<"x^"<<trav->exponent<<" + ";
            else
                cout<<"("<<trav->coefficient<<")x^"<<trav->exponent<<" + ";
            trav = trav->next;

            if(trav->next == NULL)
            {
                if(trav->exponent == 0)
                    cout<<"("<<trav->coefficient<<")"<<endl;
                else
                {
                    if(trav->coefficient == 0)
                        return;
                    else if(trav->coefficient == 1)
                        cout<<"x^"<<trav->exponent<<endl;
                    else
                        cout<<"("<<trav->coefficient<<")"<<"x^"<<trav->exponent<<endl;
                }

            }
        }
    }
}

void myPolynomial::evalPoly(int x)
{
    if(first == NULL)
        cout<<"0"<<endl;
    else
    {
        long long val;

        Node* trav = first;
        while(trav != NULL)
        {
            val += trav->coefficient * static_cast<long>(pow(x, trav->exponent));
            trav = trav->next;
        }

        cout<<val<<endl;
    }
}

Node* myPolynomial::searchTerm(int exponent) const
{
    Node* trav = first;

    while(trav != NULL)
    {
        if(trav->exponent == exponent)
            return trav;
        trav = trav->next;
    }

    return NULL;
}


myPolynomial myPolynomial::addPoly(const myPolynomial& P)
{
    myPolynomial sum(P);

    Node* trav = first;

    while(trav != NULL)
    {
        sum.insertTerm(trav->coefficient, trav->exponent);
        trav = trav->next;
    }


    return sum;
}

void func1()
{
    myPolynomial P;

    char choice='N';

    do
    {
        int coefficient, exponent;
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial is as follows:\n";
    cout<<"P(x) = ";
    P.displayPoly();
    cout<<endl;
}

void func2()
{
    myPolynomial P1, P2;
    char choice='N';

    cout<<"Enter data for polynomial P1(x):\n";
    do
    {
        int coefficient, exponent;
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P1.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial P1 is as follows:\n";
    cout<<"P1(x) = ";
    P1.displayPoly();
    cout<<endl;


    choice = 'N';
    cout<<"Enter data for polynomial P2(x):\n";
    do
    {
        int coefficient, exponent;
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P2.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial P2 is as follows:\n";
    cout<<"P2(x) = ";
    P2.displayPoly();
    cout<<endl;


    myPolynomial sum=P1.addPoly(P2);

    cout<<"P1(x) + P2(x) = ";
    sum.displayPoly();
    cout<<endl;
}

void func3()
{
    myPolynomial P;

    char choice='N';

    do
    {
        int coefficient, exponent;
        cout<<"Enter the coefficient:";     cin>>coefficient;
        cout<<"Enter the exponent:";        cin>>exponent;
        P.insertTerm(coefficient, exponent);


        cout<<"Do you want to enter more terms?(Y/N):";     cin>>choice;

    }while(choice == 'Y' or choice == 'y');

    cout<<"The polynomial is as follows:\n";
    cout<<"P(x) = ";
    P.displayPoly();
    cout<<endl;

    int x;
    cout<<"Enter the value of x:";    cin>>x;
    cout<<"P("<<x<<") = ";
    P.evalPoly(x);
    cout<<endl;
}

int main()
{
    while(true)
    {
        char choice;
        cout << "\t\tMENU" << endl;
        cout << "1. Enter and display a polynomial\n2. Add two polynomials\n3. Evaluate a polynomial\n4. Quit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case '1':
                func1();
                break;
            case '2':
                func2();
                break;
            case '3':
                func3();
                break;
            case '4':
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid input!!" << endl;
        }
    }
}
