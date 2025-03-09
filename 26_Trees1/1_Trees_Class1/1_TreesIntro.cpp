// ⭐⭐⭐⭐ Types of Trees in DSA: https://www.geeksforgeeks.org/types-of-trees-in-data-structures/

// Tree is a non-linear data structure.
// with 0,1,2 child -> it is a Binary Tree

// 🔴🔴🔴🔴 This intro(everything present here) is only regarding Binary Tree 🔴🔴🔴🔴
// Learning to build a tree recursively.
// ⭐⭐⭐⭐ Using level order traversal to traverse through the tree -> Using queue (VERY IMPORTANT) 🔴🔴
// inOrder traversal using recursion
// preOrder traversal using recursion
// postOrder traversal using recursion
// height of the tree
// Diameter of the tree

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

// inOrder traversal using recursion
void inOrderTraversal(Node* root)   // LNR(Left Current Right)
{
    // Base Case
    if(root == NULL)
    {
        return;
    }

    // LNR(Left Current Right)
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// preOrder traversal using recursion
void preOrderTraversal(Node* root)   // NLR(Current Left Right)
{
    // Base Case
    if(root == NULL)
    {
        return;
    }

    // NLR(Current Left Right)
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// postOrder traversal using recursion
void postOrderTraversal(Node* root)   // LRN(Left Right Current)
{
    // Base Case
    if(root == NULL)
    {
        return;
    }

    // LRN(Left Right Current)
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);   // root ke left child se niche ki height
    int rightHeight = height(root->right); // root ke right child se niche ki height
    int ans = max(leftHeight, rightHeight) + 1; // +1 because root se niche ki dekh rhe hai toh level 0(root) ki height add kardi
    return ans;
}

int diameter(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);  // ya toh maximum diameter b/w two nodes left me hoga root node ke, excluding root node
    int op2 = diameter(root->right);  // ya toh maximum diameter b/w two nodes right me hoga root node ke, excluding root node
    int op3 = height(root->left) + height(root->right);  // left aur right ko include karke, root node bhi included ho sakta
    int ans = max(op1, max(op2, op3));
    return ans;

    // op1 hum root ke left part me dekh rhe bas aur waha se edges nikal jayenge maximum b/w two nodes(using height function)
    // op2 hum root ke right part me dekh rhe bas aur waha se edges nikal jayenge maximum b/w two nodes(using height function)
    // op3 left aur right ko milake check kar rhe (root included) 
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "In order traversal is:" << endl; 
    inOrderTraversal(root);
    cout << endl << endl;

    cout << "Pre order traversal is:" << endl; 
    preOrderTraversal(root);
    cout << endl << endl;

    cout << "Post order traversal is:" << endl; 
    postOrderTraversal(root);
    cout << endl << endl;

    cout << "Height of the tree is:" << endl; 
    cout << height(root);
    cout << endl << endl;

    cout << "Max diameter between two nodes of the tree is:" << endl; 
    cout << diameter(root);
    cout << endl << endl;

    return 0;
}
