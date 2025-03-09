// ⭐⭐⭐⭐ Largest Binary Search Tree in a Binary Tree ⭐⭐⭐⭐
// ✅ This is the MOST IMPORTANT QUESTION OF TREES

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

class NodeData
{
    public:
    int size;
    int maxVal;
    int minVal;
    bool validBST;

    // Constructor
    NodeData()
    {

    }
    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        maxVal = max;
        minVal = min;
        validBST = valid;
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

NodeData* findLargestBST(Node* root, int& ans)
{
    // Base Case
    if(root == NULL)
    {
        NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData* leftKaAns = findLargestBST(root->left, ans);
    NodeData* rightKaAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData* currNodeKaAns = new NodeData();

    currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;     // left nodes + right nodes + khud ka size
    currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);      // max Value hamesha right subtree ki max value hoti hai BST mein
    currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);       // min Value hamesha left subtree ki min value hoti hai

    // agar (left subtree valid hai) and (right subtree valid hai) and
    // (root ka data leftAns ke maxVal se bada hai) -> toh baaki sab left subtree ke elements se bhi bada hoga
    // (root ka data rightAns ke minVal se chota hai) -> toh baaki sab right subtree ke elements se bhi chota hoga
    // toh currNodeKaAns ke validBST ko true mark kar denge
    if(leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal && root->data < rightKaAns->minVal))
    {
        currNodeKaAns->validBST = true;
    }
    else
    {
        currNodeKaAns->validBST = false;
    }

    if(currNodeKaAns->validBST)
    {
        ans = max(ans, currNodeKaAns->size);
    }
    return currNodeKaAns;
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal is: " << endl;
    inOrderTraversal(root);
    cout << endl << endl;

    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest size of BST is: " << ans << endl; 

    return 0;
}
