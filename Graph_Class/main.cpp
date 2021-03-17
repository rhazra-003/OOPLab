#include <iostream>
#include "MyLinkedList.h"

using namespace std;

class Graph
{
    int numVertices;
    List* adjVertices;
private:
	int minimumDist(int*, bool*);    
public:
    Graph(int);
    void insert(int,int,int);
    void delet();
    void display(int);
    void depthfirstsearch(int,int,bool*);
    void djikstra(int,int);
};

Graph::Graph(int n)
{
	numVertices= n;
	adjVertices= new List[numVertices];
	for (int i=0; i<numVertices; i++)
	{
		adjVertices[i].construct();
	}
	cout<<"-----An empty graph with "<<n<<" vertices was created-----"<<endl;
}

void Graph::insert(int a, int b, int weight)
{
	adjVertices[a].insert(b,weight);
	adjVertices[b].insert(a,weight);
	cout<<"-----Edge having weight "<<weight<<" was added between "<<a<<" and "<<b<<"-----"<<endl;
}

void Graph::delet()
{
	for (int i=0; i<numVertices; i++)
    {
    	adjVertices[i].deconstruct();
	}
	delete[] adjVertices;
	cout<<"-----The graph was deleted-----"<<endl;
}

void Graph::display(int vertex)
{
    cout<<"For vertex "<<vertex<<":"<<endl;
    adjVertices[vertex].display();
}

void Graph::depthfirstsearch(int start, int num, bool* visited)
{	
	if (visited[start]==0)
	{
		cout<<start<<endl;
		visited[start]=true;
		
		for (int i=0; i<numVertices; i++)
		{
			if ((adjVertices[start].search(i)!=0) && !visited[i])
			{
				depthfirstsearch(i,num,visited);
			}
		}
	}
}

int Graph::minimumDist(int dist[], bool Tset[]) 
{
	int min=INT_MAX,index;
              
	for(int i=0;i<6;i++) 
	{
		if(Tset[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Graph::djikstra(int start, int num) // adjacency matrix used is 6x6
{
	int dist[num];                            
	bool Tset[num];
	
	for(int i = 0; i<num; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;	
	}
	
	dist[start] = 0;            
	
	for(int i = 0; i<num; i++)                           
	{
		int m=minimumDist(dist,Tset);
		Tset[m]=true;
		
		for(int i = 0; i<num; i++)                  
		{
			if((!Tset[i]) && (adjVertices[i].search(m)!=0) && (dist[m]!=INT_MAX) && (dist[m]+adjVertices[i].search(m)<dist[i]))
			{
				dist[i]=dist[m]+adjVertices[i].search(m);
			}
		}
		
	}
	
	cout<<"Vertex\t\tDistance from source"<<endl;
	
	for(int i = 0; i<num; i++)                      
	{
		cout<<i<<"\t\t\t"<<dist[i]<<endl;
	}
}

int main()
{
	int n, choice;
	cout<<"Enter number of vertices in the graph: ";
	cin>>n;
	Graph* g=new Graph(n);
	
	while (true)
	{
		cout << "\t\tMENU" << endl;
        cout << "1. Insert Edge, \n2. Display, \n3. DFS, \n4. Djikstra, \n5. Delete and End Program" << endl;
        cout<<"Enter choice: ";
		cin>>choice;
		
		if (choice==1)
		{
			int a,b,c;
			
			cout<<"Enter the vertices for this edge: "<<endl;			
			cin>>a>>b;
			
			if (((a>n)||(a<0))&&((b>n)||(b<0)))
			{
				cout<<"-----Vertex does not exist-----"<<endl;
				continue;
			}
			
			cout<<"Enter edge weight: ";
			cin>>c;
			if (c<1)
			{
				cout<<"-----Entered edge weight is invalid-----"<<endl;
				continue;
			}
			
			g->insert(a,b,c);
		}
		
		else if (choice==2)
		{
			int a;
			
			cout<<"Enter vertex for display: ";
			cin>>a;
			if ((a>n)||(a<0))
			{
				cout<<"-----Vertex does not exist-----"<<endl;
				continue;
			}
			
			g->display(a);
		}
		
		else if (choice==3)
		{
			int a;
			
			cout<<"Enter start vertex for depth first search: ";
			cin>>a;
			if ((a>n)||(a<0))
			{
				cout<<"-----Vertex does not exist-----"<<endl;
				continue;
			}
			
			bool b[n]={false};
			g->depthfirstsearch(a,n,b);
		}
		
		else if (choice==4)
		{
			int a;
			
			cout<<"Enter start vertex to implement Djikstra's algorithm: ";
			cin>>a;
			if ((a>n)||(a<0))
			{
				cout<<"-----Vertex does not exist-----"<<endl;
				continue;
			}
			
			g->djikstra(a,n);
		}
		
		else if (choice==5)
		{
			g->delet();
			return 0;
		}
		
		else
		{
			cout<<"-----Wrong choice entered-----"<<endl;
		}
	}
	
}