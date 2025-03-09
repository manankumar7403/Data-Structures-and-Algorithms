// 🔴🔴🔴🔴 LEETCODE 53 -> Maximum SubArray Sum 🔴🔴🔴🔴
// Refer 17_DnC_Assignments -> 4_MaxSubArray Sum
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer
approach, which is more subtle.
*/
// ___________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

int maxSubArrayHelper(vector<int> &nums, int start, int end)
{
    // Base Case
    if (start == end)
        return nums[start]; // only single element left -> max subarray sum

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = start + ((end - start) >> 1);

    int maxLeftSum = maxSubArrayHelper(nums, start, mid);    // jo mid ko exclude karke strictly left me max subarray sum hai
    int maxRightSum = maxSubArrayHelper(nums, mid + 1, end); // jo mid ko exclude karke strictly right me max subarray sum hai

    // Calculating Max Cross Border Sum
    // To calculate Max Left Border Sum (max left sum including the middle element)
    int leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum = leftBorderSum + nums[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    // To calculate Max Right Border Sum (max right sum including the middle element)
    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum = rightBorderSum + nums[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum; // total max cross border sum including the left, right, mid
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    // returns what is max -> maxLeftSum(exc mid), maxRightSum(exc mid), crossBorderSum(inc leftSum, mid element, righSum)
}

int maxSubArray(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    return maxSubArrayHelper(nums, start, end);
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Max SubArray Sum is: " << maxSubArray(nums);
    cout << endl;
    return 0;
}
// TC -> O(nlogn)
// SC -> O(logn)