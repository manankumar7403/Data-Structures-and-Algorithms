// ⭐⭐ Backtracking Problem ⭐⭐
// 🔴🔴🔴🔴 LEETCODE 39 -> Combination Sum 🔴🔴🔴🔴
// Refer 17_DnC_ 6_Combination Sum
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any
order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique
if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than
150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/
// _______________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void combinationSum_helper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v,
int index)
{
    // Base Case
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }

    if (target < 0)
    {
        return;
    }
    // ____________________________________________________________________________

    for (int i = index; i < candidates.size(); i++)
    {
        v.push_back(candidates[i]); // sabse pehle first element(2) ko daal diya
        combinationSum_helper(candidates, target - candidates[i], ans, v, i);

        // Backtracking -> agar target 0 nhi ban rha aur < 0 ho ja rha toh last element jo try kiya tha usko pop karo
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;                                        // jo current elements pick kar rakhe hai target sum banane ke liye vo isme store kar rhe hai
    combinationSum_helper(candidates, target, ans, v, 0); // 0 is the index where we are begin from
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    
    cout << "Enter the elements in the array: " << endl;
    vector<int> candidates(n);
    for(int i=0; i<n; i++)
    {
        cin >> candidates[i];
    }

    int target;
    cout << "Enter the value of the target: " << endl;
    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "The combinations are: " << endl;
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

// Time Complexity: O(2^n)
// Space Complexity: O(n)