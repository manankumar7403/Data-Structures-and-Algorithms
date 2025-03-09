// 🔴🔴LEETCODE 138 -> Copy List With Random Pointer🔴🔴
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any
node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has
its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should
point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list
state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two
nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of
[val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not
point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Constraints:
0 <= n <= 1000
-10^4 <= Node.val <= 10^4
Node.random is null or is pointing to some node in the linked list.
*/
// _________________________________________________________________________________________________________
// 🔴🔴METHOD1: Using unordered map🔴🔴
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* random;

        // Constructor1: No data passed case
        Node()
        {
            this->data = 0;
            this->next = NULL;
            this->random = NULL;
        }

        // Constructor2: Data passed case
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }

        // Constructor3: Taking in data and next node
        Node(int data, Node* next, Node* random)
        {
            this->data = data;
            this->next = next;
            this->random = random;
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

Node *helper(Node *&head, unordered_map<Node *, Node *> &mp)
{
    if (head == NULL)
        return NULL;
    Node *newHead = new Node(head->data);
    mp[head] = newHead;
    newHead->next = helper(head->next, mp);

    if (head->random)
    {
        newHead->random = mp[head->random];
    }
    return newHead;
}

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp; // old node -> new node(same) ki mapping
    return helper(head, mp);
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

    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 13);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    cout << "Original List:" << endl;
    print(head);

    Node* copiedList = copyRandomList(head);

    cout << "Copied LL:" << endl;
    print(copiedList);

    return 0;
}

// TC -> O(n)
// SC -> O(n)
*/
// ___________________________________________________________________________________________________________

// 🔴🔴METHOD2: Without Using unordered map🔴🔴

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* random;

        // Constructor1: No data passed case
        Node()
        {
            this->data = 0;
            this->next = NULL;
            this->random = NULL;
        }

        // Constructor2: Data passed case
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }

        // Constructor3: Taking in data and next node
        Node(int data, Node* next, Node* random)
        {
            this->data = data;
            this->next = next;
            this->random = random;
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

Node *helper(Node *&head)
{
    if (head == NULL)
        return NULL;

    // Step1: Clone A -> A'
    Node *it = head; // iterate over old head
    while (it != NULL)
    {
        Node *clonedNode = new Node(it->data);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    // Step2: Assign random links of A' with the helper pf old node
    it = head;
    while (it != NULL)
    {
        Node *clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next : nullptr;
        it = it->next->next;
    }

    // Step3: Detach A' from the modified LL
    it = head;
    Node *clonedHead = it->next;
    while (it != NULL)
    {
        Node *temp = it->next;
        it->next = it->next->next;
        if (temp->next)
        {
            temp->next = temp->next->next;
        }
        it = it->next;
    }
    return clonedHead;
}

Node *copyRandomList(Node *head)
{
    return helper(head);
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

    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 13);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    cout << "Original List:" << endl;
    print(head);

    Node* copiedList = copyRandomList(head);

    cout << "Copied LL:" << endl;
    print(copiedList);

    return 0;
}

// TC -> O(n)
// SC -> O(1)