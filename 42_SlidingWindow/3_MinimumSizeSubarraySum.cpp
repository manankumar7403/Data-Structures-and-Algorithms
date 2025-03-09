// 🔴🔴LEETCODE 209 -> Minimum Size Subarray Sum🔴🔴
/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
 
Follow up: If you have figured out the O(n) solution, try coding another solution of which the
time complexity is O(n log(n)).
*/
// ______________________________________________________________________________________________________________

// ⭐⭐Method 1: Sliding Window O(n)⭐⭐

#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = INT_MAX;
    while (j < nums.size())
    {
        // include current number
        sum = sum + nums[j];
        while (sum >= target)
        {
            len = min(len, j - i + 1);
            sum = sum - nums[i];
            i++;
        }
        j++;
    }
    if (len == INT_MAX)
        return 0;
    else
        return len;
}

int main()
{
    int target, n;
    cout << "Enter the target:" << endl;
    cin >> target;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int ans = minSubArrayLen(target, nums);
    cout << "Minimum size subarray sum: " << ans << endl;
}

// TC -> O(n)
// SC -> O(1)

// _____________________________________________________________________________________________________________

// ⭐⭐Method 2: Binary Search O(nlogn)⭐⭐
/*
#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    vector<long long> ans(n + 1);
    ans[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i + 1] = ans[i] + nums[i]; // ans = [0,2,5,6,8,12,15]
    }
    int res = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        int j = lower_bound(ans.begin(), ans.end(), ans[i] + target) - ans.begin();
        if (j <= n)
        {
            res = min(res, j - i);
        }
    }
    return res <= n ? res : 0;
}

int main()
{
    int target, n;
    cout << "Enter the target:" << endl;
    cin >> target;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int ans = minSubArrayLen(target, nums);
    cout << "Minimum size subarray sum: " << ans << endl;
}
*/
// TC -> O(nlogn)
// SC -> O(n)
/*
Calculate prefix sums:
s = [0, 2, 5, 6, 8, 12, 15]
Iterate over s and use lower_bound:
For i = 0: s[0] + 7 = 7, lower_bound(s, 7) gives j = 4 (since s[4] = 8), so ans = min(7, 4 - 0) = 4.
For i = 1: s[1] + 7 = 9, lower_bound(s, 9) gives j = 5 (since s[5] = 12), so ans = min(4, 5 - 1) = 4.
For i = 2: s[2] + 7 = 12, lower_bound(s, 12) gives j = 5 (since s[5] = 12), so ans = min(4, 5 - 2) = 3.
For i = 3: s[3] + 7 = 13, lower_bound(s, 13) gives j = 6 (since s[6] = 15), so ans = min(3, 6 - 3) = 3.
For i = 4: s[4] + 7 = 15, lower_bound(s, 15) gives j = 6 (since s[6] = 15), so ans = min(3, 6 - 4) = 2.
For i = 5: s[5] + 7 = 19, lower_bound(s, 19) gives j = 7 (out of bounds), so ans remains 2.
For i = 6: s[6] + 7 = 22, lower_bound(s, 22) gives j = 7 (out of bounds), so ans remains 2.
The minimal length subarray with sum ≥ 7 is [4, 3] with length 2.
*/