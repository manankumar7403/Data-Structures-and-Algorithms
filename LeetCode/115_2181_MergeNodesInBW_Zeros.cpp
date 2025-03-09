// 🔴🔴LEETCODE 2181 -> Merge Nodes In Between Zeros🔴🔴
/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and
end of the linked list will have Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all
the merged nodes. The modified list should not contain any 0's.
Return the head of the modified linked list.

Example 1:
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:
Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

Constraints:
The number of nodes in the list is in the range [3, 2 * 10^5].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.
*/
// ____________________________________________________________________________________________________________

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

Node *mergeNodes(Node *&head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head->next;
    Node *newLastNode = NULL;

    int sum = 0;
    while (fast != NULL)
    {
        if (fast->data != 0)
        {
            sum = sum + fast->data;
        }
        else
        {
            // fast->val is now 0
            slow->data = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }

    // head will point at starting and upto newLastNode we have the ans, so deleting the remaining LL.
    Node *temp = newLastNode->next;
    newLastNode->next = NULL;
    while (temp != NULL)
    {
        Node *nxt = temp->next;
        temp->next = NULL;
        delete temp;
        temp = nxt;
    }
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

    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);

    cout << "Original List:" << endl;
    print(head);

    head = mergeNodes(head);
    cout << "Summmation List Between Zeros:" << endl;
    print(head);

    return 0;
}