/*
// GFG Question
Given a Linked List of size n, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

Examples:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)

Expected Time Complexity: O(n * n * m)
Expected Auxiliary Space: O(n)

Constraints:
0 <= n <= 50
1 <= mi <= 20
1 <= Element of linked list <= 10^3
*/

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* bottom;

        // Constructor1: No data passed case
        Node()
        {
            this->data = 0;
            this->next = NULL;
            this->bottom = NULL;
        }

        // Constructor2: Data passed case
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->bottom = NULL;
        }

        // Constructor3: Taking in data and next node
        Node(int data, Node* next, Node* bottom)
        {
            this->data = data;
            this->next = next;
            this->bottom = bottom;
        }

        // Destructor: To delete the node(no need of destructor here though as we have not dynamically created a
        // memory in this class)
        ~Node()
        {
            cout << "Node with value: " << this->data << " deleted." << endl;
        }

};

void insertNext(Node* &head, int data)
{
    if(head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void insertAtBottom(Node* &head, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->bottom != NULL)
    {
        temp = temp->bottom;
    }
    temp->bottom = newNode;
}

Node* merge(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* ans = NULL;
    if(a->data < b->data)
    {
        ans = a;
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node *flatten(Node* &root)
{
   if(root == NULL) return NULL;
   // recursive solution se ulta merge hoga jisse ye fayda hai ki leftmost node ki taraf
   // se connection lose nahi hoga
   // 28 will be merged with NULL, result merged with 19, result merged with 10,
   // result merged with 5
   Node* mergedLL = merge(root, flatten(root->next));
   return mergedLL;
}

void print(Node* &head)
{
    Node* temp = head; 
    while(temp != NULL)
    {
        cout << temp->data << " ";  
        temp = temp->bottom;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;

    insertNext(head, 5);
    insertNext(head, 10);
    insertNext(head, 19);
    insertNext(head, 28);

    insertAtBottom(head, 7);
    insertAtBottom(head->bottom, 8);
    insertAtBottom(head->bottom->bottom, 30);
    insertAtBottom(head->next, 20);
    insertAtBottom(head->next->next, 22);
    insertAtBottom(head->next->next->bottom, 50);
    insertAtBottom(head->next->next->next, 35);
    insertAtBottom(head->next->next->next->bottom, 40);
    insertAtBottom(head->next->next->next->bottom->bottom, 45);

    head = flatten(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}