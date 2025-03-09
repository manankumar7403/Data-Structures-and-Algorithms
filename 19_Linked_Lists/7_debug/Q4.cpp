/*
// Debug the code. Task is to rotate the linked list counter-clockwise by k nodes
void rotate(Node* head, int k)
{
    if (k == 0)
        return;
    Node* current = head;
  
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
  
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
  
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}
*/

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

void rotate(Node* &head, int k)
{
    if (k == 0)
        return;
    Node* current = head;
  
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
  
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
  
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}
// suppose 10 20 30 40 50 60 LL thi and k = 3
// expected output = 40 50 60 10 20 30
// first while loop will put current on 30 and kth node will be on 30 as well
// second while loop will put current on 60 and next of 60 will be on 10
// head = kthNode->next which means head is now on 40
// so the LL now looks like 40 50 60 10 20 30
// kth node was still 30 and kthNode -> next = NULL now the LL after 30 is broken so infinite loop is avoided

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

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    print(head);    

    rotate(head, 3);
    print(head);
    
    return 0;
}