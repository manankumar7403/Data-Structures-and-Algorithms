// Input: Inorder and Preorder Traversals.
// Build a tree using these traversals.
// Note: Inorder(LNR) and Preorder(NLR)

// inorder  = {40,20,50,10,60,30,70} (LNR)
// preorder = {10,20,40,50,30,60,70} (NLR)


// Ab dekho PreOrder me sabse pehle N hota hai yaani current node.
// Toh preOrder ka first element root node hai
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

// Build Tree from inorder and preorder traversal
Node *buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int& preIndex, int inorderStart,
int inOrderEnd, unordered_map<int, int>& mapping)
// preIndex ko pass by reference kiya hai kyuki ek baar preIndex aage chala gya toh vo aage chala gya.
// Ab jaha khada hai uski aur uske aage ke nodes root nodes banenge.
// Agar pass by value karta toh piche aa jaata recursion ki wajah se toh similar repetitive nodes ban jaate.

{
    // Base Case
    if(preIndex >= size || inorderStart > inOrderEnd)
    {
        return NULL;
    }

    // Step A: Create the root node using the first index(preIndex) of preOrder.
    // Ab is root node(element) ki position inOrder mein find karni hai jisse left Subtree 0 se lekar
    // element-1 index tak aa jaye aur element+1 index se size-1 tak right Subtree aa jaye
    // Toh inOrder me root node ki position find karne ke liye ek function banayenge -> findPosition
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    // int pos = findPosition(inorder, size, element);  // Not using -> using optimized approach instead
    int pos = mapping[element];

    // Step B: root->left solve karo
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos-1, mapping);

    // Step C: root->right solve karo
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inOrderEnd, mapping);
    
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
    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;

    unordered_map<int, int> mapping;
    createMapping(mapping, inorder, size);

    cout << "Building tree using inOrder and PreOrder traversal: " << endl;
    Node *root = NULL;
    root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd, mapping);

    cout << endl;
    cout << "Level order traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
