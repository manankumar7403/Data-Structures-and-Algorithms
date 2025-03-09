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

    // return head of the modified LL
    return prev;    
}

bool checkPalindrome(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return true;
    }
    if(head->next == NULL)
    {
        return true;
    }

    // 1 node in LL
    // Step1: Find the middle node of the LL
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    // slow pointer is pointing to the middle node
    // Step2: Reverse the LL after the middle node
    Node* reverseLLKaHead = reverse(slow->next);
    // join the reversed LL into the left part
    slow->next = reverseLLKaHead;

    // Step3: Start the comparison
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;
    while(temp2 != NULL)
    {
        if(temp1->data != temp2->data)
        {
            // not a palindrome
            return false;
        }
        else
        {
            // data value matches, it is a palindrome
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
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

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    print(head);

    // insertAtTail(head, tail, 10);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 10);
    // print(head);

    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome)
    {
        cout << "LL is a valid palindrome." << endl;
    }
    else cout << "LL is not a valid palindrome." << endl;
    
    return 0;
}

// TC -> O(n)
// SC -> o(1)