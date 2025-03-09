#include<iostream>
using namespace std;

class KQueue
{
    public:
        int n;  // size of array
        int k;  // number of queues
        int freeSpot;
        int *arr, *front, *rear, *next;

    public:
        KQueue(int n, int k)
        {
            this->n = n;
            this->k = k;
            arr = new int[n];   // main array to store the queues
            next = new int[n];  // stores the next free index
            front = new int[k]; // stores front of every ith queue
            rear = new int[k];  // stores rear of every ith queue
            freeSpot = 0;
            
            for(int i=0; i<k; i++)
            {
                front[i] = rear[i] = -1;
            }
            for(int i=0; i<n; i++)
            {
                next[i] = i + 1;
            }
            next[n-1] = -1;
        }

        // push x into Qith queue
        void enqueue(int data, int qi)
        {
            // overflow
            if(freeSpot == -1)
            {
                cout << "No empty space is present!" << endl;
                return;
            }

            // find first free index
            int index = freeSpot;

            // update freeSpot
            freeSpot = next[index];

            // if first element in qi
            if(front[qi-1] == -1)                 // doing -1 because of 0 based indexing
            {
                front[qi-1] = index;
            }
            else
            {
                // link new element to that Q's previous element
                next[rear[qi-1]] = index;
            }
            
            // update next
            next[index] = -1;

            // update rear
            rear[qi-1] = index;

            // push element
            cout << "Pushing " << data << " in Queue " << qi << endl;
            arr[index] = data;
        }

        int dequeue(int qi)
        {
            // Underflow
            if(front[qi-1] == -1)
            {
                cout << "Queue underflow " << endl;
                return -1;
            }

            // find index to pop 
            int index = front[qi-1];

            // front ko aage badhao
            front[qi-1] = next[index];

            // manage the free slots
            next[index] = freeSpot;
            freeSpot = index;
            cout << "Popping " << arr[index] << " from Queue " << qi << endl;
            return arr[index];
        }

        ~KQueue()
        {
            delete[] arr;
            delete[] front;
            delete[] rear;
            delete[] next;

        }
};

int main()
{
    KQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(2);
    q.dequeue(1);
    q.dequeue(2);

    return 0;
}