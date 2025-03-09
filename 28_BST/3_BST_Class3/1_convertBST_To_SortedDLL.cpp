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

Node* bstUsingInOrder(int inorder[], int start, int end)
{
    // Base Case
    if(start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstUsingInOrder(inorder, start, mid-1);
    root->right = bstUsingInOrder(inorder, mid+1, end);

    return root;
}

void convertIntoSortedDLL(Node* root, Node* &head)
{
    // Base Case
    if(root == NULL) return;

    // right subtree into DLL
    convertIntoSortedDLL(root->right, head);

    // attach root node
    root->right = head;

    if(head != NULL)
    {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree into DLL
    convertIntoSortedDLL(root->left, head);
}

// right subtree ko left subtree se pehle isliye solve kar rahe hai kyuki last me pahuch ke pichle node se connect
// karna hai toh pichle node ka track toh hai hi kyuki vo root node tha toh usko head banate raho...
// agar left subtree se chalu karta hai toh humare paas 1 2 3 4 ban ke aayega aur head 1 pe point karega par fir
// hum 4 ko 5 se kaise jodenge? uska pointer toh hai hi nahi. toh right subtree nahi dhund payenge aur uske liye
// ya toh ek extra pointer 'tail' lagega so woh method less optimized hai

void printDLL(Node* head)
{
    Node* temp = head;
    cout << endl;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    // Node *root = NULL;
    // cout << "Enter the data for Node: " << endl;
    // takeInput(root);

    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = 8;

    Node *root = NULL;
    root = bstUsingInOrder(inorder, start, end);
    
    cout << "Level order traversal is:" << endl; 
    levelOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal is: " << endl;
    inOrderTraversal(root);
    cout << endl << endl;

    cout << "Printing the sorted DLL:";
    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    printDLL(head);

    return 0;
}

// TC -> O(n)
// SC -> O(n)