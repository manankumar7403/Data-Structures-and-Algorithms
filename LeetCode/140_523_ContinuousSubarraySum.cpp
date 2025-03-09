// 🔴🔴LEETCODE 523 -> Continuous Subarray Sum🔴🔴
// ⭐⭐A lot similar to Leetcode: 525 -> Contiguous Array⭐⭐
/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and the sum of the elements of the subarray is a multiple of k.
Note that:
A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Example 3:
Input: nums = [23,2,6,4,7], k = 13
Output: false

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= sum(nums[i]) <= 2^31 - 1
1 <= k <= 2^31 - 1
*/
// ________________________________________________________________________________________________________________
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp; // sum, index
    mpp[0] = -1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (mpp.find(sum % k) != mpp.end())
        {
            if (i - mpp[sum % k] >= 2)
                return true;
        }
        else
        {
            mpp[sum % k] = i;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cout << "Enter the value of k:" << endl;
    cin >> k;
    
    if(checkSubarraySum(nums, k))
    {
        cout << "Good subarray present!" << endl;
    }
    else cout << "Good subarray absent!" << endl;
    return 0;
}

// TC -> O(N*logN) if using map and O(N) if using unordered map in best and avg and O(N^2) in unordered map worst case
// SC -> O(N) -> worst case n preifx sum can be stored
