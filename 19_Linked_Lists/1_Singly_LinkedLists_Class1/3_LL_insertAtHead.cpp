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
void insertAtHead(Node* &head, int data)
{
    // Step1: Create the new node you want to insert at head
    Node* newNode = new Node(data);

    // Step2: The next of newNode should point to the current head
    newNode->next = head;

    // Step3: Changing the head to the newNode as head is always at the beginning
    head = newNode; 

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

    insertAtHead(head, 20);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 90);

    print(head);
    return 0;
}

// head pointer -> starting point of the Linked List