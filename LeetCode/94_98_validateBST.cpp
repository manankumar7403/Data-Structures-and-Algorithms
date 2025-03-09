// 🔴🔴🔴🔴 LEETCODE 98 -> Validate Binary Search Tree 🔴🔴🔴🔴
// Refer 28_BST -> 2_BST_Class2 -> 1_validateBST.cpp
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // Initially push the root
    q.push(root);
    q.push(NULL); // NULL depicts the end of the current level

    while (!q.empty())
    {
        // Step A:
        Node *temp = q.front();

        // Step B:
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            // Step C:
            cout << temp->data << " ";

            // Step D:
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// ✅ Observation: inOrder Traversal of a BST is always sorted.
void inOrderTraversal(Node* root)
{
    // LNR
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool solve(Node *root, long long int lb, long long int ub)
{
    // base case
    if (root == NULL)
        return true;

    if (root->data > lb && root->data < ub)
    {
        bool leftAns = solve(root->left, lb, root->data);
        bool rightAns = solve(root->right, root->data, ub);
        return leftAns && rightAns;
    }
    else
        return false;
}

bool isValidBST(Node *root)
{
    long long int lowerBound = LLONG_MIN;
    long long int upperBound = LLONG_MAX;
    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal is: " << endl;
    inOrderTraversal(root);
    cout << endl << endl;
    
    if(isValidBST(root))
    {
        cout << "The BST is valid!." << endl;
    }
    else
    {
        cout << "The BST is not valid." << endl;
    }

    return 0;
}

// ek aur tareeka ye hi hai ki inorder nikal lo fir check kar lo sorted hai ki nahi

// Is question me tree banane ke liye BST insertion wala nahi normal tree wala method use kar rhe hai
// kyuki BST wale method mein only valid BST insertions honge par is question me valid or invalid BST check
// karna hai