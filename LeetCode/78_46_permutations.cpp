// 🔴🔴🔴🔴 LEETCODE 46 -> Permutations 🔴🔴🔴🔴
// Refer 16_DnC_ -> DnC_Level2 -> Permutations of a string
// Refer 17_DnC_Backtracking -> 8_permutations -> 1_permutations.cpp -> SAME QUESTION
/*
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
// ________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void permuteHelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    // Base case
    if (start >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    // Swapping
    for (int i = start; i < nums.size(); i++)
    {
        // swap
        swap(nums[i], nums[start]);

        // recursive call
        permuteHelper(nums, ans, start + 1);

        // backtracking -> ye niche swap wali line kyu likhi hai? -> To recreate the original input array.
        // We use &str -> pass by reference, so the arr changes at some recursive call and is not abc
        // In order to work on OG arr only, we swap the elements back such that the arr remains original only.
        // Backtracking ka concept hi yahi hai ki starting point se ending point ka ek tareeka dhundo,
        // then wapas starting point pe aao, dusra tareeka dhundo, wapas starting point pe aao...
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteHelper(nums, ans, 0);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "The permutations are: " << endl;
    vector<vector<int>> result = permute(nums);
    for(auto i: result)
    {
        cout << "[";
        for(auto num: i)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}

// TC -> O(n!)
// SC -> O(n)
