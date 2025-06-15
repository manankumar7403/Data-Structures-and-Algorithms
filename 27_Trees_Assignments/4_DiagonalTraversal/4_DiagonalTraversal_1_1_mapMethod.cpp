// 🔴🔴Refer: https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1 🔴🔴

/*
Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a
binary tree belonging to same line.
If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then
right subtree. 

Examples :

Input : root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : [8, 10, 14, 3, 6, 7, 13, 1, 4]
Explanation:
unnamed
Diagonal Traversal of binary tree : 8 10 14 3 6 7 13 1 4

Input: root = [1, 2, N, 3, N]
                1
               /
              2
             /
            3
Output: [1, 2, 3]
Constraints:
1 <= number of nodes<= 105
1 <= node->data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/

// __________________________________________________________________________________

// Method-1: using map

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution{
public:
    void solve(Node* root, map<int, vector<int>>&mp, int d)
    {
        if(!root) return;

        mp[d].push_back(root->data);

        // Go left -> increase diagonal number
        solve(root->left, mp, d+1);

        // Go right -> same diagonal number
        solve(root->right, mp, d);
    }
    
    vector<int>diagonal(Node* root)
    {
        map<int, vector<int>>mp;
        solve(root, mp, 0);

        vector<int> ans;
        for(auto it: mp)
        {
            for(auto val: it.second)
            {
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// Function to build tree which is:
//✅ Done using level order traversal (implemented using a queue).
Node* buildTree()
{
    cout << "Enter data for nodes in level order(-1 for NULL)\n";

    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftVal;
        if(leftVal != -1)
        {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightVal;
        if(rightVal != -1)
        {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    Node* root = buildTree();

    Solution obj;
    vector<int> res = obj.diagonal(root);

    cout << "\nDiagonal Traversal: ";
    for(int val: res)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// TC -> O(nlogn)
// SC -> O(n)

/*
accessing mp[d] in a map is O(log n) because std::map is a balanced BST internally.
Thus for each node, insertion is O(log n).
Total nodes = n
Therefore, solve() total work = O(n log n)

Now after solve():
You have another loop:
for (auto it: mp) {
    for (auto val: it.second) {
        ans.push_back(val);
    }
}

It just traverses all nodes once to fill ans, so this is O(n).
Thus, overall TC = O(n log n)

// ------------------------------------------------------------------------------------

map<int, vector<int>> mp stores all nodes somewhere → O(n) space.
vector<int> ans also stores all nodes → O(n) space.
Recursion stack:
In the worst case (skewed tree), recursion depth = O(n).
In a balanced tree, recursion depth = O(log n).
Thus: Final SC = O(n)
*/