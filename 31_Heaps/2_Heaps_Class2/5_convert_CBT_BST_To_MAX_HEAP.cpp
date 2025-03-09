/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in
the left subtree of a node should be less than all the values in the right subtree of the node. This condition is
applied on all the nodes in the so converted Max Heap.

Example 1:
Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

*/
/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

vector<int> ans;
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    ans.push_back(root->data);
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    root->data = ans.back();
    ans.pop_back();
}

void convertToMaxHeapUtil(Node *root)
{
    inOrder(root);
    reverse(ans.begin(), ans.end()); // because accessing and popping the last value in a vector is a constant operation O(1)
    postOrder(root);
}

int main()
{
    Node *root = NULL;

    cout << "Enter the elements of the BST:" << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST before conversion to Max Heap:" << endl;
    levelOrderTraversal(root);

    convertToMaxHeapUtil(root);
    cout << endl;

    cout << "Level Order Traversal of the Max Heap:" << endl;
    levelOrderTraversal(root);

    return 0;
}
*/
// TC -> O(n)
// SC -> O(n)
// _______________________________________________________________________________________________________________

/*
✅ FURTHER OPTIMIZATION: If we change the inOrder traversal from LNR TO RLN, we will get the elements sorted in
descending order. So by that we won't need to reverse the ans array to get the elements from the back.
In simple words,
inOrder traversal normally -> 25 50 60 100 150 200 300
Reverse: 300 200 150 100 60 50 25
We need to reverse it to access the elements from the back to make sure it happens in constant time,
as we need to do postOrder Traversal to convert this from BST to MAX HEAP.

OPTIMIZATION:
Reverse Inorder Traversal -> 300 200 150 100 60 50 25
Now, we don't need to reverse it to access the elements from the back
*/

#include <iostream>
#include <queue>
#include <vector>
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

vector<int> ans;
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->right);
    ans.push_back(root->data);
    inOrder(root->left);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    root->data = ans.back();
    ans.pop_back();
}

void convertToMaxHeapUtil(Node *root)
{
    inOrder(root);
    postOrder(root);
}

int main()
{
    Node *root = NULL;

    cout << "Enter the elements of the BST:" << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST before conversion to Max Heap:" << endl;
    levelOrderTraversal(root);

    convertToMaxHeapUtil(root);
    cout << endl;

    cout << "Level Order Traversal of the Max Heap:" << endl;
    levelOrderTraversal(root);

    return 0;
}

// TC -> O(n)
// SC -> O(n)