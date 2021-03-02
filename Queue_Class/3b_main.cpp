/* C++ program to implement basic queue
operations */

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front, rear, capacity;
    int *array;

public:
    Queue(int max_size);
    ~Queue()
    {
        delete[] array;
    }
    int isfull();
    int isempty();
    void enqueue(int item);
    void dequeue();
    void display();
};

Queue::Queue(int max_size)
{
    capacity = max_size;
    front = 0;
    rear = -1;
    array = new int[max_size];
}

int Queue::isfull()
{
    return (rear == capacity - 1);
}

int Queue::isempty()
{
    return (rear == -1);
}

void Queue::enqueue(int item)
{
    if (isfull())
        return;
    rear = (rear + 1) % capacity;
    array[rear] = item;
    cout << item << " enqueued to queue\n";
}

void Queue::dequeue()
{
    if (isempty())
        cout << "Queue is Empty\n";
    else
    {
        int item = array[front];
        front = (front + 1) % capacity;
        cout << item << " dequeued from queue\n";
    }
}

void Queue::display()
{
    if (isempty())
        cout << "Queue is Empty\n";
    else
    {
        int f = front, r = rear;
        while (f <= r)
        {
            cout << array[f] << " ";
            f++;
        }
        cout << "\n";
    }
}

int main()
{
    cout << "Enter Max size of Queue: ";
    int max_size;
    cin >> max_size;
    Queue q(max_size);
    while (true)
    {
        cout << "1.Enqueue\n2.Dequeue\n3.Display\n\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a number to be enqueued: ";
            int num;
            cin >> num;
            q.enqueue(num);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        default:
            cout << "Wrong choice.Try Again!\n";
        }

        cout << "Will you like to continue? (Y/N): ";
        char c;
        cin >> c;
        if (c == 'n' || c == 'N')
            break;
    }

    q.~Queue();
    cout << "\nQueue is deallocated\n\n";

    return 0;
}