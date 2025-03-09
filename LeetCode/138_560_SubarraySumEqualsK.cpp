// 🔴🔴LEETCODE 560 -> Subarray Sum Equals K🔴🔴
// ⭐⭐Prefix Sum Technique is important⭐⭐
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

// __________________________________________________________________________________________________________________
// 🔴🔴METHOD 1: Brute Force🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array:" << endl;
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

    cout << "Max subarrays are: " << subarraySum(nums, k);
    return 0;
}

// TC -> O(n^2)
// SC -> O(1)
*/

// __________________________________________________________________________________________________________________
// 🔴🔴METHOD 1: Brute Force🔴🔴

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum = prefixSum + nums[i];
        int remove = prefixSum - k;
        count = count + mpp[remove];
        mpp[prefixSum] = mpp[prefixSum] + 1;
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array:" << endl;
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

    cout << "Max subarrays are: " << subarraySum(nums, k);
    return 0;
}

// TC -> O(N*logN) if using map and O(N) if using unordered map in best and avg and O(N^2) in unordered map worst case
// SC -> O(N) -> worst case n preifx sum can be stored
