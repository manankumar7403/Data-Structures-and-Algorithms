// GFG
// Refer: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of
Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

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

int nodeCount(Node* root)
{
    if(root == NULL) return 0;
    int left = nodeCount(root->left);
    int right = nodeCount(root->right);
    return 1 + left + right;
}

bool isCBT(Node* root, int i, int& n)
{
    if(root == NULL) return true;
    if(i > n) return false;
    return isCBT(root->left, 2*i, n) && isCBT(root->right, 2*i+1, n);
}

// agar CBT hai tab hi ye neeche wale function tak pahuchenge honge warna isHeap function me isCBT false hai
// toh aage ka condition(&& isMaxOrder) dekhta hi nhi
// Agar CBT hai toh 3 cases ho sakte hai
// Leaf Node only, Only left child exists, Both child exists
bool isMaxOrder(Node *root)
{
    // Base case Leaf node
    if (root == NULL) return true;

    int left = isMaxOrder(root->left);
    int right = isMaxOrder(root->right);
    bool ans = false;

    // Left child and right child are NULL
    if (root->left == NULL && root->right == NULL)
    {
        ans = true;
    }

    // Left child exists but right child is NULL
    else if (root->left && root->right == NULL)
    {
        ans = root->data > root->left->data;
    }

    // Both child exists so have to check the Max Heap Property
    else
    {
        ans = root->data > root->left->data && root->data > root->right->data;
    }
    return ans && left && right;
}

bool isHeap(Node *tree)
{
    int n = nodeCount(tree);
    int i = 1;
    return isCBT(tree, i, n) && isMaxOrder(tree);
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
