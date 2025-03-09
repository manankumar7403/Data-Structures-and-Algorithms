/*
🔴🔴LEETCODE 148 -> Sort Linked List🔴🔴
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5
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

Node *findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1); // new node
    Node *mptr = ans;             // traversing the array(merge and sorted)

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }
    if (left != NULL)
    {
        mptr->next = left;
    }
    if (right != NULL)
    {
        mptr->next = right;
    }
    return ans->next;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Break LL into 2 halves using mid node
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // sort recursively
    left = sortList(left);
    right = sortList(right);

    // merge both left and right LLs
    Node *mergedLL = merge(left, right);
    return mergedLL;
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

    // insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);

    insertAtTail(head, tail, -1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 0);
    cout << "Input LL:" << endl;
    print(head);

    head = sortList(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}