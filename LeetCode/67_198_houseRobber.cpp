// 🔴🔴🔴🔴 LEETCODE 198 -> House Robber 🔴🔴🔴🔴
// Refer 15_Week7_Assignments

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of
// money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have
// security systems connected and it will automatically contact the police if two adjacent houses were broken
// into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of
// money you can rob tonight without alerting the police. 

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
// ________________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums)
{
    if(nums.size() == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for(int num: nums)
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
    cout << "Enter the length of the nums array: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array: " << endl;
    for (int i=0; i< n; i++)
    {
        cin >> nums[i];
    }
    cout << "Max loot: " << rob(nums);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)