// 🔴🔴🔴🔴 LEETCODE 198 -> House Robber 🔴🔴🔴🔴

#include <iostream>
#include <vector>
using namespace std;

int robHelper(vector<int>& nums, int i)
{
    // Base Case
    if(i >= nums.size()) return 0;

    // ek case solve kardo
    int robAmt1 = nums[i] + robHelper(nums, i + 2);  // looting 1st house 3rd house, 5th.....
    int robAmt2 = 0 + robHelper(nums, i + 1);        // looting 2nd house, 4th house, 6th....

    return max(robAmt1, robAmt2);
}

int rob(vector<int>& nums)
{
    return robHelper(nums, 0);
}

int main()
{
    vector<int>nums{2,1,1,9,1};
    cout << rob(nums) << endl;
    return 0;
}

// [2,7,9,3,1]
// Output should be 12 as 
// Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

