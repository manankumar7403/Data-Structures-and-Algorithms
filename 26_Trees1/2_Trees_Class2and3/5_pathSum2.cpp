// 🔴🔴🔴🔴 LEETCODE 113 -> Path Sum 2 🔴🔴🔴🔴
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node
values in the path equals targetSum. Each path should be returned as a list of the node values, not node
references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no
children.

Example 1:
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \    / \
  7    2  5   1
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
        1
       /  \
      2    3
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
            if (!q.empty())
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

void solve(Node* root, int targetSum, int &currSum, vector<int> &path, vector<vector<int>> &ans)
{
    // Base Case
    if (root == NULL)
        return;

    // ek case solve kar rhe hai leaf node wala baaki recursion aur backtracking sambhal lenge
    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        // include current node
        path.push_back(root->data);
        currSum = currSum + root->data;

        // check for target sum
        if (currSum == targetSum)
        {
            ans.push_back(path);
        }

        // exclude to check for other possible solutions from previous nodes
        path.pop_back();
        currSum = currSum - root->data;
        return;
    }

    // include current node -> normal tareeka hai currNode ko include karte raho
    path.push_back(root->data);
    currSum = currSum + root->data;

    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // backtracking -> exclude if not getting the targetSum
    path.pop_back();
    currSum = currSum - root->data;
}

vector<vector<int>> pathSum(Node* root, int targetSum)
{
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> path;
    solve(root, targetSum, sum, path, ans);
    return ans;
}

// solve function logic:
// Null node par kuch nahi ho sakta toh seedha return kar diya.
// Agar leaf node par ho, toh sabse pehle us leaf node ko include karo currSum ke andar aur path ke andar fir check karo agar target sum ke equal hua currSum toh us final path ko answer me store karlo. Fir leaf node ko currSum aur path me se remove karo jisse previous node se dusre combinations check ho sake.

// include current node
        // path.push_back(root->val);
        // currSum = currSum + root->val;
// normal node ke value ko currSum me jodte raho aur path banate raho.

// Fir left aur right me call marke dekhte raho agar currSum == targetSum hota hai toh store karlo path
// warna backtracking karo aur jo last node ka value path me aur currSum me add kiya tha use remove kardo to check for other possible solutions


int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal of normal tree:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    int targetSum;
    cout << "Enter the target sum: " << endl;
    cin >> targetSum;

    vector<vector<int> > result = pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":" << endl;
    for(auto path: result)
    {
        cout << "[ ";
        for(int value: path)
        {
            cout << value << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}

// TC -> O(n)
// SC -> O(n)