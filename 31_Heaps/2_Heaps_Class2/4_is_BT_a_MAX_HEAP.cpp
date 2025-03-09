/*
// GFG
// Refer: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5, is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // Base case (we are using recursion to build the tree)
    if (data == -1)
    {
        return NULL;
    }

    // Step A: Create the root node
    Node *root = new Node(data);

    // Step B: Get the left node using recursion
    cout << "Enter data for the left part of " << data << " node:" << endl;
    root->left = buildTree();

    // Step C: Get the right node using recursion
    cout << "Enter data for the right part of " << data << " node:" << endl;
    root->right = buildTree();

    return root;
}

int countNodes(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node *root, int curr_index, int totalCount)
{
    if (root == NULL)
        return true;

    if (curr_index >= totalCount) // Matlab CBT nahi kyuki index out of range ja rha (chances are ki left se pehle right wala node laga diya)
    {
        return false;
    }

    else
    {
        // curr_index(current node) toh theek tha ab uska left aur right check karna hai
        bool left = isCBT(root->left, 2 * curr_index + 1, totalCount);
        bool right = isCBT(root->right, 2 * curr_index + 2, totalCount);
        return (left && right);
    }
}

// agar CBT hai tab hi ye neeche wale function tak pahuchenge honge warna isHeap function me isCBT false hai
// toh aage ka condition(&& isMaxOrder) dekhta hi nhi
// Agar CBT hai toh 3 cases ho sakte hai
// Leaf Node only, Only left child exists, Both child exists
bool isMaxOrder(Node *root)
{
    // Base Case
    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // Only left child exists
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    // Both child exists
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(Node *root)
{
    int curr_index = 0;
    int totalCount = countNodes(root);                           // Total nodes in the MAX HEAP
    if (isCBT(root, curr_index, totalCount) && isMaxOrder(root)) // BT ek heap tab hi hoga jab vo CBT(complete binary tree) hai aur Max Heap property ko follow karta hai
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    
    if(isHeap(root))
    {
        cout << "The given Binary Tree is a Max Heap!" << endl;
    }
    else
    {
        cout << "The given Binary Tree is not a Max Heap!" << endl;
    }
    return 0;
}

// TC -> O(N)
// SC -> O(N)