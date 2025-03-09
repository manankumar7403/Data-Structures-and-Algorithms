// 🔴🔴🔴🔴 VERY IMPORTANT QUESTION 🔴🔴🔴🔴
// 🔴🔴🔴🔴 LEETCODE 236 -> Lowest Common Ancestor of Binary Tree 🔴🔴🔴🔴
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of
itself).”

Example 1:
       3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
       3
      / \
     5   1
    / \ / \
   6  2 0  8
     / \
    7   4

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA
definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/
// ______________________________________________________________________________________________________________

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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // Base case
    if (root == NULL)
        return NULL; // root hai hi nhi toh seedha NULL return kardo

    // Check if where we are is the value of either p or q -> then that is a possible ancestor
    if (root->data == p->data)
        return p;
    if (root->data == q->data)
        return q;

    // Now that we reached here, the ancestor node lies somewhere in the below subtrees
    Node *leftAns = lowestCommonAncestor(root->left, p, q);
    Node *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL) return NULL;
    else if (leftAns != NULL && rightAns == NULL) return leftAns;
    else if (leftAns == NULL && rightAns != NULL) return rightAns;
    // If all above conditions are false then the current node is the LCA
    // leftAns != NULL && rightAns != NULL
    else return root;
}

// Agar null mil rha hai toh upar null return kardo(recursion)
// Agar root ki val p ya q ke equal hai toh vo node(p or q) return kar do upar(recursion)
// Agar left aur right dono se null mil rha hai matlab niche answer nahi hai -> upar null return kardo(recursion)
// Agar left se answer mil rha hai(p or q) aur right se null mil rha hai toh left wale node ko upar bhej do(recursion)
// Agar left se null mil rha hai aur right se answer mil rha hai(p or q) toh right wale node ko upar bhej do(recursion)
// Agar left aur right dono se answer mil rha hai(p and q) toh jis node pe khade ho(root) wahi LCA hai -> return root

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal of normal tree:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    int p_val, q_val;
    cout << "Enter the value of node p: ";
    cin >> p_val;
    cout << "Enter the value of node q: ";
    cin >> q_val;

    Node *p = new Node(p_val);
    Node *q = new Node(q_val);

    Node *lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
    {
        cout << "The LCA of nodes " << p_val << " and " << q_val << " is: " << lca->data << endl;
    }
    else
    {
        cout << "No LCA found for nodes " << p_val << " and " << q_val << endl;
    }    

    return 0;
}

// For LCA function:
// TC -> O(n)
// SC -> O(h)