/*
An output-restricted queue is a special case of a double-ended queue where data can be removed from one end(front)
but can be inserted from both ends (front and rear). This kind of Queue does not follow FIFO(first in first out).

Operations on Output Restricted Queue:
Mainly the following three basic operations are performed on output restricted queue:
insertRear(): Adds an item at the rear of the queue. 
insertFront(): Adds an item at the front of the queue. 
deleteFront(): Deletes an item from the front of the queue. 

In addition to the above operations, the following operations are also supported:
getFront(): Gets the front item from the m queue. 
getRear(): Gets the last item from the m queue. 
isEmpty(): Checks whether the r queue is empty or not. 
isFull(): Checks whether the queue is full or not.
getSize(): Number of elements currently in the queue.
*/

#include <iostream>
using namespace std;

class OutputRestrictedQueue
{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    // Constructor
    OutputRestrictedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = 0;
    }

    void pushFront(int data)
    {
        // Queue full
        if (isFull())
        {
            cout << "Queue is full, cannot insert." << endl;
            return;
        }

        // single element case -> first element
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }

        // circular nature
        else if (front == 0 && rear != size-1) 
        {
            front = size - 1;
            arr[front] = data;
        }

        // normal flow
        else
        {
            front--;
            arr[front] = data;
        }
    }

    void pushRear(int data)
    {
        // Queue full
        if (isFull())
        {
            cout << "Queue is full, cannot insert." << endl;
            return;
        }

        // single element case -> first element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }

        // circular nature
        else if (rear == size - 1 && front != 0) // rear last pe hai aur front 0 par nahi hai matlab enqueue hoke dequeue ho chuke hai kuch elements toh shuru me space availabl hai
        {
            rear = 0;
            arr[rear] = data;
        }

        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void popFront()
    {
        // Check if empty
        if (isEmpty())
        {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        // Single element case
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // Circular nature of the queue
        else if (front == size - 1)
        {
            front = 0;
        }

        // Normal flow
        else
        {
            front++;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty() || rear < 0)
        {
            cout << "The Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || ((rear + 1) % size == front));
    }

    int getSize()
    {
        if (isEmpty())
        {
            return 0;
        }

        if (front <= rear)
        {
            return rear - front + 1;
        }

        else
        {
            return size - front + rear + 1;
        }
    }

    void printOutputRestrictedQueue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Elements of the Queue are:" << endl;
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
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
    OutputRestrictedQueue orq(10);

    orq.pushRear(10);
    orq.pushRear(20);
    orq.pushRear(30);
    orq.pushRear(40);
    orq.pushRear(50);
    orq.pushRear(60);
    orq.pushRear(70);
    orq.pushFront(80);
    orq.pushFront(90);
    orq.pushFront(100);

    if(orq.isFull())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "Queue is not full!" << endl;
    }

    cout << "Size of queue is: " << orq.getSize() << endl;
    orq.printOutputRestrictedQueue();

    orq.popFront();

    cout << "Size of queue is: " << orq.getSize() << endl;
    orq.printOutputRestrictedQueue();

    cout << "Front element is: " << orq.getFront() << endl;

    cout << "Rear element is: " << orq.getRear() << endl;

    if(orq.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    orq.popFront();
    orq.printOutputRestrictedQueue();
    orq.popFront();
    orq.printOutputRestrictedQueue();
    orq.popFront();
    orq.popFront();
    orq.printOutputRestrictedQueue();
    orq.popFront();
    orq.popFront();
    orq.popFront();
    orq.popFront();
    orq.popFront();

    if(orq.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)