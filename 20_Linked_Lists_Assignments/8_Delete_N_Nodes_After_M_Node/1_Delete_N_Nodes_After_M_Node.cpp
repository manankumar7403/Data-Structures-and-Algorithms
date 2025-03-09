// GFG Question
/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6 

Output: 
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains a number
of elements in the linked list, and the next M and N respectively space-separated. The last line contains the elements of
the linked list.
Output:
The function should not print any output to the stdin/console.

Your Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Constraints:

1 <= size of linked list <= 1000
0 < M <= size of linked list
0 <= N <= size of linked list 
*/
// __________________________________________________________________________________________________________

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

void linkdelete(Node* &head, int M, int N)
{
    if (head == NULL) return;

    Node* it = head;
    for (int i = 0; i < M - 1; i++)
    {
        // if M nodes are N.A.
        if (it == NULL) return;
        it = it->next;
    }

    // it would be at Mth node
    if (it == NULL)
        return;

    Node *MthNode = it;
    it = MthNode->next;
    for (int i = 0; i < N; i++)
    {
        if (it == NULL)
            break;
        Node *temp = it->next;
        it->next = NULL;
        delete it;
        it = temp;
    }
    MthNode->next = it;
    linkdelete(it, M, N);
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

    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 1);

    int M, N;
    cout << "Enter how many nodes to skip:" << endl;
    cin >> M;
    cout << "Enter how many nodes to delete:" << endl;
    cin >> N;

    cout << "Original LL:" << endl;
    print(head);

    linkdelete(head, M, N);

    cout << "Output LL:" << endl;
    print(head);

    return 0;
}