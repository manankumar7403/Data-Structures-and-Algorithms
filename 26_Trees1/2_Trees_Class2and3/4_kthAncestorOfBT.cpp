// 🔴🔴🔴🔴 Similar to previous question 🔴🔴🔴🔴
// Find the kth Ancestor of node p.
/*

Example 1:
       10
      /  \
    20    30
    / \     \
   40  50    60
   /   /     /  \
  70  80    90   100
     /  \
    110 120

Input: p = 120, k = 2
Output: 50
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

bool kthAncestor(Node *root, Node *p, int &k)
{
    // Base case
    if (root == NULL)
        return false; // root hai hi nhi toh seedha false return kardo

    // Check if where we are is the value of either p or q -> then that is a possible ancestor
    if (root->data == p->data)
        return true;

    // Now that we reached here, the ancestor node lies somewhere in the below subtrees
    bool leftAns = kthAncestor(root->left, p, k);
    bool rightAns = kthAncestor(root->right, p, k);

    // check karo ki left ya right me answer mila ki nahi
    if (leftAns == true || rightAns == true)
    {
        k--;
    }
    if (k == 0)
    {
        cout << "kth Ancestor of " << p->data << " is " << root->data << endl;
        k = -1;   // because if k==0 once, we set it to -1 so it doesn't remains 0 for any other case and prints a duplicate value
    }

    return leftAns || rightAns;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal of normal tree:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    int p_val, k;
    cout << "Enter the value of node p: ";
    cin >> p_val;
    cout << "Enter the value of k: ";
    cin >> k;
    
    Node *p = new Node(p_val);

    kthAncestor(root, p, k);

    return 0;
}

// TC -> O(n)
// SC -> O(h)