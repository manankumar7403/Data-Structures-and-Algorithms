/*
template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
    public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        T data = head->data;
        head = head->next;
        return data;
    }
    
    T front()  {
        return head->data;
    }
};
*/

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if (isEmpty())
        {
            head = temp;
            tail = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    T dequeue() {
        if (isEmpty()) {
            return 0;
        }
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size == 0)
        {
            tail = NULL;
        }
        return data;
    }

    T front() {
        if (isEmpty()) {
            return 0;
        }
        return head->data;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
