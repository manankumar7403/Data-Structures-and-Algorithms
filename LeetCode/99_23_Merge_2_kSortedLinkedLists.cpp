// 🔴🔴🔴🔴 LEETCODE 23 -> Merge k Sorted Linked Lists 🔴🔴🔴🔴
// Refer 31_Heaps -> 3_Class3 -> 2_Merge k Sorted Lists.cpp
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/
// _________________________________________________________________________________________________________

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Creating the Custom Comparator
class compare
{
    public:
        bool operator()(Node* a, Node* b)
        {
            return a->data > b->data;
        }
};

Node* mergeKSortedArrays(vector<Node*>& lists)
{
    // Creating Min Heap on our own custom comparator
    priority_queue<Node*, vector<Node*>, compare > minHeap;

    int k = lists.size();
    if(k == 0) return NULL;

    // har sorted LL ka first element insert karo
    // lists ka data type Node* pointer hai jo by default head ko point karta hai Linked List ke
    // isliye har Linked Lists ka pehla element hi minHeap me insert ho rha hai
    for(int i=0; i<k; i++)
    {
        if(lists[i] != NULL)
        {
            minHeap.push(lists[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!minHeap.empty())
    {
        Node* temp = minHeap.top();  // temp will never be null as we have checked lists[i] != NULL before inserting in minHeap
        minHeap.pop();

        // temp may or may not be the first element of answer linked list
        if(head == NULL)        // abhi tak koi element insert hi nahi hua
        {
            // temp -> first element of ans LL
            head = temp;
            tail = temp;
            if(tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }

        else
        {
            // temp is not the first element of LL
            tail->next = temp;
            tail = temp;
            if(tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}

int main()
{
    int k;
    cout << "Enter the number of sorted arrays: ";
    cin >> k;

    vector<Node*> lists;

    for (int i = 0; i < k; i++)
    {
        int size;
        cout << "Enter the size of array " << i + 1 << ": ";
        cin >> size;

        Node* head = NULL;
        Node* tail = NULL;

        cout << "Enter the elements of array " << i + 1 << " in sorted order: ";
        for (int j = 0; j < size; j++)
        {
            int element;
            cin >> element;

            Node* newNode = new Node(element);

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        lists.push_back(head);
    }

    Node* result = mergeKSortedArrays(lists);

    cout << "Merged sorted array: ";
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}

// TC -> O(nklogk)