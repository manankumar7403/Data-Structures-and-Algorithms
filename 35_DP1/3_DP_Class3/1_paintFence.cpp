// ⭐⭐ PAINT FENCE PROBLEM LEETCODE PREMIUM 276 ⭐⭐
// 🔴🔴 QUESTION 🔴🔴
/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
Note: n and k are non-negative integers.

Example:
Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

            post1  post2  post3      
 -----      -----  -----  -----       
   1         c1     c1     c2
   2         c1     c2     c1
   3         c1     c2     c2
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1
*/

// 🔴🔴 SOLUTION 🔴🔴
/*
If n == 1, there would be k-ways to paint.

if n == 2, there would be two situations:

2.1 You paint same color with the previous post: k*1 ways to paint, named it as same;
2.2 You paint differently with the previous post: k*(k-1) ways to paint this way, named it as diff.
So, you can think, if n >= 3, you can always maintain these two situations, You either paint the same color with the previous one, or differently.

Since there is a rule: “no more than two adjacent fence posts have the same color.”

We can further analyze:
from 2.1, since previous two are in the same color, next one you could only paint differently, and it would form one part of “paint differently” case in the n == 3 level,
and the number of ways to paint this way would equal to same*(k-1).
from 2.2, since previous two are not the same, you can either paint the same color this time (diff*1) ways to do so, or stick to paint differently (diff*(k-1)) times.
Here you can conclude, when seeing back from the next level, ways to paint the same, or variable same would equal to diff*1 = diff, and ways to paint differently,
variable diff, would equal to same * (k - 1) + diff * (k - 1) = (same + diff) * (k - 1).
*/

// ______________________________________________________________________________________________________________________________________________________________
//🔴🔴 Solving using Recursion 🔴🔴
/*
#include<iostream>
using namespace std;

int solveUsingRecursion(int n, int k)
{
    if(n<1) return 0;
    if(n==1) return k;
    if(n==2) return (k + k * (k-1));

    int ans = (solveUsingRecursion(n-2, k) + solveUsingRecursion(n-1, k)) * (k-1);
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of fence posts: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> k;

    int ans = solveUsingRecursion(n, k);
    cout << "Total number of ways to paint the posts: " << ans << endl;
    return 0;
}
*/
// TC -> O(2^n) -> two calls (n-2) and (n-1)
// _________________________________________________________________________________________________________________________

/*
// 🔴🔴Solve using Top-Down (Memoization)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingMem(int n, int k, vector<int>&dp)
{
    if(n<1) return 0;
    if(n==1) return k;
    if(n==2) return (k + k * (k-1));

    // Step 2: Check if the answer is already present in the dp array
    if(dp[n] != -1)
    {
        return dp[n];
    }

    // Step3: Store the answer in dp array
    dp[n] = (solveUsingMem(n-2, k, dp) + solveUsingMem(n-1, k, dp)) * (k-1);
    return dp[n];
}

int main()
{
    int n, k;
    cout << "Enter the number of fence posts: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> k;

    // Step1: Create the dp array
    vector<int>dp(n+1,-1);    // coz recursion me dekha ki n ki value change ho rhi hai toh us size ki dp bana di

    int ans = solveUsingMem(n, k, dp);
    cout << "Total number of ways to paint the posts: " << ans << endl;
    return 0;
}
// TC -> O(n) -> For each case only 1 computation (call) is performed
// SC -> O(n)
*/

// ___________________________________________________________________________________________________________________________
/*
// 🔴🔴Solve using Bottom-Up (Tabulation)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTab(int n, int k)
{
    // Step1: Create the dp array
    vector<int>dp(n+1, 0);    // coz recursion me dekha ki n ki value change ho rhi hai toh us size ki dp bana di
    
    // Step2: Handle the base cases
    if(n<1) return 0;
    dp[1] = k;
    dp[2] = (k + k * (k-1));

    // Step3: Perform the operation from 1 to n (bottom up)
    for(int i=3; i<=n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1);
    }
    return dp[n];
}

int main()
{
    int n, k;
    cout << "Enter the number of fence posts: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> k;

    int ans = solveUsingTab(n, k);
    cout << "Total number of ways to paint the posts: " << ans << endl;
    return 0;
}
// TC -> O(n) -> For each case only 1 computation (call) is performed
// SC -> O(n)
*/

// _____________________________________________________________________________________________________________________________

// 🔴🔴Optimizing space🔴🔴
// dp[i] = (dp[i-2] + dp[i-1]) * (k-1);
// As the value of i is dependent on i-1 and i-2 we can just use 3 variables curr, prev1, prev2, instead of using a vector array
// to optimize the space.

#include<iostream>
#include<vector>
using namespace std;

int spaceOptimization(int n, int k)
{    
    // Step2: Handle the base cases
    if(n<1) return 0;
    int prev2 = k;
    int prev1 = (k + k * (k-1));

    // Step3: Perform the operation from 1 to n (bottom up)
    for(int i=3; i<=n; i++)
    {
        int curr = (prev2 + prev1) * (k-1);
        // ⭐⭐IMPORTANT SHIFTING LOGIC⭐⭐
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n, k;
    cout << "Enter the number of fence posts: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> k;

    int ans = spaceOptimization(n, k);
    cout << "Total number of ways to paint the posts: " << ans << endl;
    return 0;
}
// TC -> O(n) -> For each case only 1 computation (call) is performed
// SC -> O(1)