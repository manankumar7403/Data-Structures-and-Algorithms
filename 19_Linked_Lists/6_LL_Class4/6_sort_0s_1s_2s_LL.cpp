/*
// 🔴🔴METHOD1: With data replacement🔴🔴

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

void sortZeroOneTwo(Node* &head)
{
    if(head == NULL) return;
    if(head->next == NULL) return;

    // Step1: Find count of zeroes, ones, twos
    int zero = 0;
    int one = 0;
    int two = 0;
    
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == 0) zero++;
        else if(temp->data == 1) one++;
        else if(temp->data == 2) two++;
        temp = temp->next;
    }

    // Step2: Fill 0s, 1s, 2s in the original LL
    temp = head;
    // fill zeroes
    while(zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    // fill ones
    while(one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    // fill twos
    while(two--)
    {
        temp->data = 2;
        temp = temp->next;
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
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    cout << "Input LL:" << endl;
    print(head);

    sortZeroOneTwo(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n)
// SC -> O(1)
*/
// __________________________________________________________________________________________________________________

// 🔴🔴METHOD2: Without data replacement🔴🔴

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

Node* sortZeroOneTwo(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }

    // Step1: Create dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* OneHead = new Node(-1);
    Node* OneTail = OneHead;
    Node* TwoHead = new Node(-1);
    Node* TwoTail = TwoHead;

    // Step2: Traverse the original LL
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->data == 0)
        {
            // take out the 0 wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in the zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1)
        {
            // take out the 1 wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the 1 node in the zeroHead LL
            OneTail->next = temp;
            OneTail = temp;
        }
        else if(curr->data == 2)
        {
            // take out the 2 wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in the zeroHead LL
            TwoTail->next = temp;
            TwoTail = temp;
        }
    }

    // now 0, 1, 2 LLs are ready
    // remove dummy nodes
    // modify 1 wali LL -> removing the dummy node
    Node* temp = OneHead;
    OneHead = OneHead->next;
    temp->next = NULL;
    delete temp;
    // modify 2 wali LL -> removing the dummy node
    temp = TwoHead;
    TwoHead = TwoHead->next;
    temp->next = NULL;
    delete temp;

    // now join them
    if(OneHead != NULL)
    {
        // 1 wali LL is non empty
        zeroTail->next = OneHead;
        if(TwoHead != NULL)
        {
            // 2 wali LL is non empty
            OneTail->next = TwoHead;
        }
    }
    else
    {
        // 1 wali LL is empty
        if(TwoHead != NULL)
        {
            zeroTail->next = TwoHead;
        }
    }

    // remove zeroHead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the modified LL
    return zeroHead;
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
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    cout << "Input LL:" << endl;
    print(head);

    // Node* temp = NULL;
    // head = sortZeroOneTwo(temp);

    head = sortZeroOneTwo(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n)
// SC -> O(1)