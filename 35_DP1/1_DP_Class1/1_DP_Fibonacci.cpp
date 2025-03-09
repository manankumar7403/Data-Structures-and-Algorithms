// 🔴🔴🔴🔴 LEETCODE 509 -> Fibonacci Number 🔴🔴🔴🔴

/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the
sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n). 

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
Constraints:
0 <= n <= 30
*/
// ______________________________________________________________________________________________

// ✅ Solved it using for loop
/*
class Solution {
public:
    int fib(int n) {
        int a=0;
        int b=1;
        int ans;
        if(n==0)
        {
            return a;
        }
        for(int i=2; i<=n; i++)
        {
            ans = a+b;
            a = b;
            b = ans;
        }
        return b;
    }
};
*/
// TC -> O(n)
// SC -> O(1)

// _________________________________________________________________________________________________

// Solved using recursion
// Given n, calculate F(n)
/*
#include <iostream>
using namespace std;

int recSolve(int n)
{
    // Base case
    if(n==0 || n==1)
    {
        return n;
    }
    int ans = recSolve(n-1) + recSolve(n-2);
    return ans;
}

int fib(int n)
{
    int ans = recSolve(n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}
TC -> O(2^n)
SC -> O(n)
*/

// _________________________________________________________________________________________________________________

// Now solving using DP (Recursion + Memoization) -> we go top -> down
/*
#include <iostream>
#include <vector>
using namespace std;

int topDownSolve(int n, vector<int>& dp)  // top down coz we are going from n to 2
{
    // Base case
    if(n==0 || n==1)
    {
        return n;
    }
    // Step3: Check if answer already exists or not
    if(dp[n] != -1)
    {
        return dp[n];
    }

    // Step2: Replace ans with dp[n]
    dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
    return dp[n];
}

int fib(int n)
{
    // Step1: Create dp array
    vector<int> dp(n+1, -1);
    int ans = topDownSolve(n, dp);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}
// TC -> O(n)
// SC -> O(n) + O(n)
*/

// _____________________________________________________________________________________________________________

// Now solving using DP (Tabulation Method) -> we go Bottom -> Up
/*
#include <iostream>
#include <vector>
using namespace std;

int BottomUpSolve(int n)  // bottom up coz we are going from 2 to n
{
    // Step1: Create DP array
    vector<int>dp(n+1, -1);

    // Step2: Observe base case
    dp[0] = 0;
    if(n==0) return dp[0];
    dp[1] = 1;
    if(n==1) return dp[1];

    // Step3: Go up from here
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// TC -> O(n)
// SC -> O(n)

int fib(int n)
{
    return BottomUpSolve(n);
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}
*/

// ________________________________________________________________________________________________________________

// Space Optimization Approach
#include <iostream>
#include <vector>
using namespace std;

int SpaceOpt(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    if(n==0) return prev2;
    if(n==1) return prev1;

    for(int i=2; i<=n; i++)
    {
        curr = prev1 + prev2;
        // Shifting
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// hume bas pichli 2 values ka hi record rakhna hai, so creating an extra array is not required, just use 2 variables.

int fib(int n)
{
    return SpaceOpt(n);
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)