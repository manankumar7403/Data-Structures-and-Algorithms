// ⭐⭐Important: Floyd Cycle Detection: Hare and Tortoise⭐⭐
// fast = fast->next->next
// slow = slow->next

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

Node* startPosOfLoop(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast)
        {
            slow = head;
            break;
        }
    }
    if(fast == NULL) return NULL;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = fourth;

    if(startPosOfLoop(head) != NULL)
    {
        cout << "Loop present at position: " << startPosOfLoop(head)->data << endl;
    }
    else cout << "Loop is not present" << endl;
    
    return 0;
}