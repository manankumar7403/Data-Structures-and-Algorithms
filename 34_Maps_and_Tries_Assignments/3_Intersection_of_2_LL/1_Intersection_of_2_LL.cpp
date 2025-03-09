// GFG
// Done a similar question on LeetCode where intersection node is found
// This code returns the entire intersection list in order of the first list
/*
Given two linked lists of length n and m, the task is to complete the function findIntersection(), which returns the
intersection of two linked lists. Each of the two linked lists contains distinct node values.

Example 1:
Input:
n = 6, m = 4
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Explanation: Nodes 6, 2 and 8 are common in both of the lists and the order will be according to LinkedList1. 

Example 2:
Input:
n = 5, m = 2
LinkedList1: 5->3->1->13->14
LinkedList2: 3->13
Output: 3 13
Explanation: Nodes 3 and 13 are common in both of the lists and the order will be according toLinkedList1. 
Your Task:
Your task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameters
and returns the head of the intersection list. The returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be the same as the order in which those particular nodes appear in input
list 1 and return null if no common element is present.

Constraints:
1 <= n,m <= 10^4
1 <= node values <= 10^5

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)
*/

#include <iostream>
#include<unordered_map>
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

Node *findIntersection(Node *head1, Node *head2)
{
    unordered_map<int, int> map;
    Node *curr = head2;
    // hash L2 items
    while (curr != NULL)
    {
        map[curr->data]++;
        curr = curr->next;
    }

    Node *IL = NULL;
    Node *it = NULL;

    curr = head1;
    while (curr != NULL)
    {
        if (map.find(curr->data) != map.end())
        {
            if (map[curr->data] > 0)
            {
                // node value found in list2
                if (IL == NULL)
                {
                    IL = curr;
                    it = IL;
                }
                else
                {
                    it->next = curr;
                    it = it->next;
                }
                map[curr->data]--;
            }
        }
        curr = curr->next;
    }
    if (it != NULL)
    {
        it->next = NULL;
    }
    return IL;
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
    Node* headA = NULL;
    Node* tailA = NULL;
    insertAtTail(headA, tailA, 9);
    insertAtTail(headA, tailA, 6);
    insertAtTail(headA, tailA, 4);
    insertAtTail(headA, tailA, 2);
    insertAtTail(headA, tailA, 3);
    insertAtTail(headA, tailA, 8);

    Node* headB = NULL;
    Node* tailB = NULL;
    insertAtTail(headB, tailB, 1);
    insertAtTail(headB, tailB, 2);
    insertAtTail(headB, tailB, 8);
    insertAtTail(headB, tailB, 6);

    cout << "List A: ";
    print(headA);
    cout << "List B: ";
    print(headB);

    Node* intersectNode = findIntersection(headA, headB);
    cout << "Intersection List: ";
    print(intersectNode);

    return 0;
}

// Time complexity: O(m+n)
// Auxiliary space: O(m+n)