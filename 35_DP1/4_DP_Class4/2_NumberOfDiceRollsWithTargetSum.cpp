// 🔴🔴🔴🔴 LEETCODE 1155 -> Number of Dice Rolls with Target Sum 🔴🔴🔴🔴
/*
You have n dice, and each die has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways)
to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large,
return it modulo 10^9 + 7.

Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 10^9 + 7.

Constraints:
1 <= n, k <= 30
1 <= target <= 1000
*/
// ____________________________________________________________________________________________________

// 🔴🔴Solve using Recursion🔴🔴
/*
#include <iostream>
using namespace std;

int solveUsingRecursion(int n, int k, int target)
{
    // Base conditions
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;
    int ans = 0;
    for (int i = 1; i <= k; i++) // each die could give a value between 1 and k
    {
        ans = ans + solveUsingRecursion(n - 1, k, target - i);
    }
    const int MOD = 1000000007;
    return ans % MOD;
}

int numRollsToTarget(int n, int k, int target)
{
    return solveUsingRecursion(n, k, target);
}

int main()
{
    int n, k, target;
    cout << "Enter the total number of dice: " << endl;
    cin >> n;
    cout << "Enter the total number of faces: " << endl;
    cin >> k;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Total number of possible ways to roll the dice: " << numRollsToTarget(n, k, target);
    cout << endl;
    return 0;
}
*/
// TC -> O(k^n) -> For every case we make k calls (as there are k faces) -> so possible solution lies between
// 1 to <= k at every call.
// SC -> O(n) -> Depth of recursive tree (stack) is n+1.
// This recursive solution gives TLE Error due to O(k^n) TC, will learn DP and revisit this problem.
// ____________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
long long int solveUsingMem(int n, int k, int target, vector<vector<long long int>> &dp)
{
    // Base conditions
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) // each die could give a value between 1 and k
    {
        if (target - i >= 0)
        {
            ans = (ans + solveUsingMem(n - 1, k, target - i, dp)) % MOD;
        }
    }
    // Step3: Store the answer in dp array
    dp[n][target] = ans;
    return dp[n][target];
}

int numRollsToTarget(int n, int k, int target)
{
    // Step1: Create a dp array: 2d dp here as value of n and target both are changing
    vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
    return solveUsingMem(n, k, target, dp);
}

int main()
{
    int n, k, target;
    cout << "Enter the total number of dice: " << endl;
    cin >> n;
    cout << "Enter the total number of faces: " << endl;
    cin >> k;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Total number of possible ways to roll the dice: " << numRollsToTarget(n, k, target);
    cout << endl;
    return 0;
}
*/

// ____________________________________________________________________________________________________________________________
/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
long long int solveUsingTab(int n, int k, int target)
{
    // Step1: Create a dp array: 2d dp here as value of n and target both are changing
    vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));

    // Step2: Check the base conditions: here all cases of return 0 won't matter as dp array is initialized with 0
    // only return 1 case i.e., n==0 and target==0 is considered
    dp[0][0] = 1;

    // Step3: Main logic of iteration
    for (int index = 1; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            int ans = 0;
            for (int i = 1; i <= k; i++) // each die could give a value between 1 and k
            {
                if (t - i >= 0)
                {
                    ans = (ans + dp[index - 1][t - i]) % MOD;
                }
            }
            dp[index][t] = ans;
        }
    }
    return dp[n][target];
}

int numRollsToTarget(int n, int k, int target)
{
    return solveUsingTab(n, k, target);
}

int main()
{
    int n, k, target;
    cout << "Enter the total number of dice: " << endl;
    cin >> n;
    cout << "Enter the total number of faces: " << endl;
    cin >> k;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Total number of possible ways to roll the dice: " << numRollsToTarget(n, k, target);
    cout << endl;
    return 0;
}
*/
// _________________________________________________________________________________________________________________

// 🔴🔴Space Optimization -1🔴🔴
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
long long int solveUsingSO(int n, int k, int target)
{
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // Step2: Check the base conditions: here all cases of return 0 won't matter as array is initialized with 0
    // only return 1 case i.e., n==0 and target==0 is considered
    prev[0] = 1;

    // Step3: Main logic of iteration
    for (int index = 1; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            int ans = 0;
            for (int i = 1; i <= k; i++) // each die could give a value between 1 and k
            {
                if (t - i >= 0)
                {
                    ans = (ans + prev[t - i]) % MOD;
                }
            }
            curr[t] = ans;
        }
        // Shifting
        prev = curr;
    }
    return curr[target];
}
int numRollsToTarget(int n, int k, int target)
{
    return solveUsingSO(n, k, target);
}

int main()
{
    int n, k, target;
    cout << "Enter the total number of dice: " << endl;
    cin >> n;
    cout << "Enter the total number of faces: " << endl;
    cin >> k;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Total number of possible ways to roll the dice: " << numRollsToTarget(n, k, target);
    cout << endl;
    return 0;
}