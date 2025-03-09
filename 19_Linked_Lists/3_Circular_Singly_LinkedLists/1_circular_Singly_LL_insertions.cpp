#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Default constructor
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        
        // Parameterized constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // Destructor
        ~Node()
        {
            if(this->next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout << "Node with value: " << this->data << " deleted." << endl;
        }
};

int findLength(Node* &tail)
{
    int len = 0;
    Node* temp = tail;
    while(temp->next != tail)
    {
        temp = temp->next;
        len++;
    }
    return len+1;
}

void addToEmpty(Node* &tail, int dataToInsert)
{
    // Check if the list is actually empty -> if it is not we are in the wrong function
    if(tail != NULL)
    {
        cout << "List is not empty! Use other functions for insertion." << endl;
        return;
    }

    // List was indeed empty
    Node* newNode = new Node(dataToInsert);
    tail = newNode;
    newNode->next = newNode;
}

void addAtBegin(Node*& tail, int dataToInsert)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = tail->next;
    tail->next = newNode;
}

void addAtEnd(Node* &tail, int dataToInsert)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertAfterValue(Node* &tail, int valueToFind, int dataToInsert)
{
    // Empty list
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    // non-empty list
    // Assuming that the element is present in the list
    Node *curr = tail;
    while (curr->data != valueToFind)
    {
        curr = curr->next;
        if (curr == tail) // If we have traversed the entire list and didn't find the value
        {
            cout << valueToFind << " not present in the list." << endl;
            return;
        }
    }

    // valueToFind has been found -> represented by curr
    Node *temp = new Node(dataToInsert);
    temp->next = curr->next;
    curr->next = temp;
    if(curr==tail)
    {
        tail=temp;
    }
}

void insertBeforeValue(Node* &tail, int valueToFind, int dataToInsert)
{
    // Empty list
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    // non-empty list
    // Assuming that the element is present in the list
    Node *curr = tail->next;
    Node *prev = tail;

    while (prev->next != tail && curr->data != valueToFind)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data != valueToFind)
    {
        // If we have traversed the entire list and didn't find the value
        cout << valueToFind << " not present in the list." << endl;
        return;
    }

    // valueToFind has been found -> represented by curr
    Node *temp = new Node(dataToInsert);
    temp->next = curr;
    prev->next = temp;
}

void insertAccToTailPos(Node* &tail, int position, int dataToInsert)
{
    if(tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    int len = findLength(tail);
    if(position < 0 || position > len)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(position == 0)
    {
        return addAtBegin(tail, dataToInsert);
    }

    if(position == len)
    {
        return addAtEnd(tail, dataToInsert);
    }

    // Step1: Find the position: prev and curr
    int i = 0;
    Node* temp = tail;
    while(i < position)
    {
        temp = temp->next;
        i++;
    }
    Node* newNode = new Node(dataToInsert);
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node* &tail)
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // We will traverse each node from head and keep printing until we reach the tail.
    Node* temp = tail->next;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != tail->next);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    addToEmpty(tail, 10);
    print(tail);

    addAtBegin(tail, 20);
    print(tail);

    addAtBegin(tail, 30);
    print(tail);

    addAtEnd(tail, 40);
    print(tail);

    addAtEnd(tail, 50);
    print(tail);

    insertAfterValue(tail, 50, 60);
    print(tail);

    insertBeforeValue(tail, 30, 70);
    print(tail);

    insertAccToTailPos(tail, 0, 80);
    print(tail);

    return 0;
}
