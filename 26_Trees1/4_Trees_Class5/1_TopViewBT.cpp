#include <iostream>
#include <queue>
#include <map>
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

void printTopView(Node* root)
{
    if(root == NULL) return;

    // EK map bana rhe hai jiske horizontal distance ke corresponding topNode->data store kar rhe hai
    //  hd    data
    map<int, int> topNode;
    // Level order
    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));  // node (root) aur horizontal distance

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aaya hai, check if answer for that hd already exists or not
        if(topNode.find(hd) == topNode.end())      // check karte karte end tak pahuch gye matlab exist nahi karta
        {
            // create entry
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right) q.push(make_pair(frontNode->right, hd+1));
    }

    // ab aapka answer store hua hoga map mein
    cout << "Printing the answer: " << endl;
    for(auto i: topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    cout << endl;
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    printTopView(root);

    return 0;
}
