// 🔴🔴LEETCODE 19 -> Remove Nth Node From the End of the List🔴🔴
/*
Given the head of a linked list, remove the nth node from the end of the list and return its
head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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

Node *removeNthFromEnd(Node* &head, int n)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL && n == 1)
        return NULL;

    int len = findLength(head);
    int count = 1;
    int nodePos = len - n;
    if (nodePos == 0)
    {
        if (head->next != NULL)
        {
            head = head->next;
            return head;
        }
        else
            return NULL;
    }
    Node *curr = head;
    while (count != nodePos)
    {
        curr = curr->next;
        count++;
    }
    Node *valToDelete = curr->next;
    curr->next = curr->next->next;
    valToDelete->next = NULL;
    delete valToDelete;
    return head;
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
    cout << "Enter the nth node from the end:" << endl;
    cin >> n;

    head = removeNthFromEnd(head, n);
    cout << "Output LL after deleting " << n << " node"<< endl;
    print(head);

    return 0;
}