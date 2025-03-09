/*
🔴🔴🔴🔴 LEETCODE 958 -> Check Completeness of a Binary Tree 🔴🔴🔴🔴
Refer 31_Heaps -> 2_Heaps_Class2 -> 6_Check_BT_is_CBT.cpp

Given the root of a binary tree, determine if it is a complete binary tree.
In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last
level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.
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

// ⭐⭐⭐⭐ Using level order traversal to traverse through the tree -> Using queue (VERY IMPORTANT) 🔴🔴
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

int countNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(Node* root, int curr_index, int totalNodes)
{
    if(root == NULL) return true;

    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if(curr_index >= totalNodes)
    {
        return false;
    }

    // Recursion for left and right subtrees
    return (isComplete(root->left, 2*curr_index+1, totalNodes) &&
            isComplete(root->right, 2*curr_index+2, totalNodes));
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    int curr_index = 0;
    int totalNodes = countNodes(root);

    cout << endl;
    cout << "Level order traversal is:" << endl;
    levelOrderTraversal(root);
    cout << endl << endl;

    if(isComplete(root, curr_index, totalNodes))
    {
        cout << "The Binary Tree is a Complete Tree!" << endl;
    }
    
    else
    {
        cout << "The Binary Tree is not a Complete Tree!" << endl;
    }

    return 0;
}

// Time Complexity: O(N) where N is the number of nodes in the tree.
// Space Complexity: O(h) where h is the height of given tree due to recursion call.

