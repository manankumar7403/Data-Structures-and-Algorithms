// 🔴🔴🔴🔴 LEETCODE 47 -> Permutations 2 🔴🔴🔴🔴
// Refer 16_DnC_ -> DnC_Level2 -> Permutations of a String
// Refer 17_DnC -> 9_permutations2 -> 1_permutations2.cpp -> SAME QUESTION
/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in
any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
// ______________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void permuteUniqueHelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    // Base case
    if (start >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited; // this will help to remove duplicate permutations
    // Swapping
    for (int i = start; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end()) // matlab already vo number mil gya(yaani swap ho chuka hai) map ke end hone se pehle
        {
            continue; // to us element ko consider nahi kar rahe aur continue kar de rahe hai
        }
        visited[nums[i]] = true; // agar present nhi hai toh true mark kar denge(ab insert kar denge)
        // swap
        swap(nums[i], nums[start]);

        // recursive call
        permuteUniqueHelper(nums, ans, start + 1);

        // backtracking -> ye niche swap wali line kyu likhi hai? -> To recreate the original input array.
        // We use &str -> pass by reference, so the arr changes at some recursive call and is not abc
        // In order to work on OG arr only, we swap the elements back such that the arr remains original only.
        // Backtracking ka concept hi yahi hai ki starting point se ending point ka ek tareeka dhundo,
        // then wapas starting point pe aao, dusra tareeka dhundo, wapas starting point pe aao...
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
    return ans;
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
    cout << "The permutations are: " << endl;
    vector<vector<int>> result = permuteUnique(nums);
    for (auto i : result)
    {
        cout << "[";
        for (auto num : i)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}

// TC -> O(n * n!)
// SC -> O(n)