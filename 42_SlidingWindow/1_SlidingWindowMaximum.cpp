// 🔴🔴🔴🔴 LEETCODE 239 -> Sliding Window Maximum 🔴🔴🔴🔴
// Refer 24_Queue -> 2_Queue_Class2 -> 4_slidingWindow_1stNegElement.cpp

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left
of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves
right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/
// ___________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    // first window of k size
    for (int i = 0; i < k; i++)
    {
        // chote element remove kardo
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so that we can check out of window elements
        dq.push_back(i);
    }

    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // remaining windows ko process karna hai
    for (int i = k; i < nums.size(); i++)
    {
        // out of window ko remove kardo
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // ab firse current element ke liye chote element ko remove karna hai us particular window ke andar
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so that we can check out of window elements
        dq.push_back(i);

        // current window ka answer store karna hai
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    
    cout << "Enter the elements in the nums array:" << endl;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the size of the sliding window:" << endl;
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);
    for(auto element: result)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(k)