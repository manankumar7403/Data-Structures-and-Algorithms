#include <iostream>
using namespace std;

class CirQueue
{
    public:
        int size;
        int* arr;
        int front;
        int rear;

        // Constructor
        CirQueue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data)
        {
            // Queue full
            if((front == 0 && rear == size-1) || ((rear+1) % size == front))
            {
                cout << "Queue is full, cannot insert." << endl;
                return;
            }

            // single element case -> first element
            else if(front == -1)
            {
                front = rear = 0;
                arr[rear] = data;
            }

            // circular nature
            else if(rear == size -1 && front != 0)  // rear last pe hai aur front 0 par nahi hai matlab enqueue hoke dequeue ho chuke hai kuch elements toh shuru me space available hai
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

        void pop()
        {
            // Check if empty
            if(front == -1)
            {
                cout << "Queue is empty, cannot pop!" << endl;
                return;
            }

            // Single element case
            else if(front == rear)
            {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            // Circular nature of the queue
            else if(front == size-1)
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
            if(front == -1)
            {
                cout << "The Queue is empty!" << endl;
                return -1;
            }
            return arr[front];
        }

        int getRear()
        {
            if(front == -1)
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
            if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int getSize()
        {
            if(isEmpty())
            {
                return 0;
            }

            if(front <= rear)
            {
                return rear - front + 1;
            }

            else
            {
                return size - front + rear + 1;
            }
        }

        void printCirQueue()
        {
            if(front == -1)
            {
                cout << "The queue is empty!" << endl;
                return;
            }
            cout << "Elements of the Queue are:" << endl;
            if(rear >= front)
            {
                for(int i=front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }

            else
            {
                for(int i=front; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                for(int i=0; i <= rear; i++)
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
    CirQueue cq(10);

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.push(60);
    cq.push(70);
    cq.push(80);
    cq.push(90);
    cq.push(100);
    
    if(cq.isFull())
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "Queue is not full!" << endl;
    }

    cout << "Size of queue is: " << cq.getSize() << endl;
    cq.printCirQueue();

    cq.pop();

    cout << "Size of queue is: " << cq.getSize() << endl;
    cq.printCirQueue();

    cout << "Front element is: " << cq.getFront() << endl;

    cout << "Rear element is: " << cq.getRear() << endl;

    if(cq.isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    cq.pop();
    cq.pop();
    cq.printCirQueue();
    cq.pop();
    cq.printCirQueue();

    return 0;
}

/*
In push function (Queue full condition)
The condition `((rear+1) % size == front)` is used instead of `(rear+1 == front)` because it accounts for the
circular nature of the queue. Let's break down the difference:

1. **Circular Queue Considerations:**
   - In a circular queue, after reaching the end of the array, the next position for insertion might be at the
   beginning of the array (due to the circular nature).
   - If `(rear+1 == front)` were used, it would only check if the next position after the current `rear` is equal
   to `front`, but it wouldn't handle the case where the array has wrapped around.

2. **Modulo Operation for Wrap-around:**
   - `(rear+1) % size` ensures that if `rear+1` exceeds the array size, it wraps around to the beginning of the
   array.
   - The modulo operation allows the circular queue to "wrap" from the end of the array to the beginning
   seamlessly.

3. **Example:**
   - Let's say `rear` is at the end of the array (e.g., `size - 1`), and `front` is at the beginning (0).
   - With `(rear+1) % size`, the expression becomes `(size) % size`, which results in 0, indicating that the next
   position after the current `rear` is at the beginning of the array.

4. **Correct Circular Condition:**
   - So, `((rear+1) % size == front)` checks whether the next position after the current `rear` (considering
   circular wrap-around) is equal to the current `front`. This correctly handles the circular conditions in a
   circular queue.

In summary, the modulo operation is crucial for circular queues to ensure that indices wrap around when they
reach the end of the array. Using `(rear+1) % size == front)` makes the condition more robust and applicable to
circular queues, preventing errors related to the circular nature of the data structure.
*/