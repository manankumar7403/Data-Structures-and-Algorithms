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

void insertAfterValue(int dataToInsert, int valueToFind, Node* &head, Node* &tail)
{
    // Check if the Linked List is empty
    if(head == NULL)
    {
        Node* newNode = new Node(dataToInsert);
        head = newNode;
        tail = newNode;
        return;
    }

    // Find the node with the given value
    Node* temp = head;
    while(temp != NULL && temp->data != valueToFind)
    {
        temp = temp->next;
    }

    // If the value is not found return
    if(temp == NULL)
    {
        cout << valueToFind << " not found in the Linked List." << endl;
        return;
    }

    // If the value is found
    Node* newNode = new Node(dataToInsert);

    // Adjust the pointers to insert the new node after the found value
    newNode->next = temp->next;
    temp->next = newNode;

    // If the new node is inserted at the end, update the tail
    if(temp == tail)
    {
        tail = newNode;
    }
}

void insertBeforeValue(int dataToInsert, int valueToFind, Node* &head, Node* &tail)
{
    // Check for empty Linked List
    if (head == NULL)
    {
        Node* newNode = new Node(dataToInsert);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the given value is at the head, insert at the head
    if (head->data == valueToFind)
    {
        insertAtHead(head, tail, dataToInsert);
        return;
    }

    // Find the node before the one with the given value
    Node* temp = head;
    while (temp != NULL && temp->next != NULL && temp->next->data != valueToFind)
    {
        temp = temp->next;
    }

    // If the value is not found, return
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Value not found in the Linked List." << endl;
        return;
    }

    // Create a new node
    Node* newNode = new Node(dataToInsert);

    // Adjust the pointers to insert the new node before the found value
    newNode->next = temp->next;
    temp->next = newNode;
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
    print(head);
    cout << endl;
    
    insertAtTail(head, tail, 50);
    print(head);
    cout << endl;

    insertAtPosition(60, 0, head, tail);
    insertAtPosition(70, 6, head, tail);
    print(head);
    cout << endl;

    insertAfterValue(235, 60, head, tail);
    print(head);
    cout << endl;
    
    insertBeforeValue(999, 70, head, tail);

    print(head);
    return 0;
}

/*
while (temp != NULL && temp->next != NULL && temp->next->data != valueToFind)

1. `temp != NULL`: This condition ensures that the loop continues as long as `temp` is pointing to a valid node
in the linked list. If `temp` becomes `NULL`, it means we have reached the end of the linked list, and there is
no need to continue searching.

2. `temp->next != NULL`: This condition is used to prevent dereferencing a null pointer. Inside the loop, we
often use `temp->next` to move to the next node. Before accessing `temp->next`, we need to make sure that `temp`
itself is not the last node (i.e., `temp->next` is not `NULL`). Otherwise, trying to access `temp->next` when
`temp` is the last node would result in a null pointer dereference error.

3. `temp->next->data != valueToFind`: This condition checks whether the data in the next node is equal to the
value we are searching for (`valueToFind`). If it is, we have found the node before the one containing the
value we are looking for, and the loop can exit.

The loop continues to iterate through the linked list until one of these conditions is false. It stops when it
finds the target value (`valueToFind`), reaches the end of the list, or encounters a null pointer. After the
loop, `temp` points to the node before the one containing the target value, allowing us to insert a new node
before it. If the target value is not found, appropriate error handling is performed.
*/