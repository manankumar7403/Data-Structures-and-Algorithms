// 🔴🔴🔴🔴 LEETCODE 543 -> Diameter Of Binary Tree 🔴🔴🔴🔴
// Refer 26_Trees1 -> 1_Trees_Class1 -> 1_TreesIntro.cpp -> diameter function
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may
or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
           1
        /     \
      2        3
    /  \
  4     5

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100

*/
// _____________________________________________________________________________________________________________

// Using recursive method to build the tree to find the diameter

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

int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = maxDepth(root->left);      // root ke left child se niche ki height
    int rightHeight = maxDepth(root->right);    // root ke right child se niche ki height
    int ans = max(leftHeight, rightHeight) + 1; // +1 coz root se niche ki dekh rhe hai toh level 0(root) ki height add kardi
    return ans;
}

int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = maxDepth(root->left) + maxDepth(root->right);
    int ans = max(op1, max(op2, op3));
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << "Height of the tree is:" << endl;
    cout << maxDepth(root);
    cout << endl
         << endl;

    cout << "Diameter of the tree is:" << endl;
    cout << diameterOfBinaryTree(root);
    cout << endl << endl;
    return 0;
}

// Time Complexity: O(n^2) (can be optimized to O(n) with memoization)
// Space Complexity: O(n)
