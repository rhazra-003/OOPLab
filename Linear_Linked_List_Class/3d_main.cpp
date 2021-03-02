#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
	int data;
	node *next;
};

class linearlinkedlist
{
	private:
			node *head,*tail;
	public:
			linearlinkedlist();
			~linearlinkedlist();
			int insertBeg(int);
			void display();
			void concatenate(node*,node*);
			node* gethead();
			int search(int,node*);
			void deletekey(node*,int);
};

linearlinkedlist::linearlinkedlist()
{
	head=NULL;
	tail=NULL;
}

linearlinkedlist::~linearlinkedlist()
{
	node*ptr;
	for(ptr=head;head;ptr=head)
	{
		head=head->next;
		delete ptr;
	}
}

node* linearlinkedlist::gethead()
{
	return head;
}

int linearlinkedlist::insertBeg(int x)
{
	node*temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=tail->next;
	}
	return x;
}

int linearlinkedlist::search(int z,node*l1)
{
	int i=0,flag;
	node*ptr=new node;
	ptr=l1;
	if(ptr==NULL)
	{
		cout<<"Empty list"<<endl;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==z)
			{
				cout<<"Item found at location "<<i+1<<endl;
				flag=0;
			}
			else
			{
				flag=1;
			}
			i++;
			ptr=ptr->next;
		}
		if(flag==1)	
		{
			cout<<"Item not found"<<endl;
		}
	}
	return 0;
}

void linearlinkedlist::display()
{
	node*ptr=new node;
	ptr=head;
	cout<<"Linked list elements are"<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
}

void linearlinkedlist::concatenate(node*l1,node*l2)
{
	if(l1!=NULL && l2!=NULL)
	{
		if(l1->next==NULL)
			l1->next=l2;
		else
			concatenate(l1->next,l2);
	}
	else
		cout<<"Either l1 or l2 is NULL"<<endl;
}

void linearlinkedlist::deletekey(node*l1,int key)
{
	node*temp=new node;
	node*curr=new node;
	node*prev=new node;
	if(l1==NULL)
	{
		cout<<"No keys to delete"<<endl;
	}
	prev=curr=l1;
	while((curr!=NULL)&&(curr->data!=key))
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		cout<<"Key not found"<<endl;
		return;
	}
	if(curr==head)
	{
		head=head->next;
		cout<<"Required key deleted"<<endl;
	}
	else
	{
		prev->next=curr->next;
		if(curr->next==NULL)
		{
			temp=prev;
		}
	cout<<"Key deleted"<<endl;
	}
	delete(curr);
}

int main()
{
	linearlinkedlist l1;
	linearlinkedlist l2;
	int choice,n,temp,tmp,y;
	do
	{
		cout<<"0-EXIT"<<endl;
		cout<<"1-Concatenate"<<endl;
		cout<<"2-Display"<<endl;
		cout<<"3-Searching"<<endl;
		cout<<"4-Deleting certain node"<<endl;
		cout<<"5-Insertion at end"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
		
			case 0:break;

			case 1:
					l1.concatenate(l1.gethead(),l2.gethead());
					break;

			case 2:
					l1.display();
					break;

			case 3:
					cout<<"Enter element you want to search: "<<endl;
					cin>>y;
					l1.search(y,l1.gethead());
					break;	
			
			case 4:
					cout<<"Enter key to be deleted "<<endl;
					int z;
					cin>>z;
					l1.deletekey(l1.gethead(),z);
					break;
			
			case 5:
					cout<<"Enter element to be inserted in l1: "<<endl;
					srand(time(NULL));
					int n=rand()%10+1;
					temp=l1.insertBeg(n);
					cout<<"Inserted data at begining of l1 is "<<temp<<endl;
					cout<<"Enter element to be inserted in l2"<<endl;
					srand(time(NULL));
					int m=rand()%5+1;
					tmp=l2.insertBeg(m);
					cout<<"Inserted data at begining of l2 is "<<tmp<<endl;
					break;
		}
	}
	while(choice!=0);
return 0;
}

