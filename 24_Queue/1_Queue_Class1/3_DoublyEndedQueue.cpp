#include <iostream>
using namespace std;

class DoublyEndedQueue {
public:
    int* arr;
    int size;
    int front;
    int rear;

    // Constructor
    DoublyEndedQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data) {
        // Queue full
        if (front == 0 && rear == size - 1) {
            cout << "Queue is full, cannot insert." << endl;
            return;
        }

        // single element case -> first element
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }

        // normal flow
        else if (rear < size - 1) {
            rear++;
            arr[rear] = data;
        }

        // Move rear to start if at end
        else {
            rear = 0;
            arr[rear] = data;
        }
    }

    void pushFront(int data) {
        // Queue full
        if (front == 0 && rear == size - 1) {
            cout << "Queue is full, cannot insert." << endl;
            return;
        }

        // single element case -> first element
        else if (front == -1) {
            front = rear = 0;
            arr[front] = data;
        }

        // Move front to end if at start
        else if (front > 0) {
            front--;
            arr[front] = data;
        }

        // normal flow
        else {
            front = size - 1;
            arr[front] = data;
        }
    }

    void popFront() {
        // Check if empty
        if (front == -1) {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        // Single element case
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        else if(front == size - 1)
        {
            front = 0;
        }

        // Normal flow
        else {
            front++;
        }
    }

    void popRear() {
        // Check if empty
        if (front == -1) {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        // Single element case
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // Normal flow
        else if (rear > 0) {
            rear--;
        }

        // Move rear to end if at start
        else {
            rear = size - 1;
        }
    }

    int getFront() {
        if (front == -1) {
            cout << "The Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (front == -1) {
            cout << "The Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size));
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        }

        if (front <= rear) {
            return rear - front + 1;
        }

        else {
            return size - front + rear + 1;
        }
    }

    void printDoublyEndedQueue() {
        if (front == -1) {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Elements of the Queue are:" << endl;
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Creation
    DoublyEndedQueue deq(10);

    deq.pushRear(10);
    deq.pushRear(20);
    deq.pushRear(30);
    deq.pushRear(40);
    deq.pushRear(50);
    // deq.pushFront(100);
    deq.pushFront(90);
    deq.pushFront(80);
    deq.pushFront(70);
    deq.pushFront(60);

    if (deq.isFull()) {
        cout << "Queue is full!" << endl;
    }
    else {
        cout << "Queue is not full!" << endl;
    }

    cout << "Size of queue is: " << deq.getSize() << endl;
    deq.printDoublyEndedQueue();

    deq.popFront();

    cout << "Size of queue is: " << deq.getSize() << endl;
    deq.printDoublyEndedQueue();

    cout << "Front element is: " << deq.getFront() << endl;

    cout << "Rear element is: " << deq.getRear() << endl;

    if (deq.isEmpty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Queue is not empty!" << endl;
    }

    deq.popFront();
    deq.popRear();
    deq.printDoublyEndedQueue();
    deq.popRear();
    deq.popFront();
    deq.printDoublyEndedQueue();
    deq.popFront();
    if (deq.isEmpty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}