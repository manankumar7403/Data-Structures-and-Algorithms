// 🔴🔴LEETCODE 160 -> Intersection of 2 Linked Lists🔴🔴
/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.
Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):
intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your
program. If you correctly return the intersected node, then your solution will be accepted.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the
intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B
(2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in
memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

Example 2:
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the
intersected node in A; There are 1 node before the intersected node in B.

Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not
intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

Constraints:
The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 10^4
1 <= Node.val <= 10^5
0 <= skipA < m
0 <= skipB < n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.

Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?
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

Node *getIntersectionNode(Node* &headA, Node* &headB)
{
    Node *a = headA;
    Node *b = headB;
    // if both of the LL are equal it will return the node at which a and b meet (intersection node)
    while (a->next != NULL && b->next != NULL)
    {
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }

    // if both have reached the end and there is no intersection point, return NULL
    if (a->next == NULL && b->next == NULL && a != b)
    {
        return NULL;
    }

    // if a has reached the end but b has not, calculate the length by which b is bigger
    if (a->next == NULL && b->next != NULL)
    {
        // b is bigger
        int blen = 0;
        while (b->next != NULL)
        {
            blen++;
            b = b->next;
        }
        // move the headB to the no of times it is bigger than LL a so when we traverse, it will intersect with a at some point
        while (blen--)
        {
            headB = headB->next;
        }
    }

    // if b has reached the end but a has not, calculate the length by which a is bigger
    else if (b->next == NULL && a->next != NULL)
    {
        // a is bigger
        int alen = 0;
        while (a->next != NULL)
        {
            alen++;
            a = a->next;
        }
        // move the headA to the no of times it is bigger than LL b so when we traverse, it will intersect with b at some point
        while (alen--)
        {
            headA = headA->next;
        }
    }

    // now headA and headB stand at their respective points where they are equal in dist from their ends, they will meet at some point
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
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
    insertAtTail(headA, tailA, 4);
    insertAtTail(headA, tailA, 1);

    Node* headB = NULL;
    Node* tailB = NULL;
    insertAtTail(headB, tailB, 5);
    insertAtTail(headB, tailB, 6);
    insertAtTail(headB, tailB, 1);

    Node* intersection = new Node(8);
    tailA->next = intersection;
    tailB->next = intersection;
    Node* tailIntersection = intersection;

    insertAtTail(tailIntersection, tailIntersection, 4);
    insertAtTail(tailIntersection, tailIntersection, 5);

    cout << "List A: ";
    print(headA);
    cout << "List B: ";
    print(headB);

    Node* intersectNode = getIntersectionNode(headA, headB);
    if (intersectNode)
        cout << "Intersection node is " << intersectNode->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

// TC -> O(m+n)
// SC -> O(1)