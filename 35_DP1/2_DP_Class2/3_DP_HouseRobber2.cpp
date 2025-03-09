// 🔴🔴🔴🔴 LEETCODE 213 -> House Robber II 🔴🔴🔴🔴
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two
adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/
// _____________________________________________________________________________________________________________________

// Basic idea hai ye ki last aur first wala kabhi bhi ek saath nahi ayega becuase circle me hai houses and last and first
// houses adjacent ho jayenge toh hum ek function me first house exclude karke 2nd se last tak houses ka max looted amount
// nikalenge and ek dusre function me last house ko exclude karke first se secondlast house se max looted amount
// nikalenge. FInally we will calculate the max of the answer1 from 1st function and answer2 from 2nd function
// REFER 2_DP_HouseRobber.cpp

//⭐⭐ Space Optimized Solution ⭐⭐
#include <iostream>
#include <vector>
using namespace std;
int maxleft(vector<int> &nums)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    return prev1;
}

int maxright(vector<int> &nums)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = prev1;
        prev1 = max(prev2 + nums[i], prev1);
        prev2 = temp;
    }
    return prev1;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    return max(maxleft(nums), maxright(nums));
}

int main()
{
    int n;
    cout << "Enter the number of houses:" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the amount of money present in each house(circle):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Max loot from houses in a circle: " << rob(nums) << endl;
}
// TC -> O(n)
// SC -> O(1)