// 🔴🔴Refer: https://www.geeksforgeeks.org/problems/transform-to-sum-tree--170645/1 🔴🔴
/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where value of each
node will be the sum of the values of all the nodes in left and right sub trees of the original tree. The values of leaf nodes
are changed to 0.
Note: You have to modify the given tree in-place.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
      8    -4   7    5
Output:
            20
          /     \
        4        12
       /  \     /  \
     0     0   0    0
Explanation:
           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
Example 2:

Input:
            10
        /        \
      -2           6
     /   \        /  \
    8    -4      7     5
    / \   / \    / \   / \
  2  -2 3  -5  9  -8 2   8
Output:
            29
        /        \
       2          23
     /  \        /  \
    0   -2      1    10
   / \  / \    / \   / \
   0  0 0   0  0   0 0   0
Explanation:
                 (-2+6+8-4+7+5+2-2+3-5+9-8+2+8)
               /                                \
          (8-4+2-2+3-5)                    (7+5+9-8+2+8)
          /      \                            /      \       
       (2-2)   (3-5)                        (9-8)    (2+8)
        /     \  /    \                      /     \   /     \
       0      0 0      0                   0        0 0       0

Your Task: 
You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^4
*/

// __________________________________________________________________________________________________________________


#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
        {
            // leaf node
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int lsum = sum(root->left);
        int rsum = sum(root->right);
        int temp = root->data;
        root->data = lsum + rsum;
        return root->data + temp;
    }

    void toSumTree(Node *node)
    {
        sum(node);
    }
};

// Function to build tree which is:
//✅ Done using level order traversal (implemented using a queue).
Node* buildTree()
{
    cout << "Enter data for nodes in level order(-1 for NULL)\n";

    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftVal;
        if(leftVal != -1)
        {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightVal;
        if(rightVal != -1)
        {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

void inOrderTraversal(Node* root)
{
    if(!root) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node* root = buildTree();

    Solution obj;
    obj.toSumTree(root);

    cout << "\nThe inorder traversal of the transformed sum tree is:\n";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}

// TC -> O(n) as every node is visited only once
// SC -> O(h) where h is the height of the tree (due to recursive stack space)