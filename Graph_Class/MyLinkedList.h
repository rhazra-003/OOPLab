#include <iostream>

using namespace std;

class Node	//defining structure of a Node, with integer vert and pointer to next node
{
	public:
    	int vert;
    	int weight;
    	Node* next;
};

class List	//defining structure of a Linked List, with a head Node and the appropriate functions
{
	public:
    	void construct();
    	void deconstruct();
    	void display();
		int count();
    	void insert(int,int);
    	void delet(int);    	
    	int search(int);
    	
	private:
    	Node* head;
};

void List::construct()	//to create a new Linked List
{
	this->head=NULL;
}

void List::deconstruct()	//to delete a pre-existing Linked List
{
	if (head == NULL) 
	{
        return;
    }
    
    else
    {
    	Node* current= head;
    	Node* next=NULL;
 
    	while (current != NULL) 
    	{
    	    next=current->next;
    	    delete current;
   			current = next;
    	}
 
    	head=NULL;
	}
}

int List::count()	//to count the number of nodes of a Linked List
{

    int n=0;
    Node* temp = head;
    while (temp != NULL) 
	{
        n++;
        temp=temp->next;
    }
	return n;
}

void List::display()	//to display the contents of a Linked List
{
    Node* temp = head;
    while (temp != NULL) 
	{
    	cout<<"-----Adjacent vertex is "<<temp->vert<<", weight of edge is "<<temp->weight<<"-----";
    	cout<<endl;
    	temp=temp->next;
    }
}

void List::insert(int vert, int weight)	//to insert a new value at the beginning of a Linked List
{    
    Node* newnode=new Node();  
    newnode->vert=vert;
	newnode->weight=weight;  
    newnode->next=head;
    head=newnode;  
}	

void List::delet(int key)	//to search and delete a value from a Linked List
{
    Node* temp=head;
    Node* prev=NULL;
     
    if (temp!=NULL && temp->vert==key)
    {
        head=temp->next;
        delete temp;
        return;
    }

    else
    {
    	while (temp!= NULL && temp->vert!=key)
    	{
        	prev = temp;
        	temp = temp->next;
    	}

    	if (temp==NULL)
        {
        	return;
		}
 
    	prev->next = temp->next;
    	delete temp;
    }
}

int List::search(int key)	//to search for a given key in a linked list and return weight if found, 0 if not found 
{  
    Node* current = head; 
    while (current != NULL)  
    {  
        if (current->vert == key)  
        {
        	return current->weight;
		}  
        current = current->next;
    }  
    return 0;  
}
