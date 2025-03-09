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

void printLeftBoundary(Node* root)
{
    // Base Case
    if(root == NULL) return;  // root is null, then go back
    if(root->left == NULL && root->right == NULL) return;  // leaf node, then go back

    cout << root->data << " ";
    if(root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root)
{
    // Base Case
    if(root == NULL) return;  // root is null, then go back
    if(root->left == NULL && root->right == NULL) // leaf node
    {
        cout << root->data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root)
{
    // Base Case
    if(root == NULL) return;  // root is null, then go back
    if(root->left == NULL && root->right == NULL) return;  // leaf node, then go back

    if(root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}
void boundaryTraversal(Node* root)
{
    // Base case
    if(root == NULL) return;

    // First print the root node
    cout << root->data << " ";

    // StepA: print the left nodes
    printLeftBoundary(root->left);
    // StepB: print the leaf nodes
    printLeafBoundary(root);
    // StepC: print the right nodes
    printRightBoundary(root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "Boundary traversal is:" << endl;
    boundaryTraversal(root);

    return 0;
}
