// ⭐⭐LEETCODE 1130 -> Minimum Cost Tree From Leaf Values⭐⭐
/*
Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.
It is guaranteed this sum fits into a 32-bit integer.
A node is a leaf if and only if it has zero children.\

Example1:
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44

Constraints:
2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 2^31).
*/
// ________________________________________________________________________________________________________________________
/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // Base Case
    if (left == right)
        return 0;

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                           solveUsingRecursion(arr, maxi, left, i) +
                           solveUsingRecursion(arr, maxi, i + 1, right));
    }
    return ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;    // coz unordered map doesn't support pair
    // pre-computation
    for (int i = 0; i < arr.size(); i++)
    {
        // pair<int, int>p;
        // p.first=i;
        // p.second=i;
        // maxi[p]=arr[i]; //these 4 lines are the same as maxi[{i,i}] = arr[i];
        maxi[{i, i}] = arr[i]; // from 1 to 1 the max value will be at index 1
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    int ans = solveUsingRecursion(arr, maxi, 0, n - 1);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans = mctFromLeafValues(arr);
    cout << "Smallest possible sum of the values of each non-leaf node: " << ans << endl;
    return 0;
}
*/

// _________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION (Top-Down)🔴🔴
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // Base Case
    if (left == right)
        return 0;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                           solveUsingMem(arr, maxi, left, i, dp) +
                           solveUsingMem(arr, maxi, i + 1, right, dp));
    }

    // Step3: Store the answer in dp array
    dp[left][right] = ans;
    return dp[left][right];
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi; // coz unordered map doesn't support pair
    // pre-computation
    for (int i = 0; i < arr.size(); i++)
    {
        // pair<int, int>p;
        // p.first=i;
        // p.second=i;
        // maxi[p]=arr[i]; //these 4 lines are the same as maxi[{i,i}] = arr[i];
        maxi[{i, i}] = arr[i]; // from 1 to 1 the max value will be at index 1
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    // Step1: Create the dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int ans = solveUsingMem(arr, maxi, 0, n - 1, dp);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans = mctFromLeafValues(arr);
    cout << "Smallest possible sum of the values of each non-leaf node: " << ans << endl;
    return 0;
}
*/

// _____________________________________________________________________________________________________________________

// 🔴🔴TABULATION (Bottom-Up)🔴🔴
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int solveUsingTab(vector<int> &arr, map<pair<int, int>, int> &maxi)
{
    int n = arr.size();
    // Step1: Create the dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Step2: Check the base case -> dp init with 0 only so base case doesn't really matter
    // if(left==right) return 0;

    // Step3: Main iteration logic
    for (int left = n - 1; left >= 0; left--) // mem and recursion left -> 0 to n-1, so opposite here
    {
        for (int right = 0; right <= n - 1; right++) // mem and recursion right -> n-1 to 0, so opposite here
        {
            if (left >= right)
                continue;
            else // valid range
            {
                int ans = INT_MAX;
                for (int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                                       dp[left][i] +
                                       dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n - 1];
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi; // coz unordered map doesn't support pair
    // pre-computation
    for (int i = 0; i < arr.size(); i++)
    {
        // pair<int, int>p;
        // p.first=i;
        // p.second=i;
        // maxi[p]=arr[i]; //these 4 lines are the same as maxi[{i,i}] = arr[i];
        maxi[{i, i}] = arr[i]; // from 1 to 1 the max value will be at index 1
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int ans = solveUsingTab(arr, maxi);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans = mctFromLeafValues(arr);
    cout << "Smallest possible sum of the values of each non-leaf node: " << ans << endl;
    return 0;
}