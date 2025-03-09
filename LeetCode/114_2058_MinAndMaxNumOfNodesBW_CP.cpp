// 🔴🔴LEETCODE 2058 -> Find the Minimum and Maximum Number Of Nodes Between Critical Points🔴🔴
/*
A critical point in a linked list is defined as either a local maxima or a local minima.
A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the
minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct
critical points. If there are fewer than two critical points, return [-1, -1].

Example 1:
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

Example 2:
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

Example 3:
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.

Constraints:
The number of nodes in the list is in the range [2, 10^5].
1 <= Node.val <= 10^5
*/

#include <iostream>
#include <vector>
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

vector<int> nodesBetweenCriticalPoints(Node* &head)
{
    vector<int> ans = {-1, -1}; // min dist, max dist
    Node *prev = head;
    if (prev == NULL)
        return ans;
    Node *curr = head->next;
    if (curr == NULL)
        return ans;
    Node *nxt = head->next->next;
    if (nxt == NULL)
        return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;
    while (nxt != NULL)
    {
        bool isCP = ((curr->data > prev->data && curr->data > nxt->data) ||
        (curr->data < prev->data && curr->data < nxt->data)) ? true : false;
        
        if (isCP & firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if (lastCP == firstCP)
    {
        // only 1 CP found
        return ans;
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
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

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);

    cout << "Original List:" << endl;
    print(head);

    vector<int> ans = nodesBetweenCriticalPoints(head);
    cout << "Minimum distance between CP: " << ans[0] << endl;
    cout << "Maximum distance between CP: " << ans[1] << endl;
    cout << endl;

    return 0;
}