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

void deleteNode(int position, Node* &head, Node* &tail)
{
    // Check if the Linked List is empty
    if(head == NULL)
    {
        cout << "Cannot delete as the Linked List is empty!" << endl;
        return;
    }

    int len = findLength(head);
    if(position == 0 || position > len)
    {
        cout << "Invalid position to delete" << endl;
        return;
    }

    // If you want to delete the first node(head)
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;                   // calls the destructor (check the Node class)
        return;
    }

    // If you want to delete the last node(tail)
    if(position == len)
    {
        // Find prev
        int i=1;
        Node* prev = head;
        while(i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp = tail;
        tail = prev;
        delete temp;                   // calls the destructor (check the Node class)
        return;
    }

    // Deleting any node in the middle
    // Step1: Find prev and curr
    int i=1;
    Node* prev = head;
    while(i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step2
    prev->next = curr->next;

    // Step3
    curr->next = NULL;

    // Step4:
    delete curr;
}

void deleteAfterValue(int valueToDeleteAfter, Node* &head, Node* &tail)
{
    // Check for empty Linked List
    if(head == NULL)
    {
        cout << "Cannot delete as Linked List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL && temp->data != valueToDeleteAfter)
    {
        temp = temp->next;
    }

    // If the value is not found or it is the last node, return
    if(temp == NULL || temp->next == NULL)
    {
        cout << "Value not found or reached the last node, cannot delete." << endl;
        return;
    }

    // Node to be deleted
    Node* nodeToDelete = temp->next;

    // Adjust pointers to skip the node to be deleted
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;

    // If the deleted node was the tail, update the tail
    if(nodeToDelete == tail)
    {
        tail = temp;
    }

    // Delete the node
    delete nodeToDelete;
}

void deleteBeforeValue(int valueToDeleteBefore, Node* &head, Node* &tail)
{
    // Check for empty Linked List
    if (head == NULL || head->next == NULL)
    {
        cout << "Cannot delete as the Linked List is empty or has only one node!" << endl;
        return;
    }

    // If the given value is at the head, there is no node before it to delete
    if (head->data == valueToDeleteBefore)
    {
        cout << "Cannot delete before the head node!" << endl;
        return;
    }

    // Find the node before the one with the given value
    Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL && temp->next->next->data != valueToDeleteBefore)
    {
        temp = temp->next;
    }

    // If the value is not found or it is the first node, return
    if (temp->next == NULL || temp->next->next == NULL)
    {
        cout << "Value not found or it's the first node, cannot delete." << endl;
        return;
    }

    // Node to be deleted
    Node* nodeToDelete = temp->next;

    // Adjust pointers to skip the node to be deleted
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;

    // Delete the node
    delete nodeToDelete;
}

void deleteValue(int valueToDelete, Node* &head, Node* &tail)
{
    // Check for empty Linked List
    if (head == NULL || head->next == NULL)
    {
        cout << "Cannot delete as the Linked List is empty!" << endl;
        return;
    }

    // If the given value is at the head, there is no node before it to delete
    if (head->data == valueToDelete)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Find the node before the one with the given value
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != valueToDelete)
    {
        temp = temp->next;
    }

    // If the value is not found, return
    if (temp->next == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }

    // Node to be deleted
    Node* nodeToDelete = temp->next;

    // Adjust pointers to skip the node to be deleted
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;

    // Delete the node
    delete nodeToDelete;
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
    
    insertAtTail(head, tail, 50);

    insertAtPosition(60, 2, head, tail);
    insertAtPosition(70, 6, head, tail);

    print(head);

    deleteNode(8, head, tail);
    
    print(head);
    
    deleteAfterValue(10, head, tail);
    print(head);

    deleteBeforeValue(70, head, tail);
    print(head);

    deleteValue(20, head, tail);
    print(head);
    return 0;
}