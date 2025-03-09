#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

// I want to insert a new node right at the head of the Linked List
void insertAtHead(Node* &head, Node* &tail, int data)
{
    // Check for empty Linked List
    // agar LL empty hai to ek new node create karke ussi ke upar head aur tail daal ke return kara diya
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step1: Create the new node you want to insert at head
    Node* newNode = new Node(data);

    // Step2: The next of newNode should point to the current head
    newNode->next = head;

    // Step3: Changing the head to the newNode as head is always at the beginning
    head = newNode; 

}

// I want to insert a new node right at the end of the Linked List
void insertAtTail(Node* &head, Node* &tail, int data)
{
    // Check for empty Linked List
    // agar LL empty hai to ek new node create karke ussi ke upar head aur tail daal ke return kara diya
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step1: Create the new node you want to insert at the end (tail)
    Node* newNode = new Node(data);

    // Step2: The next of the current tail should point to the newNode
    tail->next = newNode;

    // Step3: Changing the tail to newNode as tail is always at the end
    tail = newNode;
}

void print(Node* &head)
{
    Node* temp = head; 
    while(temp != NULL)
    {
        cout << temp->data << " ";  
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    
    insertAtTail(head, tail, 77);

    print(head);
    return 0;
}

// head pointer -> starting point of the Linked List
// tail pointer -> ending point of the Linked List 
// jab bhi aap head aur tail dono ko NULL se initialize karte ho, toh jab aap ki pehli node aayegi toh aapko
// head aur tail ko us node se intiialize karna padega