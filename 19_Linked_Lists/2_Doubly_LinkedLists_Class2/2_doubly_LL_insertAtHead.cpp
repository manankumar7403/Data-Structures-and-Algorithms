#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        // Constructor1: Default Constructor -> When no data is passed.
        Node()
        {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }

        // Constructor2: Parameterized Constructor -> When data is passed.
        Node(int data)
        {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

};

int getLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
    
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    // Check if the Linked List is empty
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step1: Create a new Node
    Node* newNode = new Node(data);

    // Step2: Newnode jo banaya hai uska next current head pe point kardo
    newNode->next = head;

    // Step3: Head ka jo previous hai usko null se hatake newnode pe point karo
    head->prev = newNode;

    // Step4: ab jo newnode hai usko head bana do kyuki head hamesha beginning me hota hai
    head = newNode;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);

    print(head);

    return 0;
}
