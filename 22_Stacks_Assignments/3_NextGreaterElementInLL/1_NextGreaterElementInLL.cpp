// 🔴🔴LEETCODE 1019 -> Next Greater Node in Linked List🔴🔴
/*
You are given the head of a linked list with n nodes.
For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first
node that is next to it and has a strictly larger value than it.
Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed).
If the ith node does not have a next greater node, set answer[i] = 0.

Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 
Constraints:
The number of nodes in the list is n.
1 <= n <= 10^4
1 <= Node.val <= 10^9
*/

#include <iostream>
#include <vector>
#include <stack>
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

vector<int> nextLargerNodes(Node* &head)
{
    vector<int> ll;
    while (head != NULL)
    {
        ll.push_back(head->data);
        head = head->next;
    }
    stack<int> st;
    for (int i = 0; i < ll.size(); i++)
    {
        while (!st.empty() && ll[i] > ll[st.top()])
        {
            // means ith element is the next greater of the element index present inside the stack;
            int kids = st.top();
            st.pop();
            ll[kids] = ll[i];
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ll[st.top()] = 0;
        st.pop();
    }
    ll[ll.size() - 1] = 0;
    return ll;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 5);
    cout << "Input LL:" << endl;
    print(head);
    
    cout << "Next greater elements:" << endl;
    vector<int> ans = nextLargerNodes(head);
    for(int i: ans)
    {
        cout << i << " ";
    }

    return 0;
}