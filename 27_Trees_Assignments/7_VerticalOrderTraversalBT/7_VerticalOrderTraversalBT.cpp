// 🔴🔴 LEETCODE 987: Vertical Order Traversal of a Binary Tree 🔴🔴
/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1)
respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the
leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case,
sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
*/
// _______________________________________________________________________________________________________________

#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<map>
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

class Solution
{
public:
    vector<vector<int>> verticalTraversal(Node *root)
    {
        vector<vector<int>> ans;
        queue<pair<Node *, pair<int, int>>> q; // Node, {row, col} (every node stored with row and col position in queue)
        q.push({root, {0, 0}});                    // root node is passed with (0,0) coordinates
        map<int, map<int, multiset<int>>> mp;      // col -> {row: {x,y,z...}}
        // acc to ex1: 0th column 1st row has 3, 2nd row has 15
        // acc to ex2: 0th column 1st row has 1, 2nd row has 5 and 6. To sort 5 and 6 (asc order) we are using multiset.
        // (A multiset automatically sorts its values in ascending order and keeps duplicates.)

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            Node *&node = front.first;
            auto &coordinate = front.second;
            int &row = coordinate.first;
            int &col = coordinate.second;
            mp[col][row].insert(node->data);
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        // Store final vertical order into ans vector
        for (auto it : mp)
        {
            auto &colMap = it.second;
            vector<int> vLine;
            for (auto colMapIt : colMap)
            {
                auto &mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
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
    vector<vector<int>> result = obj.verticalTraversal(root);

    cout << "\nThe vertical order traversal of the tree is:\n";
    for(auto& vec: result)
    {
        for(int val: vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

// TC -> O(nlogn), insertion into multiset is logn and traversing all nodes once(traversing and pushing/popping nodes in/from
// queue) is n -> so nlogn.
// SC -> O(n), storing in map, queue, and vector all are O(n) each, so asymptotically it is O(n).