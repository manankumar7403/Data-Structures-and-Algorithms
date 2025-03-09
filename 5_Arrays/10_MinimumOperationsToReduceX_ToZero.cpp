// 🔴🔴LEETCODE 1658 -> Minimum Operations To Reduce X To Zero🔴🔴
// ⭐⭐Sliding Window⭐⭐
// ⭐⭐Refer: https://www.youtube.com/watch?v=NRamG4Q9LwQ⭐⭐

/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the
rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future
operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total)
to reduce x to zero.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
1 <= x <= 10^9
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    int sum = accumulate(nums.begin(), nums.end(), 0); // beg iterator, end iterator, init value -> computes the sum
    int target = sum - x;                              // the idea is to find the max subarray len making the target=sum-x, the sub the len from nums.size()
    int currSum = 0, maxLen = 0;
    int i = 0; // starting index of the subarray
    bool found = false;

    for (int j = 0; j < nums.size(); j++)
    {
        currSum = currSum + nums[j];

        // if currSum becomes greater than target,shrink the window(subtract nums[i] to reduce currSum below or equal to target)
        while (i <= j && currSum > target)
        {
            currSum = currSum - nums[i];
            i = i + 1;
        }
        if (currSum == target)
        {
            found = true;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    if (found)
    {
        return nums.size() - maxLen;
    }
    return -1;
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
    int x;
    cout << "Enter the value of x:" << endl;
    cin >> x;
    cout << "Min operations required are: " << minOperations(nums, x);
    return 0;
}

// TC -> O(n)
// SC -> O(1)