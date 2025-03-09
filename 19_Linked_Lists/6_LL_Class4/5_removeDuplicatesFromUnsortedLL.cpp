/*
// 🔴🔴METHOD 1: Nested loop for curr node comparison with rest of the nodes🔴🔴

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

void removeDuplicatesFromUnsortedLL(Node* &head)
{
    Node* prev;
    Node* curr;
    Node* dup;
    prev = head;
    while(prev!=NULL && prev->next!=NULL)
    {
        curr = prev;
        while(curr->next != NULL)
        {
            if(prev->data == curr->next->data)
            {
                dup = curr->next;
                curr->next = curr->next->next;
                dup->next = NULL;
                delete dup;
            }
            else
            {
                curr = curr->next;
            }
        }
        prev = prev->next;
    }

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

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 10);
    cout << "Input LL:" << endl;
    print(head);

    removeDuplicatesFromUnsortedLL(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n^2)
// SC -> O(1)
*/
// __________________________________________________________________________________________________________

/*
// 🔴🔴METHOD 2:Sort the LL(merge sort LL), then remove the duplicate elements like in 2nd part of same folder 🔴🔴
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

Node *findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node *merge(Node *left, Node *right)
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

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Break LL into 2 halves using mid node
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // sort recursively
    left = sortList(left);
    right = sortList(right);

    // merge both left and right LLs
    Node *mergedLL = merge(left, right);
    return mergedLL;
}

void removeDuplicatesFromUnsortedLL(Node* &head)
{
    head = sortList(head);
    if(head == NULL)
    {
        cout << "LL is empty!" << endl;
        return;
    }
    if(head->next == NULL)
    {
        cout << "Single node in LL" << endl;
        return;
    }

    // now case for more than 1 node
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            // equal(duplicate) -> handle the pointers
            curr->next = curr->next->next;
           
            // delete node
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
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

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 10);
    cout << "Input LL:" << endl;
    print(head);

    removeDuplicatesFromUnsortedLL(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}
// TC -> O(nlogn)
// SC -> O(logn)
*/
// _________________________________________________________________________________________________________________

// 🔴🔴METHOD 3: Using set
#include <iostream>
#include <unordered_set>
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

void removeDuplicatesFromUnsortedLL(Node* &head)
{
    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        // if value found in set, means it exists before
        if(seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
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

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 10);
    cout << "Input LL:" << endl;
    print(head);

    removeDuplicatesFromUnsortedLL(head);
    cout << "Output LL:" << endl;
    print(head);

    return 0;
}

// TC -> O(n)
// SC -> O(n)