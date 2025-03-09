/*
template <typename T>
class Stack {
    Node<T> *head;
    int size;

    public :    
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T>* temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    T pop() {
        T data = head->data;
        head = head->next;
        size--;
        return data;   
    }
    
    T top() {
        return head->data;
    }    
};
*/

#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
public:   
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T>* temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    T pop() {
        if(size==0){
            return 0;
        }
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;        
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0){
            return 0;
        }
        return head->data;
    }  
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    cout << "Top element: " << s.top() << endl;
    if(s.isEmpty())
    {
        cout << "Empty!" << endl;
    }
    else cout << "Not empty!" << endl;
    
    cout << "Size of stack: " << s.getSize() << endl;
    return 0;
}