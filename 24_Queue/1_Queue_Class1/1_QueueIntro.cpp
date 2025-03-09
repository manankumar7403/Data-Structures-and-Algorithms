// ⭐⭐ Queue follows FIFO (First-In-First_Out) Approach. ⭐⭐
// Insertion is at rear and deletion is from the front.
/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Creation of queue
    queue<int> q;

    // Insertion
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    // Size of the queue
    cout << "Size of the queue is: " << q.size() << endl;

    // Deletion in queue
    q.pop();

    // Re-checking the size;
    cout << "Size of the queue is: " << q.size() << endl;

    // Empty or not
    if(q.empty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    cout << "Front of the queue is " << q.front() << endl;
    cout << "Rear of the queue is " << q.back() << endl;
    return 0;
}
*/
// ___________________________________________________________________________________________

// We can implement queue using arrays, vector and Linked Lists

// This is Linear Queue. In linear queue:
// say we enqueue 10 20 30 40 50 -> front is at index = 0 and rear is at index 5
// say we dequeue 3 times
// -1 -1 -1 40 50 -> front is at index 3 and rear is at index 5
// Now even though the first 3 locations are empty, we can't insert elements as rear is out of bound(at index 5).
//⭐⭐ This leads to memory wastage in Linear Queue. ⭐⭐

// Implementing our own queue
// Enqueue is pushing in queue
// Dequeue is popping from queue

#include <iostream>
using namespace std;

class Queue
{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        // Constructor
        Queue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void push(int data)
        {
            if(rear == size)
            {
                cout << "Queue is full." << endl;
                return;
            }
            else
            {
                arr[rear] = data;
                rear++;
            }
        }

        void pop()
        {
            if(front == rear)
            {
                cout << "Queue is empty, can't pop!" << endl;
                return;
            }
            else
            {
                arr[front] = -1;
                front++;
                if(front == rear)        // if front == rear, the queue is empty, so start from the beginning instead starting from somewhere in the middle 
                {
                    front = 0;
                    rear = 0;
                }
            }
        }

        int getFront()
        {
            if(front == rear)
            {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            else
            {
                return arr[front];
            }
        }

        int getRear()
        {
            if(front == rear)
            {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            else
            {
                return arr[rear - 1];
            }
        }

        bool isEmpty()
        {
            if(front == rear)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if(front == 0 && rear == size)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        // not the size of the actual array but the number of elements present.
        int getSize()
        {
            return rear - front;
        }

        void printQueue()
        {
            if (isEmpty())
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                cout << "Queue elements are: ";
                for (int i = front; i < rear; ++i)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    // Creation
    Queue q(10);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    cout << "Size of queue is: " << q.getSize() << endl;
    q.printQueue();

    if(q.isFull())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "Queue is not full!" << endl;
    }

    q.pop();

    cout << "Size of queue is: " << q.getSize() << endl;
    q.printQueue();

    cout << "Front element is: " << q.getFront() << endl;

    cout << "Rear element is: " << q.getRear() << endl;

    if(q.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    q.pop();
    q.pop();
    q.printQueue();
    q.pop();
    q.printQueue();

    return 0;
}