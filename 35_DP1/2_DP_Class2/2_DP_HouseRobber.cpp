// 🔴🔴🔴🔴 LEETCODE 198 -> House Robber 🔴🔴🔴🔴
// Already done in 15_Week7_Assignments\8_House_Robber -> House Robber Optimized in TC -> O(n) and SC -> O(1)
// Check dry run for this optimized solution
// This is THE DP APPROACH
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/
// ______________________________________________________________________________________________________________

// ⭐Solve using Recursion⭐
/*
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int>& nums, int curr)    // curr represent the index of the current house
{
    if(curr < 0) return 0;
    if(curr == 0) return nums[0];

    // include
    int include = solveUsingRecursion(nums, curr-2) + nums[curr];
    // exclude
    int exclude = solveUsingRecursion(nums, curr-1) + 0;

    return max(include, exclude);
}

int rob(vector<int>& nums)
{
    int curr = nums.size()-1;
    return solveUsingRecursion(nums, curr);
}

int main()
{
    int n;
    cout << "Enter the number of houses:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the amount of money in each house:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int res = rob(nums);
    cout << "Maximum loot: " << res << endl;
    return 0;
}
*/
// TC -> O(2^n)
// SC -> O(n)
// _________________________________________________________________________________________________________________

// ⭐Solve using Memoization(Top-Down)⭐
/*
#include<iostream>
#include<vector>
using namespace std;

int solveUsingMemTopDown(vector<int>& nums, int curr, vector<int>& dp)
{
    if(curr < 0) return 0;
    if(curr == 0) return nums[0];

    // Step3: Check if the answer already exists in the dp array or not
    if(dp[curr] != -1)
    {
        return dp[curr];
    }
    int include = solveUsingMemTopDown(nums, curr-2, dp) + nums[curr];
    int exclude = solveUsingMemTopDown(nums, curr-1, dp) + 0;

    // Step2: Store answer in dp
    dp[curr] = max(include, exclude);
    return dp[curr];
}

int rob(vector<int>& nums)
{
    int curr = nums.size()-1;

    // Step1: Create the dp array
    vector<int>dp(curr+1, -1);

    return solveUsingMemTopDown(nums, curr, dp);
}

int main()
{
    int n;
    cout << "Enter the number of houses:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the amount of money in each house:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int res = rob(nums);
    cout << "Maximum loot: " << res << endl;
    return 0;
}
*/
// TC -> O(n)
// SC -> O(n)
// _______________________________________________________________________________________________________________

// ⭐Solve using Tabulation(Bottom-Up)⭐
/*
#include<iostream>
#include<vector>
using namespace std;

int solveUsingTabulationBottomUp(vector<int>& nums, int curr)
{
    vector<int> dp(curr+1, 0);
    dp[0] = nums[0];

    for(int i = 1; i <= curr; i++)
    {
        int temp = 0;
        if(i-2 >= 0)
        {
            temp = dp[i-2];
        }
        int include = temp + nums[i];
        int exclude = dp[i - 1] + 0;

        dp[i] = max(include, exclude);
    }
    return dp[curr];
}

int rob(vector<int>& nums)
{
    int curr = nums.size()-1;

    return solveUsingTabulationBottomUp(nums, curr);
}

int main()
{
    int n;
    cout << "Enter the number of houses:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the amount of money in each house:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int res = rob(nums);
    cout << "Maximum loot: " << res << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(n)
*/
// ________________________________________________________________________________________________________________

// ⭐Space Optimization Solution⭐
#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums)
    {
        int temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}

int main()
{
    int n;
    cout << "Enter the number of houses:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the amount of money in each house:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int res = rob(nums);
    cout << "Maximum loot: " << res << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)