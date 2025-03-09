/*
🔴🔴LEETCODE 21 -> Merge 2 Sorted Lists🔴🔴
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the
nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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

Node *mergeTwoLists(Node *left, Node *right)
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

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 4);

    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 4);

    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);

    Node* mergedList = mergeTwoLists(head1, head2);
    cout << "Merged List: ";
    print(mergedList);

    return 0;
}