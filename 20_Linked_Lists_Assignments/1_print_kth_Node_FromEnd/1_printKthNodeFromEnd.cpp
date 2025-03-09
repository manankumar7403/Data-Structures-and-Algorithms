// hackerrank question

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

        // Constructor3: Taking in data and next node
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }

        // Destructor: To delete the node(no need of destructor here though as we have not dynamically created a
        // memory in this class)
        ~Node()
        {
            cout << "Node with value: " << this->data << " deleted." << endl;
        }

};

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

int findLength(Node* &head)
{
    Node* temp = head;
    int len = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

int getNode(Node* &head, int positionFromTail) {
    if(head == NULL) return -1;

    int len = findLength(head);
    int nodePos = len - positionFromTail - 1;
    if (nodePos < 0 || nodePos >= len) {
        return -1;
    }
    Node* curr = head;
    for(int i=0; i<nodePos; i++)
    {
        curr = curr->next;
    }
    return curr->data;
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

    insertAtTail(head, tail, -1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 0);
    cout << "Input LL:" << endl;
    print(head);

    int n;
    cout << "Enter the nth position from tail:" << endl;
    cin >> n;
    int ans = getNode(head, n);
    cout << n <<" node from the tail is "<< ans << endl;

    return 0;
}