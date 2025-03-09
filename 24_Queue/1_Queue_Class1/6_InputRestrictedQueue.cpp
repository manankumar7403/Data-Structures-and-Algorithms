/*
An input restricted queue is a special case of a double-ended queue where data can be inserted from one end(rear)
but can be removed from both ends (front and rear). This kind of Queue does not follow FIFO(first in first out).

Operations on Input Restricted Queue:
Mainly the following three basic operations are performed on input restricted queue:
insertRear(): Adds an item at the rear of the queue. 
deleteFront(): Deletes an item from the front of the queue. 
deleteRear(): Deletes an item from rear of the queue.

In addition to above operations, following operations are also supported:
getFront(): Gets the front item from the queue. 
getRear(): Gets the last item from the queue. 
isEmpty(): Checks whether queue is empty or not. 
isFull(): Checks whether queue is full or not.
getSize(): Number of elements currently in the queue.
*/

#include <iostream>
using namespace std;

class InputRestrictedQueue
{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    // Constructor
    InputRestrictedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = 0;
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

    void popRear()
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
        else if (rear == 0)
        {
            rear = size - 1;
        }

        // Normal flow
        else
        {
            rear--;
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

    void printInputRestrictedQueue()
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
    InputRestrictedQueue irq(10);

    irq.pushRear(10);
    irq.pushRear(20);
    irq.pushRear(30);
    irq.pushRear(40);
    irq.pushRear(50);
    irq.pushRear(60);
    irq.pushRear(70);
    irq.pushRear(80);
    irq.pushRear(90);
    irq.pushRear(100);

    if(irq.isFull())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "Queue is not full!" << endl;
    }

    cout << "Size of queue is: " << irq.getSize() << endl;
    irq.printInputRestrictedQueue();

    irq.popFront();

    cout << "Size of queue is: " << irq.getSize() << endl;
    irq.printInputRestrictedQueue();

    cout << "Front element is: " << irq.getFront() << endl;

    cout << "Rear element is: " << irq.getRear() << endl;

    if(irq.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    irq.popFront();
    irq.popRear();
    irq.printInputRestrictedQueue();
    irq.popRear();
    irq.popFront();
    irq.printInputRestrictedQueue();
    irq.popRear();
    irq.popFront();
    irq.popRear();
    irq.popFront();
    irq.popRear();
    irq.printInputRestrictedQueue();

    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)