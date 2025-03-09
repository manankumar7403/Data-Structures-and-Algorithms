// ⭐⭐LEETCODE 354 -> Russian Doll Envelopes⭐⭐
/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's
width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:
1 <= envelopes.length <= 10^5
envelopes[i].length == 2
1 <= wi, hi <= 10^5
*/
// ____________________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingRecursion(vector<vector<int>> &env, int curr, int prev)
{
    // Base condition
    if (curr >= env.size())
        return 0;

    // include
    int include = 0;
    if (prev == -1 || env[curr][0] > env[prev][0] && env[curr][1] > env[prev][1])
    {
        include = 1 + solveUsingRecursion(env, curr + 1, curr);
    }
    // exclude
    int exclude = 0 + solveUsingRecursion(env, curr + 1, prev);

    int ans = max(include, exclude);
    return ans;
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end());
    int curr = 0;  // curr index
    int prev = -1; // prev index
    int ans = solveUsingRecursion(envelopes, curr, prev);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;

    vector<vector<int>> envelopes(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> envelopes[i][j];
        }
    }

    int ans = maxEnvelopes(envelopes);
    cout << "Max number of envelopes that could be Russian Doll: " << ans << endl;

    return 0;
}
*/
// _____________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingMem(vector<vector<int>> &env, int curr, int prev, vector<vector<int>> &dp)
{
    // Base condition
    if (curr >= env.size())
        return 0;

    // Step2: Check if the answer is already present inside the array
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 || env[curr][0] > env[prev][0] && env[curr][1] > env[prev][1])
    {
        include = 1 + solveUsingMem(env, curr + 1, curr, dp);
    }
    // exclude
    int exclude = 0 + solveUsingMem(env, curr + 1, prev, dp);

    // Step3: Store the answer in dp array
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end());
    int curr = 0;  // curr index
    int prev = -1; // prev index

    int n = envelopes.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = solveUsingMem(envelopes, curr, prev, dp);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;

    vector<vector<int>> envelopes(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> envelopes[i][j];
        }
    }

    int ans = maxEnvelopes(envelopes);
    cout << "Max number of envelopes that could be Russian Doll: " << ans << endl;

    return 0;
}

*/
// _______________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingTab(vector<vector<int>> &env)
{
    int n = env.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= envelopes.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || env[curr][0] > env[prev][0] && env[curr][1] > env[prev][1])
            {
                include = 1 + dp[curr + 1][curr + 1]; // prev-1 ka ans 0th idx, prev-0 ka ans 1st idx, har num ka ans +1 wale index par exist karta hai thats why we did curr+1 here
            }
            // exclude
            int exclude = 0 + dp[curr + 1][prev + 1];

            // Store the answer in dp array
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][-1 + 1];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end());

    int ans = solveUsingTab(envelopes);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;

    vector<vector<int>> envelopes(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> envelopes[i][j];
        }
    }

    int ans = maxEnvelopes(envelopes);
    cout << "Max number of envelopes that could be Russian Doll: " << ans << endl;

    return 0;
}
*/
// ____________________________________________________________________________________________________________________
/*
// 🔴🔴Space Optimization🔴🔴

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingSO(vector<vector<int>> &env)
{
    int n = env.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= envelopes.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || env[curr][0] > env[prev][0] && env[curr][1] > env[prev][1])
            {
                include = 1 + nextRow[curr + 1]; // prev-1 ka ans 0th idx, prev-0 ka ans 1st idx, har num ka ans +1 wale index par exist karta hai thats why we did curr+1 here
            }
            // exclude
            int exclude = 0 + nextRow[prev + 1];

            // Store the answer in dp array
            currRow[prev + 1] = max(include, exclude);
        }
        // Shifting
        nextRow = currRow;
    }
    return currRow[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end());

    int ans = solveUsingSO(envelopes);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;

    vector<vector<int>> envelopes(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> envelopes[i][j];
        }
    }

    int ans = maxEnvelopes(envelopes);
    cout << "Max number of envelopes that could be Russian Doll: " << ans << endl;

    return 0;
}
*/
// ____________________________________________________________________________________________________________________

// 🔴🔴Optimal Solution🔴🔴

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

int solveOptimal(vector<vector<int>> &arr)
{
    // sort envelopes by inc order of width
    // and if wi == wj, decreasing order of height
    sort(arr.begin(), arr.end(), comp);

    // Base case
    if (arr.size() == 0)
        return 0;

    // run LIS on height
    vector<int> ans;
    ans.push_back(arr[0][1]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][1] > ans.back())
        {
            // include
            ans.push_back(arr[i][1]);
        }
        else
        {
            // overwrite
            // find index of the just bigger element
            int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
            ans[index] = arr[i][1];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int ans = solveOptimal(envelopes);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;

    vector<vector<int>> envelopes(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> envelopes[i][j];
        }
    }

    int ans = maxEnvelopes(envelopes);
    cout << "Max number of envelopes that could be Russian Doll: " << ans << endl;

    return 0;
}

// TC -> O(nlogn)
// SC -> O(n)