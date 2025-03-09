// 🔴🔴🔴🔴 LEETCODE 653 -> Two Sum IV - Input is a BST 🔴🔴🔴🔴
// Refer 28_BST -> 2_BST_Class2 -> 5_twoSumIV_BST.cpp
/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST
such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
root is guaranteed to be a valid binary search tree.
-10^5 <= k <= 10^5
*/

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

    // Destructor
    ~Node()
    {
        // Recursive deletion of left and right subtrees
        delete left;
        delete right;
    }
};

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not the first node
    if(root->data > data) // root ka data ab jo input me data aaya usse bada hai toh left me insert karna hai
    {
        // insert to left
        root->left = insertIntoBST(root->left, data);
    }

    else
    {
        // insert to right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

void storeInorder(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    // Inorder Logic: LNR
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    storeInorder(root, inorder);

    // inorder sorted array mil gya ab ispe 2 pointers laga ke sum karke check karlo if any 2 num ka sum = k
    int start = 0;
    int end = inorder.size() - 1;
    while (start < end)
    {
        int sum = inorder[start] + inorder[end];
        if (sum == k)
        {
            return true;
        }
        if (sum > k)
            end--; // sum bada hai target se toh badi value(arr ke end element) ko piche lao
        else
            start++; // sum chota hai target se toh choti value(arr ka start element) ko aage badhao to increase it
    }
    return false; // koi possible solution nahi mila toh false return kardo
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node: " << endl;
    takeInput(root);

    cout << endl;
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal is: " << endl;
    inOrderTraversal(root);
    cout << endl << endl;
    
    int k;
    cout << "Enter the value of sum(k):" << endl;
    cin >> k;
    if(findTarget(root, k))
    {
        cout << "Target sum available." << endl;
    }
    else
    {
        cout << "Target sum not available." << endl;
    }
    return 0;
}

// pehle inorder store kara lo ek vector array me fir 2 pointer approach ka use karke dekh lo if sum of two numbers is equal
// to k (inorder sorted array hota hai BST ka)

// TC -> O(n)
// SC -> O(n)