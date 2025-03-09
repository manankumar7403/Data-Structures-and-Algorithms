#include<iostream>
#include<unordered_map>
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

void insertAtHead(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode; 

}

void insertAtTailLL(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
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

void insertAtTailCLL(Node* &tail, int dataToInsert)
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

bool isCircular(Node* &head)
{
    unordered_map<Node*, bool> vis;
    Node* temp = head;

    while(temp != NULL)
    {
        if(vis.find(temp) != vis.end())
        {
            return true;  // temp already present, return true that LL is circular
        }
        else
        {
            vis[temp] = true;   // temp not present already, create its entry
        }
        temp = temp->next;
    }
    return false;  // LL is not circular 
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

void printCLL(Node* &tail)
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
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTailLL(head, tail, 10);
    insertAtTailLL(head, tail, 20);
    insertAtTailLL(head, tail, 30);
    insertAtTailLL(head, tail, 40);
    insertAtTailLL(head, tail, 50);
    insertAtTailLL(head, tail, 60);
    print(head);
    // Not circular

    // insertAtTailCLL(tail, 10);
    // insertAtTailCLL(tail, 20);
    // insertAtTailCLL(tail, 30);
    // insertAtTailCLL(tail, 40);
    // insertAtTailCLL(tail, 50);
    // insertAtTailCLL(tail, 60);
    // printCLL(tail);
    // LL is circular

    if(isCircular(tail)) cout << "LL is circular" << endl;
    else cout << "Not circular" << endl;
    
    return 0;
}