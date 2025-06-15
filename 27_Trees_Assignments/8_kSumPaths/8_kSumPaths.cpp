// 🔴🔴 LEETCODE 437: Path Sum III 🔴🔴
/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the
path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent
nodes to child nodes).

Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 
Constraints:
The number of nodes in the tree is in the range [0, 1000].
-10^9 <= Node.val <= 10^9
-1000 <= targetSum <= 1000
*/
// _______________________________________________________________________________________________________________

/*
// Method 1: Trying to make the desired sum from each node (NOT OPTIMIZED)
#include<iostream>
#include<queue>
#include<vector>
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
    int ans = 0;
    void pathFromOneRoot(Node *root, long long sum)
    {
        if (!root)
            return;
        if (root->data == sum)
            ans++;                                     // is node pe sum ho gya poora, then this is one of the paths
        pathFromOneRoot(root->left, sum - root->data);  // warna left me check kiya sum me se current node ki val subtract krke
        pathFromOneRoot(root->right, sum - root->data); // warna right me check kiya sum me se current node ki val subtract krke
    }

    int pathSum(Node *root, long long targetSum)
    {
        if (root)
        {
            pathFromOneRoot(root, targetSum); // pehle root bhej diya hai and usse saare paths check kar liye
            pathSum(root->left, targetSum);   // then baaki bache hue nodes ko root bana ke pathFromOneRoot me bhej diya
            pathSum(root->right, targetSum);  // then baaki bache hue nodes ko root bana ke pathFromOneRoot me bhej diya
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
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    Solution obj;
    int ans = obj.pathSum(root, targetSum);

    cout << "\nThe number of paths possible for targetSum = " << targetSum << " is " << ans;
    cout << endl;
    return 0;
}

// TC -> O(n^2): The function pathSum is called once for each node (via recursion), and at each node, it calls pathFromOneRoot.
// pathFromOneRoot can also potentially visit every node in the tree in the worst case (i.e., a skewed tree), making it O(n) for a single call.
// So, TC becomes O(n) * O(n) = O(n^2)

// SC -> O(n): recursive call stack

*/

// -----------------------------------------------------------------------------------------------------------------------

// Method 2: Prefix sum + Hash Map (OPTIMIZED)
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
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
    int dfs(Node *node, long long currentSum, int targetSum, unordered_map<long long, int> &prefixSumCount)
    {
        if (!node)
            return 0;
        currentSum += node->data;
        int paths = 0;

        // Check if there is a prefix sum that makes currentSum - targetSum
        if (prefixSumCount.count(currentSum - targetSum)) // Is there a prefix sum of currentSum - targetSum so far?
        {
            paths += prefixSumCount[currentSum - targetSum]; // If so, how many times has it occurred?
        }
        // Add currentSum to the map
        prefixSumCount[currentSum]++;
        // Recurse to children
        paths += dfs(node->left, currentSum, targetSum, prefixSumCount);
        paths += dfs(node->right, currentSum, targetSum, prefixSumCount);
        // Backtrack: remove currentSum before returning to the parent
        prefixSumCount[currentSum]--;
        return paths;
    }

    int pathSum(Node *root, int targetSum)
    {
        unordered_map<long long, int> prefixSumCount; // stores prefixSum:count
        // prefixSum->sum of values from root to curr node, count is no. of times that exact sum has occurred on current DFS path
        prefixSumCount[0] = 1; // Base case: There exists one prefix path (an empty one, before we’ve started) that sums to 0.
        return dfs(root, 0, targetSum, prefixSumCount);
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
    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    Solution obj;
    int ans = obj.pathSum(root, targetSum);

    cout << "\nThe number of paths possible for targetSum = " << targetSum << " is " << ans;
    cout << endl;
    return 0;
}

/*
Let’s say you’re at the root and its value is equal to targetSum.
currentSum = root->val
currentSum - targetSum = 0
So, to detect that a path from the root to here (i.e. just the root) sums to targetSum,
we need to check:
paths += prefixSumCount[currentSum - targetSum];  // prefixSumCount[0]
If we didn’t initialize prefixSumCount[0] = 1, this path wouldn’t be counted.
*/

// TC -> O(n)
// SC -> O(n)