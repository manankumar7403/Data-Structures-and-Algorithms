// 🔴🔴LEETCODE 188 -> Best Time To Buy And Sell Stock 4🔴🔴
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at
most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell
on day 6 (price = 3), profit = 3-0 = 3.

Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/
// _________________________________________________________________________________________________________________
/*
// 🔴🔴RECURSION🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int> &prices, int i, int buy, int limit)
{
    // Base condition
    if (i >= prices.size() || limit == 0)
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyItProfit = solveUsingRecursion(prices, i + 1, 0, limit) - prices[i];
        int skipProfit = solveUsingRecursion(prices, i + 1, 1, limit);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = solveUsingRecursion(prices, i + 1, 1, limit - 1) + prices[i];
        int skipProfit = solveUsingRecursion(prices, i + 1, 0, limit);
        profit = max(sellItProfit, skipProfit);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    return solveUsingRecursion(prices, 0, true, k);
}

int main()
{
    int n, k;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    cout << "Enter the number of transactions: " << endl;
    cin >> k;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(k, prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O((2^n)*k)
// SC -> O(n*k)
*/
// __________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(vector<int> &prices, int i, int buy, vector<vector<vector<int>>> &dp, int limit)
{
    // Base condition
    if (i >= prices.size() || limit == 0)
        return 0;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[i][buy][limit] != -1)
    {
        return dp[i][buy][limit];
    }

    int profit = 0;
    if (buy)
    {
        int buyItProfit = solveUsingMem(prices, i + 1, 0, dp, limit) - prices[i];
        int skipProfit = solveUsingMem(prices, i + 1, 1, dp, limit);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = solveUsingMem(prices, i + 1, 1, dp, limit - 1) + prices[i];
        int skipProfit = solveUsingMem(prices, i + 1, 0, dp, limit);
        profit = max(sellItProfit, skipProfit);
    }
    // Step3: Store the answer in dp array and return
    dp[i][buy][limit] = profit;
    return dp[i][buy][limit];
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solveUsingMem(prices, 0, true, dp, k);
}

int main()
{
    int n, k;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    cout << "Enter the number of transactions: " << endl;
    cin >> k;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(k, prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O(n*k)
// SC -> O(n*k)
*/
// _____________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(vector<int> &prices, int k)
{
    int n = prices.size();
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size() || limit == 0) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < k + 1; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyItProfit = dp[i + 1][0][limit] - prices[i];
                    int skipProfit = dp[i + 1][1][limit];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = dp[i + 1][1][limit - 1] + prices[i];
                    int skipProfit = dp[i + 1][0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                // Store the answer in dp array
                dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][k];
}

int maxProfit(int k, vector<int> &prices)
{
    return solveUsingTab(prices, k);
}

int main()
{
    int n, k;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    cout << "Enter the number of transactions: " << endl;
    cin >> k;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(k, prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O(n*k)
// SC -> O(n*k)

*/
// _______________________________________________________________________________________________________________________

// 🔴🔴SPACE OPTIMIZATION🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(vector<int> &prices, int k)
{
    int n = prices.size();
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size() || limit == 0) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < k + 1; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyItProfit = dp[1][0][limit] - prices[i];
                    int skipProfit = dp[1][1][limit];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = dp[1][1][limit - 1] + prices[i];
                    int skipProfit = dp[1][0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                // Store the answer in dp array
                dp[0][buy][limit] = profit;
            }
        }
        // Shifting
        dp[1] = dp[0];
    }
    return dp[0][1][k];
}

int maxProfit(int k, vector<int> &prices)
{
    return solveUsingSO(prices, k);
}

int main()
{
    int n, k;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    cout << "Enter the number of transactions: " << endl;
    cin >> k;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(k, prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}

// TC -> O(n*k)
// SC -> O(k)