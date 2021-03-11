#include <iostream>

using namespace std;

class Node	
{
	public:
    	int data;
    	Node* next;
};

class List	
{
	public:
    	void construct();
    	void deconstruct();
    	void displayList();
		int countNode();
    	void insertNode(int);
    	void deleteNode(int);    	
    	int searchList(int);
    	
	private:
    	Node* head;
};

void List::construct()	
{
	this->head=NULL;
}

void List::deconstruct()	
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

int List::countNode()	
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

void List::displayList()	
{
    Node* temp = head;
    while (temp != NULL) 
	{
    	cout<<temp->data<<"-->";
    	temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void List::insertNode(int val)	
{    
    Node* newnode=new Node();  
    newnode->data=val;  
    newnode->next=head;
    head=newnode;  
}	

void List::deleteNode(int key)	
{
    Node* temp=head;
    Node* prev=NULL;
     
    if (temp!=NULL && temp->data==key)
    {
        head=temp->next;
        delete temp;
        return;
    }

    else
    {
    	while (temp!= NULL && temp->data!=key)
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

int List::searchList(int key)	 
{  
    Node* current = head; 
    int pos=1;
    while (current != NULL)  
    {  
        if (current->data == key)  
        {
        	return pos;
		}  
        current = current->next;
        pos++;
    }  
    return -1;  
}
