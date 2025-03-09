// 🔴🔴LEETCODE 525 -> Contiguous Array🔴🔴
/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/
// _________________________________________________________________________________________________________
// 🔴🔴Method 1: BRUTE FORCE🔴🔴
/*
#include<iostream>
#include<vector>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int zeroCount = 0;
        int onesCount = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 0)
                zeroCount++;
            else if (nums[j] == 1)
                onesCount++;

            if (zeroCount == onesCount)
            {
                ans = max(ans, j - i + 1);
            }
        }
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
    cout << "Max length: " << findMaxLength(nums);
    return 0;
}

// Getting TLE
// TC -> O(n^2)
// SC -> O(1)
*/

// _________________________________________________________________________________________________________
// 🔴🔴Method 2: Map🔴🔴

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int ans = 0;
    unordered_map<int, int> mpp; // sum, index
    mpp[0] = -1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            sum += -1;
        else if (nums[i] == 1)
            sum += 1;

        if (mpp.find(sum) != mpp.end())
        {
            int index = mpp[sum];
            int len = i - index;
            ans = max(ans, len);
        }
        else
        {
            mpp[sum] = i;
        }
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
    cout << "Max length: " << findMaxLength(nums);
    return 0;
}

// TC -> O(N*logN) if using map and O(N) if using unordered map in best and avg and O(N^2) in unordered map worst case
// SC -> O(N) -> worst case n preifx sum can be stored