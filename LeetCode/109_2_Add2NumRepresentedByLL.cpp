// 🔴🔴LEETCODE 2 -> Add 2 numbers represented by LL🔴🔴
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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

// Node* reverse(Node* &head)
// {
//     if(head == NULL)
//     {
//         cout << "LL is empty!" << endl;
//         return NULL;
//     }

//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = curr->next;
//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }

Node* sumOfDigitsLL(Node* &head1, Node* &head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    // Step1: Reverse both LLs -> here they are already reversed
    // head1 = reverse(head1);
    // head2 = reverse(head2);
    int carry = 0;
    
    // Step2: Add both LLs
    Node* ansHead = NULL;
    Node* ansTail = NULL; 
    while(head1 != NULL && head2 != NULL)
    {
        // calculate sum
        int sum = head1->data + head2->data + carry;
        // find digit to create node
        int digit = sum % 10;
        // calculate carry
        carry = sum / 10;

        // create a new node for the digit
        Node* newNode = new Node(digit);

        // attach the new node into the ans wali LL
        if(ansHead == NULL)
        {
            // inserting the first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    } 

    // when len(head1) > len(head2)
    if(head1 != NULL)
    {
        while(head1 != NULL)
        {
            int sum = head1->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            Node* newNode = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head1 = head1->next;
        }
    }

    // when len(head2) > len(head1)
    if(head2 != NULL)
    {
        while(head2 != NULL)
        {
            int sum = head2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            Node* newNode = new Node(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head2 = head2->next;
        }
    }

    // handle carry ko alag se
    while(carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // Step3: Reverse the ans of the LL -> already the correct output
    // ansHead = reverse(ansHead);
    return ansHead;
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
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 9);
  
    insertAtTail(head2, tail2, 5);
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 9);

    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);

    Node* addedSum = sumOfDigitsLL(head1, head2);
    cout << "Total sum of the two lists: ";
    print(addedSum);

    return 0;
}
// TC -> O(n)
// SC -> O(1)