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

void insertAtTail(Node* &head, Node* &tail, int data)
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

void removeDuplicates(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return;
    }
    if(head->next == NULL)
    {
        cout << "Single node in LL" << endl;
        return;
    }

    // now case for more than 1 node
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            // equal(duplicate) -> handle the pointers
            curr->next = curr->next->next;
           
            // delete node
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
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

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 4);
    cout << "Input LL:" << endl;
    print(head);

    removeDuplicates(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n)
// SC -> O(1)