// 🔴🔴LEETCODE 123 -> Best Time To Buy and Sell Stock 3🔴🔴
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time.
You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5
*/
// ________________________________________________________________________________________________________

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

int maxProfit(vector<int> &prices)
{
    return solveUsingRecursion(prices, 0, true, 2);
}

int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O(2^n)
// SC -> O(n)
*/
// ________________________________________________________________________________________________________________

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

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveUsingMem(prices, 0, true, dp, 2);
}

int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O(n)
// SC -> O(n)
*/
// ___________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(vector<int> &prices)
{
    int n = prices.size();
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size() || limit == 0) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
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
    return dp[0][1][2];
}

int maxProfit(vector<int> &prices)
{
    return solveUsingTab(prices);
}

int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}
// TC -> O(n)
// SC -> O(n)
*/
// ____________________________________________________________________________________________________________________

// 🔴🔴SPACE OPTIMIZATION🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(vector<int> &prices)
{
    // Step1: Create the dp array: 3d dp as i, true/false condition, and limit is changing
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size() || limit == 0) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
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
    return dp[0][1][2];
}

int maxProfit(vector<int> &prices)
{
    return solveUsingSO(prices);
}

int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    vector<int>prices(n);
    cout << "Enter the prices: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(prices);
    cout << "Max profit is " << ans << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)