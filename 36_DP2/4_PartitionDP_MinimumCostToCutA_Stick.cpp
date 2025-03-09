// ⭐⭐Partition DP, Refer: https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/ ⭐⭐
// 🔴🔴LEETCODE 1547 -> Minimum Cost To Cut A Stick🔴🔴
/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as
follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick,
it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer
to the first example for a better explanation.
Return the minimum total cost of the cuts.

Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part
of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is
7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example
photo 7 + 4 + 3 + 2 = 16).

Example 2:
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the
minimum possible.

Constraints:
2 <= n <= 10^6
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/
// ____________________________________________________________________________________________________________________
// 🔴🔴Solve Using Recursion🔴🔴
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingRecursion(int i, int j, vector<int> &cuts)
{
    // Base case
    if (i > j)
        return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] + solveUsingRecursion(i, ind - 1, cuts) + solveUsingRecursion(ind + 1, j, cuts);
        mini = min(mini, ans);
    }
    return mini;
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return solveUsingRecursion(1, cuts.size() - 2, cuts);
}

int main()
{
    int n;
    cout << "Enter the length of the wooden stick:" << endl;
    cin >> n;
    int size;
    cout << "Enter the size of the cuts array:" << endl;
    cin >> size;
    vector<int>cuts(size);
    cout << "Enter the cuts:" << endl;
    for(int i=0; i<size; i++)
    {
        cin >> cuts[i];
    }
    int ans = minCost(n, cuts);
    cout << "Min cost: " << ans << endl;
    return 0;
}

// TC -> O(2^n)
// SC -> O(n)
*/
// _______________________________________________________________________________________________________________________

// 🔴🔴Solve Using Memoization(Top-Down)🔴🔴
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingMem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    // Base case
    if (i > j)
        return 0;

    // Step2: Check if the answer is already present inside the dp array
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        // Calculate the cost for making a cut at position 'ind'.
        int ans = cuts[j + 1] - cuts[i - 1] + solveUsingMem(i, ind - 1, cuts, dp) + solveUsingMem(ind + 1, j, cuts, dp);
        mini = min(mini, ans);
    }

    // Step3: Store the answer in dp array and return
    dp[i][j] = mini;
    return dp[i][j];
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Step1: Create a dp array: 2d dp as i and j are changing
    vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
    return solveUsingMem(1, cuts.size() - 2, cuts, dp);
}

int main()
{
    int n;
    cout << "Enter the length of the wooden stick:" << endl;
    cin >> n;
    int size;
    cout << "Enter the size of the cuts array:" << endl;
    cin >> size;
    vector<int>cuts(size);
    cout << "Enter the cuts:" << endl;
    for(int i=0; i<size; i++)
    {
        cin >> cuts[i];
    }
    int ans = minCost(n, cuts);
    cout << "Min cost: " << ans << endl;
    return 0;
}

// TC -> O(n^3)
// SC -> O(n^2) + O(n) = O(n^2) -> (2d vector and stack in recursion)
*/
// __________________________________________________________________________________________________________________

// 🔴🔴Solve Using Tabulation(Bottom-Up)🔴🔴

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingTab(vector<int> &cuts)
{
    int m = cuts.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(m, vector<int>(m, 0));

    // Step2: Check the base case -> no change as dp array already initialized with 0
    // if(i>j) return 0;

    // Step3: Main iteration logic
    for (int i = m - 2; i >= 1; i--)
    {
        for (int j = 1; j <= m - 2; j++)
        {
            // 🔴🔴Can make a mistake here🔴🔴
            if (i > j)
                continue; // This would imply that we are looking at an invalid range where the starting index is greater than the ending index. Calculating a cost for such a range doesn't make sense because there are no cuts to be made in this "range".
            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, ans);
            }
            // Store the answer in dp array
            dp[i][j] = mini;
        }
    }
    return dp[1][m - 2];
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return solveUsingTab(cuts);
}

int main()
{
    int n;
    cout << "Enter the length of the wooden stick:" << endl;
    cin >> n;
    int size;
    cout << "Enter the size of the cuts array:" << endl;
    cin >> size;
    vector<int>cuts(size);
    cout << "Enter the cuts:" << endl;
    for(int i=0; i<size; i++)
    {
        cin >> cuts[i];
    }
    int ans = minCost(n, cuts);
    cout << "Min cost: " << ans << endl;
    return 0;
}

// TC -> O(n^3)
// SC -> O(n^2)