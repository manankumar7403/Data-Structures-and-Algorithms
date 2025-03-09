// Input: Inorder and Postorder Traversals.
// Build a tree using these traversals.
// Note: Inorder(LNR) and Postorder(LRN)

// inorder  = {40,20,10,50,30,60} (LNR)
// postorder = {40,20,50,60,30,10} (LRN)

// Ab dekho PostOrder me last me N hota hai yaani current node.
// Toh postOrder ka last element root node hai
// Ab inorder me is element ke left side me left subtree hoga aur right side me right subtree.

#include <iostream>
#include <queue>
#include <unordered_map>
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

// This is recursively called again and again -> use map instead to optimize(map uses O(1))
// Overall complexity after using map is prev TC + O(n)
// if findPosition is used then for every element findPosition is recursively called -> more TC
// int findPosition(int inorder[], int size, int element)
// {
//     for(int i=0; i<size; i++)
//     {
//         if(inorder[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// ✅ OPTIMIZATION FOR FIND ELEMENT FUNCTION
void createMapping(unordered_map<int, int>& mapping, int inorder[], int size)
{
    // Storing indexes of every element
    for(int i=0; i<size; i++)
    {
        mapping[inorder[i]] = i;
    }
}

// Build Tree from inorder and postorder traversal
// PostOrder is LRN and InOrder is LNR. The root node is last element of PostOrder so element just before that
// would be the next element you are dealing with, it is obviously present in the right subtree of the InOrder, so 
// we go from right to left.
Node *buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int size, int& postIndex, int inorderStart,
int inOrderEnd, unordered_map<int, int>& mapping)
// postIndex ko pass by reference kiya hai kyuki ek baar postIndex piche chala gya toh chala gya.
// Ab jaha khada hai uski aur uske piche ke nodes root nodes banenge.
// Agar pass by value karta toh aage aa jaata recursion ki wajah se toh similar repetitive nodes ban jaate.

{
    // Base Case
    if(postIndex < 0 || inorderStart > inOrderEnd)
    {
        return NULL;
    }

    // Step A: Create the root node using the first index(postIndex) of postOrder.
    // Ab is root node(element) ki position inOrder mein find karni hai jisse left Subtree 0 se lekar
    // element-1 index tak aa jaye aur element+1 index se size-1 tak right Subtree aa jaye
    // Toh inOrder me root node ki position find karne ke liye ek function banayenge -> findPosition
    int element = postorder[postIndex--];
    Node* root = new Node(element);

    // int pos = findPosition(inorder, size, element); // Not using -> using optimized approach instead
    int pos = mapping[element];

    // Step B: root->right solve karo
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, pos+1, inOrderEnd, mapping);

    // Step C: root->left solve karo
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, inorderStart, pos-1, mapping);

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

int main()
{
    int inorder[] = {40,20,10,50,30,60};
    int postorder[] = {40,20,50,60,30,10};
    int size = 6;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;

    unordered_map<int, int> mapping;
    createMapping(mapping, inorder, size);

    cout << "Building tree using inOrder and postOrder Traversal: " << endl;
    Node *root = NULL;
    root = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, inorderStart, inorderEnd, mapping);

    cout << endl;
    cout << "Level order traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
