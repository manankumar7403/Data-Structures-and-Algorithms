/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree
where value of each node will be the sum of the values of all the nodes in left and right sub trees of the
original tree. The values of leaf nodes are changed to 0.
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

*/
// _____________________________________________________________________________________________________

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

// in-place function
// Function with leaf nodes 0
int sumTreeLeafNode0(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftAns = sumTreeLeafNode0(root->left);
    int rightAns = sumTreeLeafNode0(root->right);
    int curr_data = root->data;
    root->data = leftAns + rightAns;
    return curr_data + leftAns + rightAns;
}

// in-place function
// Function with leaf nodes having their value only(current sum = current value as leftSum and rightSum = 0)
int sumTreeLeafNodeCurrentValue(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftAns = sumTreeLeafNodeCurrentValue(root->left);
    int rightAns = sumTreeLeafNodeCurrentValue(root->right);
    root->data = leftAns + rightAns + root->data;
    return root->data;
}


int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal of normal tree:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    // cout << endl;
    // cout << "Level order traversal of sum tree with leaf nodes 0:" << endl;
    // sumTreeLeafNode0(root);
    // levelOrderTraversal(root);
    // cout << endl;
    
    // do not run sumTreeLeafNode0 and sumTreeLeafNodeCurrentValue together as they are in-place functions, so the
    // function you call above in the main function will work correctly and update the values and the function you
    // call below that in the main function will work on the updated tree rather than the original tree.
    // So, comment and run one at a time.

    cout << endl;
    cout << "Level order traversal of sum tree with leaf nodes having current value:" << endl;
    sumTreeLeafNodeCurrentValue(root);
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

// Refer YT: https://www.youtube.com/watch?v=XpeA8w44xeo&t=373s