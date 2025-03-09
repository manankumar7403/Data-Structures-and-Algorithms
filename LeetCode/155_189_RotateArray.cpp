// 🔴🔴LEETCODE 189 -> Rotate Array🔴🔴
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5

Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

/*
#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}

int main()
{
    int n, k;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the number of steps:" << endl;
    cin >> k;
    rotate(nums, k);
    for(auto i: nums)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O(n)
// SC -> O(n)
*/
// ______________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int> &nums, int k)
{                                            // nums = 1,2,3,4,5,6,7
    k = k % nums.size();                     // prevents runtime error
    reverse(nums.begin(), nums.end());       // 7,6,5,4,3,2,1
    reverse(nums.begin(), nums.begin() + k); // 5,6,7,4,3,2,1
    reverse(nums.begin() + k, nums.end());   // 5,6,7,1,2,3,4
}

int main()
{
    int n, k;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the number of steps:" << endl;
    cin >> k;
    rotate(nums, k);
    for(auto i: nums)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O(n)
// sc -> O(1)