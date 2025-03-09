// ⭐⭐LEETCODE 375 -> Guess Number Higher or Lower II⭐⭐
/*
We are playing the Guessing Game. The game will work as follows:
I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Example 1:
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.

Example 2:
Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.

Example 3:
Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.

Constraints:
1 <= n <= 200
*/
// __________________________________________________________________________________________________________________

// 🔴🔴Solve Using Recursion🔴🔴
/*
#include<iostream>
using namespace std;

int solveUsingRecursion(int start, int end)
{
    // Base condition
    if (start >= end)
        return 0;

    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
    }
    return ans;
}

int getMoneyAmount(int n)
{
    int ans = solveUsingRecursion(1, n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the end limit: ";
    cin >> n;
    int ans = getMoneyAmount(n);
    cout << "Min amount to pay: " << ans << endl;
    return 0;
}
TC -> O(2^n)

*/
// ________________________________________________________________________________________________________________________
/*
// 🔴🔴Memoization(Top-Down)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(int start, int end, vector<vector<int>> &dp)
{
    // Base condition
    if (start >= end)
        return 0;

    // Step2: Check if the answer is already present or not
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        ans = min(ans, i + max(solveUsingMem(start, i - 1, dp), solveUsingMem(i + 1, end, dp)));
    }
    // Step3: Store the answer in dp array
    dp[start][end] = ans;
    return dp[start][end];
}

int getMoneyAmount(int n)
{
    // Step1: Create the dp array: 2d array as value of start and end both are changing
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(1, n, dp);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the end limit: ";
    cin >> n;
    int ans = getMoneyAmount(n);
    cout << "Min amount to pay: " << ans << endl;
    return 0;
}
// TC -> O(n^3)
// SC -> O(n^2)

*/
// __________________________________________________________________________________________________________________

// 🔴🔴Tabulation(Bottom-Up)🔴🔴

#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(int n)
{
    // Step1: Create the dp array: 2d array as value of start and end both are changing
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // Step2: Check Base condition -> no need as dp array already init with 0
    // if(start >= end) return 0;

    // Step3: Main iteration logic
    for (int start = n; start >= 1; start--)
    {
        for (int end = 1; end <= n; end++)
        {
            if (start >= end)
                continue;
            else
            {
                int ans = INT_MAX;
                for (int i = start; i < end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                // Store the answer in dp array
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n]; // the same thing you called in solveUsingTab in getMoneyAmount function
}

int getMoneyAmount(int n)
{
    int ans = solveUsingTab(n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the end limit: ";
    cin >> n;
    int ans = getMoneyAmount(n);
    cout << "Min amount to pay: " << ans << endl;
    return 0;
}

// TC -> O(n^3)
// SC -> O(n^2)
