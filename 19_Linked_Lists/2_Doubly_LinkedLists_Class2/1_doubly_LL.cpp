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
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);

    return 0;
}