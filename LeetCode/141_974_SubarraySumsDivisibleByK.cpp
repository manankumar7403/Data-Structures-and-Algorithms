// 🔴🔴LEETCODE 974 -> Subarray Sums Divisible By K🔴🔴
// ⭐⭐A lot similar to 523 -> Continuous Subarray Sum⭐⭐
// ⭐⭐Prefix Sum logic is important⭐⭐
// https://www.youtube.com/watch?v=C0okNE_tt14

/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0

Constraints:
1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
2 <= k <= 10^4
*/
// ___________________________________________________________________________________________________________
// 🔴🔴METHOD 1: Brute Force🔴🔴
/*
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            if (sum % k == 0)
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
    cout << "Number of subarrays divisible by " << k << " are: " << subarraysDivByK(nums, k);
    return 0;
}

// TC -> O(n^2)
// SC -> O(1)
*/
// ____________________________________________________________________________________________________________

// 🔴🔴METHOD 2: Using Map🔴🔴

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int prefixSum = 0, ans = 0;
    unordered_map<int, int> mpp; // sum, index
    mpp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum = (prefixSum + nums[i] % k + k) % k; // to convert -ve no % k to +ve you do (-ve no + k) % k
        ans = ans + mpp[prefixSum];
        mpp[prefixSum]++;
    }
    return ans;
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
    cout << "Number of subarrays divisible by " << k << " are: " << subarraysDivByK(nums, k);
    return 0;
}

// TC -> O(N*logN) if using map and O(N) if using unordered map in best and avg and O(N^2) in unordered map worst case
// SC -> O(N) -> worst case n preifx sum can be stored
