// 🔴🔴🔴🔴 LEETCODE 230 -> kth Smallest Element in a BST 🔴🔴🔴🔴
// Refer 28_BST -> 2_BST_Class2 -> 3_kthSmallestElementInBST.cpp
/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the
values of the nodes in the tree.
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4
*/
// _________________________________________________________________________________________________________

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

int kthSmallest(Node *root, int &k)
{
    if (root == NULL)
        // -1 reflects that base condition has been reached.
        return -1;

    // Inorder
    // L -> Left
    int leftAns = kthSmallest(root->left, k);

    if (leftAns != -1)
        return leftAns;

    // N -> Root
    k--;
    if (k == 0)
        return root->data;

    // R -> Right
    int rightAns = kthSmallest(root->right, k);
    return rightAns;
}

// Inorder(LNR) wala logic kyuki BST mein inorder sorted hota hai
// pehle left me check karo agar answer milta hai toh kyuki left mein BST me sabse smallest elements hai
// aur inorder (N) me k-- krte raho kyuki usually piche se -1 aa rha hoga toh k-- karke jab k=0 ho jaygea wahi ans hoga
// warna obviously right me answer hoga

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
    cout << "Enter the value of k:" << endl;
    cin >> k;
    int temp = k;
    int result = kthSmallest(root, k);
    cout << "The " << temp << " smallest element is: " << result << endl;

    return 0;
}