// 🔴🔴🔴🔴  CREATION OF BST (Binary Search Tree) 🔴🔴🔴🔴

// Important
// ✅ Observation: inOrder Traversal of a BST is always sorted.

// insertion in BST (taking input from user)
// level, in, pre, post order traversals
// find node in BST (Searching)
// minimum value in BST
// maximum value in BST
// inorder successor for a given key in BST
// inorder predecessor for a given key in BST
// delete node in BST

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

void preOrderTraversal(Node* root)
{
    // NLR
    if(root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    // LRN
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* findNodeInBST(Node* root, int target)
{
    // Base Case
    if(root == NULL) return NULL;

    if(root->data == target)
    {
        return root;
    }

    if(target > root->data)
    {
        // right subtree me search karo
        return findNodeInBST(root->right, target);
    }

    else
    {
        // left subtree me search karo
        return findNodeInBST(root->left, target);
    }
}

int minVal(Node* root)
{
    Node* temp = root;
    
    if(temp == NULL)
    {
        return -1;
    }

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node* root)
{
    Node* temp = root;
    
    if(temp == NULL)
    {
        return -1;
    }

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

void findPredSucc(Node *root, Node *&pred, Node *&succ, int key)
{
    // Base Case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            pred = temp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        succ = root;
        findPredSucc(root->left, pred, succ, key);
    }
    else // go to right subtree
    {
        pred = root;
        findPredSucc(root->right, pred, succ, key);
    }
}

Node* deleteNodeInBST(Node* root, int target)
{
    // Base Case
    if(root == NULL) return NULL;

    // Step 1: Found the node to be deleted(standing on it)
    if(root->data == target)
    {
        // isi ko delete karna hai
        // 4 cases
        // Case 1: The target is a leaf node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: If root->left is NULL and root->right is NOT NULL
        else if(root->left == NULL && root->right != NULL)
        {
            Node* child = root->right;
            delete root;
            return child;
        }

        // Case 3: If root->left is NOT NULL and root->right is NULL
        else if(root->left != NULL && root->right == NULL)
        {
            Node* child = root->left;
            delete root;
            return child;
        }

        // Case 4: Both left and right are NOT NULL yaani dono child node exist karte hai
        // Toh ya toh left subtree me se inorder predecessor nikal ke usko jis node ko delete karna hai usse replace kardo, fir inorder predecessor ko delete kardo
        // ya fir right subtree me se inorder successor nikal ke replace karo fir inorder successor ko delete kardo
        // inorder predecessor of left subtree -> left subtree me max value
        else
        {
            // both child
            // find inOrder predecessor in left subtree
            int inOrderPre = maxVal(root->left);
            // replace root->data value with inOrder predecessor
            root->data = inOrderPre;
            // delete inorder predecessor from left subtree
            root->left = deleteNodeInBST(root->left, inOrderPre);  // ye toh obviously leaf node hi hoga toh ye upar Case 1 me delete ho jayega 
            return root;
        }
    }

    // Step 2: Target Nahi mila aur target > root->data toh right jayenge
    else if(target > root->data)
    {
        // right jana chahiye
        root->right =  deleteNodeInBST(root->right, target);
    }

    // Step 3: Target Nahi mila aur target < root->data toh left jayenge
    else if(target < root->data)
    {
        // left jana chahiye
        root->left = deleteNodeInBST(root->left, target);
    }

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

    cout << "Pre Order Traversal is: " << endl;
    preOrderTraversal(root);
    cout << endl << endl;

    cout << "Post Order Traversal is: " << endl;
    postOrderTraversal(root);
    cout << endl << endl;

    int target = 50;
    Node *result = findNodeInBST(root, target);
    if (result != NULL)
    {
        cout << "Node with value " << target << " found in the BST." << endl;
    }
    else
    {
        cout << "Node with value " << target << " not found in the BST." << endl;
    }
    cout << endl;

    cout << "Minimum value in BST: " << minVal(root) << endl << endl;

    cout << "Maximum value in BST: " << maxVal(root) << endl << endl;


    Node *pred = NULL;
    Node *succ = NULL;
    int key = 110;
    findPredSucc(root, pred, succ, key);
    if (pred != NULL)
        cout << "Inorder Predecessor of " << key << " is " << pred->data << endl;
    else
        cout << "No Predecessor of " << key << " exists." << endl;

    if (succ != NULL)
        cout << "Inorder Successor of " << key << " is " << succ->data << endl;
    else
        cout << "No Successor " << key << " exists." << endl;
    
    cout << endl;

    deleteNodeInBST(root, 100);

    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}