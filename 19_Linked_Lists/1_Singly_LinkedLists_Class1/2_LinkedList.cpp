#include <iostream>
using namespace std;

class Node
{
    public:
        int data;     // Linked list me jo value padi hai vo
        Node* next;   // next node wala address

        Node()                 // constructor if data pass nhi kiya toh usse 0 le liya
        {
            this->data = 0;
            this->next = NULL;
        }

        Node(int data)         // constructor if data pass kiya toh data ki value daal di
        {
            this->data = data;
            this->next = NULL;
        }
};

void print(Node* &head)         // head banaya jo actually me first element hai
{
    Node* temp = head;          // us head=first ko humne temp likha liya hai
    while(temp != NULL)           // jab tak temp ka address null nahi hai tab tak ye chalega
    {
        cout << temp->data << " ";  
        temp = temp->next;
    }
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Printing the linked list: " << endl;
    print(first);
    return 0;
}

// head pointer -> starting point of the Linked List 