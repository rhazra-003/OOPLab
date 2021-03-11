#include <iostream>
#include <cstdlib>
#include <cmath>
#include "MyLinkedList.h"

class Hash	
{
    private:
        List* hashTable;	
        int hashFunction(int);

    public:
        int size;	
        Hash(int);
        ~Hash();
        void search(int);
        void insert(int);
        void delet(int);
        void display();
        double TableLoadDistr(int);
};

int Hash::hashFunction(int element)	
{
    return (element%size);
}

Hash::Hash(int tableSize)	
{
    this->size=tableSize;
    hashTable=new List[size];
    for (int i=0; i<size; i++)
    {
    	hashTable[i].construct();
	}
}

Hash::~Hash()
{
    for (int i=0; i<size; i++)
    {
        hashTable[i].deconstruct();
    }

    delete[] hashTable;
}

void Hash::search(int key)	
{
    int i=hashFunction(key);
    int pos=hashTable[i].searchList(key);

    if (pos==-1)
    {
        cout << "---> "<<key<<" was not found in the the Hash Table" << endl;
    }
    else
    {
        cout << "---> "<<key<<" was found in the the Hash Table in Bucket " << i << endl;
    }
}

void Hash::insert(int element)	
{
    int i=hashFunction(element);
    hashTable[i].insertNode(element);
}

void Hash::delet(int key)	
{
    int i=hashFunction(key);
    hashTable[i].deleteNode(key);
    cout<<"---> " << key << " was deleted from the the Hash Table" << endl;
}

void Hash::display()	
{
	for (int i=0; i<size; i++)
	{
		cout<<"Bucket "<<i<<": ";
        hashTable[i].displayList();
	}
}

double Hash::TableLoadDistr(int n)	
{
    double var=0.0;
    for (int i=0; i<size; i++)
    {
        var=var+pow((hashTable[i].countNode()-(n/size*1.0)),2);
    }
    var= var/(double)(n-1);
    return var;
}

int main()	
{
	Hash* hash1=new Hash(10);
	Hash* hash2=new Hash(15);
	
	int arr[100];	
	for (int i=0; i<100; i++)
	{
		arr[i]=rand();
	}
	
	for (int i=0; i<100; i++)
	{
		hash1->insert(arr[i]);
	}	
	
	for (int i=0; i<100; i++)
	{
		hash2->insert(arr[i]);
	}
	
	hash1->display();
	cout << "Variance of first Hash Table is "<<hash1->TableLoadDistr(100) << endl << endl;
	
	hash2->display();
	cout << "Variance of second Hash Table is " << hash2->TableLoadDistr(100) << endl << endl;

	
	hash2->search(41);
	hash2->delet(41);
	hash2->search(41);
}
