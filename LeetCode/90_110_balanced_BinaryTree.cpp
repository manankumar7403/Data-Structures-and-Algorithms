// 🔴🔴🔴🔴 https://www.geeksforgeeks.org/types-of-binary-tree/  🔴🔴🔴🔴

// 🔴🔴🔴🔴 LEETCODE 110 -> Balanced Binary Tree 🔴🔴🔴🔴
// Refer 26_Trees1 -> 2_Trees_Class2and3 -> 1_balanced_BinaryTree.cpp
/*
Given a binary tree, determine if it is height-balanced (A height-balanced binary tree is a binary tree in which
the depth of the two subtrees of every node never differs by more than one.).

Example 1:
        3
      /   \
     9     20
          /  \
        15    7
Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:
        1
      /   \
     2     2
   /  \
  3    3
 / \
4   4

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/
// _______________________________________________________________________________________________________

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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);        // root ke left child se niche ki height
    int rightHeight = height(root->right);      // root ke right child se niche ki height
    int ans = max(leftHeight, rightHeight) + 1; // +1 because root se niche ki dekh rhe hai toh level 0(root) ki height add kardi
    return ans;
}

bool isBalanced(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return true; // node hi nahi hai toh balanced hoga
    }

    // 1 case solve kardo, baaki recursion sambhal lega
    int leftHeight = height(root->left);      // root ke left subtree ki height nikal li
    int rightHeight = height(root->right);    // root ke right subtree ki height nikali li
    int diff = abs(leftHeight - rightHeight); // absolute diff store kar liya
    bool ans1 = (diff <= 1);                  // agar difference more than 1 hai toh false aa jayega

    // Recursion
    bool leftAns = isBalanced(root->left);   // ab left side ke har ek node ke subtrees ki height nikal li
    bool rightAns = isBalanced(root->right); // right side ke har ek node ke subtrees ki height nikal li

    if (ans1 && leftAns && rightAns) // agar har node ke left aur right subtrees ki height ka diff <= 1 hai toh true
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
    Node *root = NULL;
    root = buildTree();

    cout << "Height of the tree is:" << endl;
    cout << height(root);
    cout << endl;

    if(isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}

// Time Complexity: O(n^2) -> memoization se improve hoke O(N) ho jayegi
// Space Complexity: O(h)