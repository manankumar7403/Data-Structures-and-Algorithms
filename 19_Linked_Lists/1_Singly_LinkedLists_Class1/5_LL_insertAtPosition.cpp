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

int findLength(Node* &head)
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

void insertAtPosition(int data, int position, Node* &head, Node* &tail)
{
    // Check for empty Linked List
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    int len = findLength(head);
    if(position > len || position < 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // If position = 0 where you want to insert(it means you are inserting at head)
    if(position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // If position = last-1 where you want to insert(it means you are inserting at tail)
    if(position == len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    
    // Step1: Find the position: prev and curr
    int i = 1;
    Node* prev = head;
    while(i < position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step2: Create a new Node
    Node* newNode = new Node(data);

    // Step3 (always do before step4, else address of curr node would be lost)
    newNode->next = curr;

    // Step4
    prev->next = newNode;
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
    
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    
    insertAtTail(head, tail, 50);

    insertAtPosition(60, 1, head, tail);
    insertAtPosition(70, 7, head, tail);

    print(head);
    return 0;
}

// head pointer -> starting point of the Linked List
// tail pointer -> ending point of the Linked List 
// jab bhi aap head aur tail dono ko NULL se initialize karte ho, toh jab aap ki pehli node aayegi toh aapko
// head aur tail ko us node se intiialize karna padega

// 🔴🔴🔴🔴 Inserting a node at a position -> Considering 0-based indexing 🔴🔴🔴🔴
// 🔴🔴🔴🔴 Deleting a node at a position -> Considering 1-based indexing 🔴🔴🔴🔴

// Agar position me bhi 1-based indexing karni hai toh
// if(position == 1)
//     {
//         insertAtHead(head, tail, data);
//         return;
//     }

// aur 

// while(i < position - 1)
//     {
//         prev = prev->next;
//         i++;
//     }

// ye changes kardo