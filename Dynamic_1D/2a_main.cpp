#include<iostream>

using namespace std;

int* alloc1DArray(int size)                 

{
    int* heap = new int[size];
    return heap;
}

void insHeap(int *heap,int n,int element)       
{
    if(n==0)
    {
        heap[0]=element;
        return;
    }

    heap[n]=element;
    int i=n;

    while (i>0)
    {
        if(element>heap[(i-1)/2])
        {
            heap[i]=heap[(i-1)/2];
            i=(i-1)/2;
        }
        
        else break;
    }
   
    heap[i]=element;
}

void heapify(int *arr, int n, int i)            
{
    int largest = i;                        
    int l = 2 * i + 1;                      
    int r = 2 * i + 2;                      

    if (l < n && arr[l] > arr[largest])         
        largest = l;


    if (r < n && arr[r] > arr[largest])         
        largest = r;

    if (largest != i)                           
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);              
    }
}

int delHeap(int *heap, int& n)                      
{
    int root=heap[0];
    int lastElement = heap[n - 1];
    heap[0] = lastElement;
    n --;
    heapify(heap, n, 0);
    return root;
}

void display1DArray(int *heap,int size)             
{
    cout << "[ ";
    for(int i=0;i<size;i++)
    {
        cout << heap[i] << " ";
    }
    cout << "]" << endl;
}

int main()

{
    cout << "Start by creating a heap: " << endl;

    int size;
    cout << "\nEnter the size of your heap: ";   
    cin >> size;
    int *heap=alloc1DArray(size);

    int n;
    cout << "\nHow many numbers do you want to enter now?: ";    
    cin >> n;
    cout << "Enter " << n << " numbers below: " << endl;
    for(int i=0;i<n;i++)
    {
        int element;
        cin >> element;
        insHeap(heap,i,element);
    }

    int choice;
    while (true)
    
    {
        cout << endl << endl;
        cout << "Choose from the below options: " << endl;
        cout << "1.Display your heap\n2.Insert a new number\n3.Delete the max number\n4.Quit" << endl;
        cout<<"\nEnter your choice: ";  
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                display1DArray(heap,n);
                break;
            }
            case 2:
            {
                if(size==n)
                {
                    cout << "Cannot insert more numbers. No space left! "<< endl;
                    break;
                }
                int element;
                cout << "Enter your element: ";  
                cin >> element;
                insHeap(heap,n,element);
                n++;
                cout << "Modified heap is as follows: " << endl;
                display1DArray(heap,n);
                break;
            }
            case 3:
            {
                cout << "Deleted element is: ["<<delHeap(heap,n)<<"]" << endl;
                break;
            }
            case 4:
            {
                delete[] heap;                                    
                cout << "\nExiting program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice! Please choose again!" << endl;

        }
    }

}

