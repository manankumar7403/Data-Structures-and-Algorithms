// 🔴🔴LEETCODE 122 -> Best Time To Buy and Sell Stock 2🔴🔴
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4
*/
// _____________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int> &prices, int i, bool buy)
{
    // Base condition
    if (i >= prices.size())
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyItProfit = solveUsingRecursion(prices, i + 1, 0) - prices[i];
        int skipProfit = solveUsingRecursion(prices, i + 1, 1);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = solveUsingRecursion(prices, i + 1, 1) + prices[i];
        int skipProfit = solveUsingRecursion(prices, i + 1, 0);
        profit = max(sellItProfit, skipProfit);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    return solveUsingRecursion(prices, 0, true);
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
// __________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    // Base condition
    if (i >= prices.size())
        return 0;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }

    int profit = 0;
    if (buy)
    {
        int buyItProfit = solveUsingMem(prices, i + 1, 0, dp) - prices[i];
        int skipProfit = solveUsingMem(prices, i + 1, 1, dp);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = solveUsingMem(prices, i + 1, 1, dp) + prices[i];
        int skipProfit = solveUsingMem(prices, i + 1, 0, dp);
        profit = max(sellItProfit, skipProfit);
    }
    // Step3: Store the answer in dp array and return
    dp[i][buy] = profit;
    return dp[i][buy];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // Step1: Create the dp array: 2d dp as i and true/false condition is changing
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveUsingMem(prices, 0, true, dp);
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

// _______________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(vector<int> &prices)
{
    int n = prices.size();
    // Step1: Create the dp array: 2d dp as i and true/false condition is changing
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size()) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyItProfit = dp[i + 1][0] - prices[i];
                int skipProfit = dp[i + 1][1];
                profit = max(buyItProfit, skipProfit);
            }
            else
            {
                int sellItProfit = dp[i + 1][1] + prices[i];
                int skipProfit = dp[i + 1][0];
                profit = max(sellItProfit, skipProfit);
            }
            // Store the answer in dp array
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
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
*/
// TC -> O(n)
// SC -> O(n)
// _______________________________________________________________________________________________________________

// 🔴🔴SPACE OPTIMIZATION🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingSO(vector<int> &prices)
{
    // Step1: Create the dp array: 2d dp as i and true/false condition is changing
    vector<vector<int>> dp(2, vector<int>(2, 0));

    // Step2: Check the base condition -> dp array already init with 0
    // if(i >= prices.size()) return 0;

    // Step3: Main iteration logic
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyItProfit = dp[1][0] - prices[i];
                int skipProfit = dp[1][1];
                profit = max(buyItProfit, skipProfit);
            }
            else
            {
                int sellItProfit = dp[1][1] + prices[i];
                int skipProfit = dp[1][0];
                profit = max(sellItProfit, skipProfit);
            }
            // Store the answer in dp array
            dp[0][buy] = profit;
        }
        // Shifting
        dp[1] = dp[0];
    }
    return dp[0][1];
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