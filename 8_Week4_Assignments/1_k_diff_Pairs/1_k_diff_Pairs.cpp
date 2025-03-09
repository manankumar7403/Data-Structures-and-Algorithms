// LEETCODE 532
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Example 1:
// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

// Example 2:
// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

// Example 3:
// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

// Constraints:
// 1 <= nums.length <= 10^4
// -10^7 <= nums[i] <= 10^7
// 0 <= k <= 10^7

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &nums, int start, int x)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == x)
        {
            return mid;
        }
        else if (x > nums[mid])
        {
            // search right
            start = mid + 1;
        }
        else
        {
            // search left
            end = mid - 1;
        }
    }
    return -1;
}

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // currently at nums[i], need to search nums[i] + k in right sub-array
        if (binarySearch(nums, i + 1, nums[i] + k) != -1) // i+1 coz required to search in right sub-array
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the elements in the vector: " << endl;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k: " << endl;
    int k;
    cin >> k;

    int result = findPairs(nums, k);
    cout << "The result is " << result << endl;
    return 0;
}

// Time Complexity - O(nlogn) -> sort function is O(nlogn) and binary search is logn but as it is being
// called inside a for loop it becomes - O(nlogn)
// So, O(nlogn) + O(nlogn) => O(nlogn)

// Space Complexity - O(n) as set pair is used.