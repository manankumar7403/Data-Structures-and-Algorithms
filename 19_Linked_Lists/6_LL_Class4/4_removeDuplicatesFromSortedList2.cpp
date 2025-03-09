/*
🔴🔴LEETCODE 82 -> Remove Duplicates From Sorted List 2🔴🔴
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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

Node* deleteDuplicates(Node* &head)
{
    // Dummy node to handle edge cases such as removing the head node
    Node* dummy = new Node(0, head);
    Node* prev = dummy; // Previous distinct node
    Node* curr = head;  // Current node to check for duplicates

    while (curr != NULL)
    {
        // Skip all nodes that have the same value
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            while (curr->next != NULL && curr->data == curr->next->data)
            {
                curr = curr->next;
            }
            // Link the previous distinct node to the node after duplicates
            prev->next = curr->next;
        }
        else
        {
            // No duplicates, move prev to current node
            prev = prev->next;
        }
        // Move current to the next node
        curr = curr->next;
    }
    return dummy->next;
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

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    cout << "Input LL:" << endl;
    print(head);

    head = deleteDuplicates(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n)
// SC -> O(1)