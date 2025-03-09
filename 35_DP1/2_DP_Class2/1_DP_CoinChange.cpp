// 🔴🔴🔴🔴 LEETCODE 322 -> Coin Change 🔴🔴🔴🔴
/*
You are given an integer array coins representing coins of different denominations and an integer amount
representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by
any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/

// _______________________________________________________________________________________________________________

// ⭐ USING Recursion ⭐
/*
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(vector<int>& coins, int amount)
{
    // base case
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int ans = solveUsingRecursion(coins, amount - coins[i]);
        if(ans != INT_MAX)
        {
            mini = min(mini, ans+1);
        }
    }
    return mini;
}

int coinChange(vector<int>& coins, int amount)
{
    int ans = solveUsingRecursion(coins, amount);
    if(ans == INT_MAX) return -1;
    else return ans;
}

int main()
{
    int n, amount;
    cout << "Enter the number of coins in the array:" << endl;
    cin >> n;
    vector<int>coins(n);
    cout << "Enter the coins in the coin array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the total amount:" << endl;
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Lowest number of coins needed to make " << amount << " is " << result << endl;
    return 0;
}

TC -> O(n^amount) where n is the number of the coins
SC -> O(n^amount)
*/
// ________________________________________________________________________________________________________________


// ⭐ USING Top-Down (Recursion + Memoization) ⭐
/*
#include <iostream>
#include <vector>
using namespace std;

int solveMemTopDown(vector<int>& coins, int amount, vector<int>& dp)
{
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;
    
    // Step3: Check if answer already exists
    if(dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int ans = solveMemTopDown(coins, amount - coins[i], dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, ans+1);
        }
    }

    // Step2: Save answer in dp
    dp[amount] = mini;
    return mini;
}

int coinChange(vector<int>& coins, int amount)
{
    // Step1: Create dp array
    vector<int> dp(amount+1, -1);
    int ans = solveMemTopDown(coins, amount, dp);
    if(ans == INT_MAX) return -1;
    else return ans;
}

int main()
{
    int n, amount;
    cout << "Enter the number of coins in the array:" << endl;
    cin >> n;
    vector<int>coins(n);
    cout << "Enter the coins in the coin array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the total amount:" << endl;
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Lowest number of coins needed to make " << amount << " is " << result << endl;
    return 0;
}

TC -> O(amount)
SC -> O(n+n)
*/

// ___________________________________________________________________________________________________________________

// ⭐ USING Bottom-Up (Tabulation) ⭐

#include <iostream>
#include <vector>
using namespace std;

int solveTabBottomUp(vector<int> &coins, int amount)
{
    // Step1: Create dp array
    vector<int> dp(amount+1, INT_MAX);
    
    // Step2: Base case dekho
    dp[0] = 0;

    // Step3: Check the range and flow of top down approach and code accordingly
    for (int i = 1; i <= amount; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if(i - coins[j] >= 0)
            {
                int ans = dp[i - coins[j]];
                if(ans != INT_MAX)
                {
                    mini = min(mini, ans + 1);
                }
            }
        }
        dp[i] = mini;
    }
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount)
{
    int ans = solveTabBottomUp(coins, amount);
    if(ans == INT_MAX) return -1;
    else return ans;
}

int main()
{
    int n, amount;
    cout << "Enter the number of coins in the array:" << endl;
    cin >> n;
    vector<int>coins(n);
    cout << "Enter the coins in the coin array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the total amount:" << endl;
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Lowest number of coins needed to make " << amount << " is " << result << endl;
    return 0;
}

// TC -> O(amount)
// SC -> O(n+n)