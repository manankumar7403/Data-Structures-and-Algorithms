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

int findLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
        len++;
    }
    return len+1;
}

void addToEmpty(Node* &head, Node* &tail, int dataToInsert)
{
    // Check if the list is actually empty -> if it is not we are in the wrong function
    if(head != NULL && tail != NULL)
    {
        cout << "List is not empty! Use other functions for insertion." << endl;
        return;
    }

    // List was indeed empty
    Node* newNode = new Node(dataToInsert);
    head = newNode;
    tail = newNode;
    newNode->prev = newNode;
    newNode->next = newNode;
}

void addAtBegin(Node* &head, Node* &tail, int dataToInsert)
{
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

void addAtEnd(Node* &head, Node* &tail, int dataToInsert)
{
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

void insertAfterValue(Node* &head, Node* &tail, int valueToFind, int dataToInsert)
{
    // Empty list
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    if(tail->data == valueToFind)
    {
        Node* newNode = new Node(dataToInsert);
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
        return;                  // return addAtEnd(head, tail, dataToInsert);
    }

    Node* temp = head;
    while(temp->next != head && temp->data != valueToFind)
    {
        temp = temp->next;
    }

    if(temp->data == valueToFind)
    {
        Node* curr = temp->next;
        Node* newNode = new Node(dataToInsert);
        newNode->prev = temp;
        newNode->next = curr;
        temp->next = newNode;
        curr->prev = newNode;
    }
    else cout << "Value to delete after not present inside the linked list." << endl;
    return;
}

void insertBeforeValue(Node* &head, Node* &tail, int valueToFind, int dataToInsert)
{
    // Empty list
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    if(head->data == valueToFind)
    {
        Node* newNode = new Node(dataToInsert);
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        return;                         // return addAtBegin(head, tail, dataToInsert);
    }

    Node* curr = head->next;
    Node* temp = head;
    while(curr->next != head && curr->data != valueToFind)
    {
        curr = curr->next;
        temp = temp->next;
    }

    if(curr->data == valueToFind)
    {
        Node* newNode = new Node(dataToInsert);
        newNode->prev = temp;
        newNode->next = curr;
        temp->next = newNode;
        curr->prev = newNode;
    }
    else cout << "Value to delete not found in the linked list." << endl;
    return;
}

void insertAccToTailPos(Node* &head, Node* &tail, int position, int dataToInsert)
{
    // Empty list
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    int len = findLength(head);
    if(position < 0 || position > len)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(position == 0)
    {
        return addAtBegin(head, tail, dataToInsert);
    }

    if(position == len)
    {
        return addAtEnd(head, tail, dataToInsert);
    }

    int i = 0;
    Node* temp = tail;
    while(i < position)
    {
        temp = temp->next;
        i++;
    }
    Node* curr = temp->next;
    Node* newNode = new Node(dataToInsert);
    newNode->next = curr;
    newNode->prev = temp;
    temp->next = newNode;
    curr->prev = newNode;
}

void insertAccToHeadPos(Node* &head, Node* &tail, int position, int dataToInsert)
{
    // Empty list
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    int len = findLength(head);
    if(position < 0 || position > len)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(position == 0)
    {
        return addAtBegin(head, tail, dataToInsert);
    }
    
    if(position == len)
    {
        return addAtEnd(head, tail, dataToInsert);
    }

    int i = 1;
    Node* temp = head;
    while(i < position)
    {
        temp = temp->next;
        i++;
    }
    Node* curr = temp->next;
    Node* newNode = new Node(dataToInsert);
    newNode->next = curr;
    newNode->prev = temp;
    temp->next = newNode;
    curr->prev = newNode;
}

void print(Node* &head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    addToEmpty(head, tail, 10);
    print(head);

    addAtBegin(head, tail, 20);
    print(head);

    addAtBegin(head, tail, 30);
    print(head);

    addAtEnd(head, tail, 40);
    print(head);

    addAtEnd(head, tail, 50);
    print(head);

    insertAfterValue(head, tail, 50, 60);
    print(head);

    insertBeforeValue(head, tail, 30, 70);
    print(head);

    insertAccToTailPos(head, tail, 0, 80);
    print(head);

    insertAccToHeadPos(head, tail, 8, 90);
    print(head);

    return 0;
}
