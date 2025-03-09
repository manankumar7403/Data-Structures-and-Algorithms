// Circular doubly ended queue and doubly ended queue only have 1 difference in condition.
// If rear is at end and front is not at 0, space available at front in circular queue, here in circular
// doubly ended queue.
// So, everything remains same, we just put the below condition for making doubly ended queue to circular
// doubly ended queue.

// if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
// and also:
// circular nature
// else if(rear == size -1 && front != 0)  // rear last pe hai aur front 0 par nahi hai matlab enqueue hoke dequeue ho chuke hai kuch elements toh shuru me space availabl hai
// {
//     rear = 0;
//     arr[rear] = data;
// }
// ___________________________________________________________________________________________________________

#include <iostream>
using namespace std;

class CirDoublyEndedQueue
{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    // Constructor
    CirDoublyEndedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // Queue full
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
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

    void pushFront(int data)
    {
        // Queue full
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
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

    void popFront()
    {
        // Check if empty
        if (front == -1)
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
        if (front == -1)
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
        if (front == -1)
        {
            cout << "The Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (front == -1)
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
        return (front == 0 && rear == size - 1) || ((rear + 1) % size == front);
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

    void printCirDoublyEndedQueue()
    {
        if (front == -1)
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
    CirDoublyEndedQueue cdeq(10);

    cdeq.pushFront(10);
    cdeq.pushRear(20);
    cdeq.pushRear(30);
    cdeq.pushRear(40);
    cdeq.pushRear(50);
    cdeq.pushRear(60);
    cdeq.pushRear(70);
    cdeq.pushRear(80);
    cdeq.pushRear(90);
    // cdeq.pushFront(100);

    if(cdeq.isFull())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "Queue is not full!" << endl;
    }

    cout << "Size of queue is: " << cdeq.getSize() << endl;
    cdeq.printCirDoublyEndedQueue();

    cdeq.popFront();

    cout << "Size of queue is: " << cdeq.getSize() << endl;
    cdeq.printCirDoublyEndedQueue();

    cout << "Front element is: " << cdeq.getFront() << endl;

    cout << "Rear element is: " << cdeq.getRear() << endl;

    if(cdeq.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    cdeq.popFront();
    cdeq.popRear();
    cdeq.printCirDoublyEndedQueue();
    cdeq.popRear();
    cdeq.popFront();
    cdeq.printCirDoublyEndedQueue();
    cdeq.popRear();
    cdeq.popFront();
    cdeq.popRear();
    cdeq.popFront();
    cdeq.popRear();
    cdeq.printCirDoublyEndedQueue();

    return 0;
}