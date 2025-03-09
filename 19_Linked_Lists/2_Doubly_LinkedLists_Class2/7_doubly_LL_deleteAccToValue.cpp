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

        ~Node()
        {
            cout << "Node with value: " << this->data << " deleted." << endl;
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

void deleteFromPos(Node* &head, Node* &tail, int position)
{
    // Check if the Linked List is empty
    if(head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    if(head->next == NULL)
    {
        // Single Node present in the Linked List
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if(position > len || position < 0)
    {
        cout << "Please enter a valid position." << endl;
        return;
    }

    if(position == 1)
    {
        // Want to delete the head node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if(position == len)
    {
        // Want to delete the last node
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    // Delete from anywhere in the middle
    // Step1: Find left, curr, right
    int i = 1;
    Node* left = head;
    while(i < position - 1)
    {
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    // Step2:
    left->next = right;
    // Step3:
    right->prev = left;
    // Step4:
    curr->prev = NULL;
    // Step5:
    curr->next = NULL;
    // Step6:
    delete curr;
}

void deleteAfterValue(Node* &head, Node* &tail, int valueToFind)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == valueToFind && temp->next != NULL)
        {
            // Found the node with the given value, delete the node after it
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            if (nodeToDelete->next != NULL)
            {
                nodeToDelete->next->prev = temp;
            }
            if (tail == nodeToDelete)
            {
                // If the node to delete is the tail, update the tail
                tail = temp;
            }
            nodeToDelete->prev = NULL;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }

    cout << "Value " << valueToFind << " not found in the list or there is no node after it." << endl;
}

void deleteBeforeValue(Node* &head, Node* &tail, int valueToFind)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == valueToFind && temp->prev != NULL)
        {
            // Found the node with the given value, delete the node before it
            Node* nodeToDelete = temp->prev;
            temp->prev = nodeToDelete->prev;
            if (nodeToDelete->prev != NULL)
            {
                nodeToDelete->prev->next = temp;
            }
            if (head == nodeToDelete)
            {
                // If the node to delete is the head, update the head
                head = temp;
            }
            nodeToDelete->prev = NULL;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }

    cout << "Value " << valueToFind << " not found in the list or there is no node before it." << endl;
}

void deleteValue(Node* &head, Node* &tail, int valueToDelete)
{
    if(head->data == valueToDelete)
    {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == valueToDelete)
        {
            // Found the node with the given value, delete the node
            Node* prevNode = temp->prev;
            if(temp == tail)
            {
                tail = prevNode;
                temp->prev = NULL;
                prevNode->next = NULL;
                delete temp;
                return;
            }
            prevNode->next = temp->next;
            temp->next->prev = prevNode;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;                        
        }
        temp = temp->next;
    }
    cout << "Value " << valueToDelete << " not found in the list." << endl;
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

    insertAtPosition(head, tail, 390, 2);
    print(head);

    deleteFromPos(head, tail, 2);
    print(head);

    deleteAfterValue(head, tail, 40);
    print(head);

    deleteBeforeValue(head, tail, 501);
    print(head);

    deleteValue(head, tail, 501);
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