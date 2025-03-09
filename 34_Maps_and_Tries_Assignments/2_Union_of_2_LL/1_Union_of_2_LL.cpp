// GFG
/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked
lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 

Example 2:
Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of
the new list.
Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

Constraints:
1<=N,M<=10^4
*/

#include <iostream>
#include<map>
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

Node* makeUnion(Node* &head1, Node* &head2)
{
    map<int, Node *> myMap;
    Node *curr = head1;

    // L1 hashed
    while (curr != NULL)
    {
        myMap[curr->data] = curr;
        curr = curr->next;
    }

    curr = head2;

    // L2 hashed
    while (curr != NULL)
    {
        myMap[curr->data] = curr;
        curr = curr->next;
    }

    Node *UL = NULL;
    curr = NULL;
    // iterate Map and make final union list (UL)
    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (UL == NULL)
        {
            UL = it->second;
            curr = UL; // curr is now UL's head
        }
        else
        {
            curr->next = it->second;
            curr = curr->next;
        }
    }
    curr->next = NULL;
    return UL;
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
    insertAtTail(headB, tailB, 2);

    cout << "List A: ";
    print(headA);
    cout << "List B: ";
    print(headB);

    Node* unionNode = makeUnion(headA, headB);
    cout << "Union List without duplicates: ";
    print(unionNode);

    return 0;
}