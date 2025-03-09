// 🔴🔴LEETCODE 61 -> Rotate List🔴🔴 
/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
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
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *rotateRight(Node* &head, int k)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    int len = findLength(head);
    int actualRotate = (k % len);
    if (k == len || actualRotate == 0)
        return head;

    int newLastNodePos = len - actualRotate - 1;
    Node* newLastNode = head;
    for (int i = 0; i < newLastNodePos; i++)
    {
        newLastNode = newLastNode->next;
    }
    Node* newHead = newLastNode->next;
    newLastNode->next = NULL;

    Node* it = newHead;
    while (it->next != NULL)
    {
        it = it->next;
    }
    it->next = head;

    return newHead;
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
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    int k;
    cout << "Enter the value of k:" << endl;
    cin >> k;

    cout << "Original List:" << endl;
    print(head);

    head = rotateRight(head, k);

    cout << "Rotated LL by "<< k << ":" << endl;
    print(head);

    return 0;
}