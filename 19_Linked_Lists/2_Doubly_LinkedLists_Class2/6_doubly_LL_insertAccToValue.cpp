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

void insertAtTail(Node* &head, Node* &tail, int data)
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

    // Step2: Tail ka next newnode pe point kara do 
    tail->next = newNode;

    // Step3: newNode ka jo previous hai usko null se hatake tail pe point karo
    newNode->prev = tail;

    // Step4: ab jo newnode hai usko tail bana do kyuki tail hamesha end me hota hai
    tail = newNode;

}

void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    // Check for empty Linked List
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLength(head);
    if(position < 0 || position > len)
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

    // If position = last where you want to insert(it means you are inserting at tail)
    if(position == len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    
    // Step1: Find the position: prevNode and curr node
    int i = 1;
    Node* prevNode = head;
    while(i < position)
    {
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;

    // Step2: Create a new Node
    Node* newNode = new Node(data);

    // Step3: Prev Node ka next new Node par daal do
    prevNode->next = newNode;

    // Step4: new Node ka prev, previous node par daal do
    newNode->prev = prevNode;

    // Step5: Current node ka previous new Node pe daalo
    curr->prev = newNode;

    // Step6: newNode ka next current node par daalo
    newNode->next = curr;
}

void insertAfterValue(Node* &head, Node* &tail, int valueToFind, int data)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == valueToFind)
        {
            // Found the node with the given value, insert after it
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            if (tail == temp)
            {
                // If the found node is the tail, update the tail
                tail = newNode;
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Value " << valueToFind << " not found in the list." << endl;
}

void insertBeforeValue(Node* &head, Node* &tail, int valueToFind, int data)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == valueToFind)
        {
            // Found the node with the given value, insert before it
            Node* newNode = new Node(data);
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != NULL)
            {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
            if (head == temp)
            {
                // If the found node is the head, update the head
                head = newNode;
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Value " << valueToFind << " not found in the list." << endl;
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
    
    insertAtTail(head, tail, 501);
    print(head);

    insertAtPosition(head, tail, 390, 4);
    print(head);

    insertAfterValue(head, tail, 501, 235);
    print(head);

    insertBeforeValue(head, tail, 235, 100);
    print(head);

    return 0;
}

/*
head pointer -> starting point of the Linked List
tail pointer -> ending point of the Linked List 
jab bhi aap head aur tail dono ko NULL se initialize karte ho, toh jab aap ki pehli node aayegi toh aapko
head aur tail ko us node se intiialize karna padega

🔴🔴🔴🔴 Inserting a node at a position -> Considering 0-based indexing 🔴🔴🔴🔴
🔴🔴🔴🔴 Deleting a node at a position -> Considering 1-based indexing 🔴🔴🔴🔴

Agar position me bhi 1-based indexing karni hai toh
if(position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

aur 

while(i < position - 1)
    {
        prev = prev->next;
        i++;
    }

ye changes kardo


⭐⭐⭐⭐
Agar bina 'curr' pointer banaye insert karna hai toh insertAtPosition wale function me,
bhale hi Doubly Linked List hai, par order matter karega.
⭐⭐⭐⭐

1) Find prev Node (same as done in insertAtPosition function)
2) Create new Node
3) prevNode->next->prev = newNode
4) newNode->next = prevNode->next
5) prevNode->next = newNode
6) newNode->prev = prevNode
*/