// 🔴🔴🔴🔴 LEETCODE 235 Lowest Common Ancestor of a BST 🔴🔴🔴🔴
// Refer 28_BST -> 2_BST_Class2 -> 2_LCA_BST.cpp
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given
nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is
defined between two nodes p and q as the lowest node in T that has both p and q as
descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.
*/
// _______________________________________________________________________________

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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // Base Case
    if (root == NULL)
        return NULL;

    // Case 1: Both p and q are smaller than the root
    if (p->data < root->data && q->data < root->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Case 2: Both p and q are greater than the root
    if (p->data > root->data && q->data > root->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Case 3: If p->data < root->data && q->data > root->data
    // Case 4: If p->data > root->data && q->data < root->data
    // where we are standing is the root
    return root;
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
    
    int p, q;
    cout << "Enter the values of nodes p and q:" << endl;
    cin >> p >> q;

    Node *nodeP = new Node(p);
    Node *nodeQ = new Node(q);

    Node *lca = lowestCommonAncestor(root, nodeP, nodeQ);

    if (lca)
    {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->data << endl;
    }
    else
    {
        cout << "Nodes " << p << " and " << q << " do not have a common ancestor." << endl;
    }

    // Remember to free the memory allocated for nodeP and nodeQ
    delete nodeP;
    delete nodeQ;

    return 0;
}