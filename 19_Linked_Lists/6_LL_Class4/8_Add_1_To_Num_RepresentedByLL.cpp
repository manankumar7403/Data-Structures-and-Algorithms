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

Node* reverse(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* add1ToLL(Node* &head)
{
    if(head == NULL) return NULL;
    if(head->next == head) return head;

    head = reverse(head);

    int carry = 1;
    Node* ansHead = NULL;
    Node* ansTail = NULL; 

    while(head != NULL)
    {
        // calculate sum
        int sum = head->data + carry;
        // find digit to create node
        int digit = sum % 10;
        // calculate carry
        carry = sum / 10;

        // create a new node for the digit
        Node* newNode = new Node(digit);

        // attach the new node into the ans wali LL
        if(ansHead == NULL)
        {
            // inserting the first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head = head->next;
    }

    // carry ko alag se handle karo
    while(carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // Step3: Reverse the ans of the LL
    ansHead = reverse(ansHead);
    return ansHead;
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
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 9);

    cout << "Original List: ";
    print(head);

    Node* addedSum = add1ToLL(head);
    cout << "Total sum of the two lists: ";
    print(addedSum);

    return 0;
}

// TC -> O(n)
// SC -> O(1)