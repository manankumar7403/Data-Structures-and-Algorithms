#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Constructor1: No data passed case
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }

        // Constructor2: Data passed case
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // Destructor: To delete the node(no need of destructor here though as we have not dynamically created a
        // memory in this class)
        ~Node()
        {
            cout << "Node with value: " << this->data << " deleted." << endl;
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

// reverse ek Node* pointer type ka function hai jo Node* type ka pointer return karta hai
// Jo LL reverse hoke aayi hai uska jo head hoga vo return hoga is function se
Node* reverseUsingRecursion(Node* &prev, Node* &curr)
{
    // Base case
    if(curr == NULL)
    {
        // LL reverse ho chuki hai toh uska head hoga 'prev' pointer
        return prev;
    }

    // 1 case solve karo baaki recursion sambhal lega
    Node* forward = curr->next;
    curr->next = prev;

    // recursion
    return reverseUsingRecursion(curr, forward);
}

Node* reverseUsingLoop(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
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
    
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);

    insertAtTail(head, tail, 77);
    print(head);

    // Node* prev = NULL;
    // Node* curr = head;
    // cout << "Reversed LL using recursion:" << endl;
    // head = reverseUsingRecursion(prev, curr);
    // print(head);

    cout << "Reversed LL using loop:" << endl;
    head = reverseUsingLoop(head);    
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