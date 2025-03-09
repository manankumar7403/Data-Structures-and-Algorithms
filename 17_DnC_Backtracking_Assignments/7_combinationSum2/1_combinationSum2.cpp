// 🔴🔴🔴🔴 LEETCODE 40 -> Combination Sum 2 🔴🔴🔴🔴
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations
in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
// ________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
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
        if (i > index && candidates[i] == candidates[i - 1]) // suppose array sort ke baad 1,2,2,2,5 hai toh ek
        {                                              // 2 pick kiya (index 1), then i+1(index 2) par bhi 2 hai so candidates[i] == candidates[i-1] ho rha, we skip that repetitive element
            continue;
        }
        v.push_back(candidates[i]);                                               // sabse pehle first element(2) ko daal diya
        combinationSum_helper(candidates, target - candidates[i], ans, v, i + 1); // i+1 coz ek element ko dobara repeat nhi karwana hoga

        // Backtracking -> agar target 0 nhi ban rha aur < 0 ho ja rha toh last element jo try kiya tha usko pop karo
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
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

    vector<vector<int>> result = combinationSum2(candidates, target);
    cout << "The combination sum is: " << endl;
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


// TC -> O(2^n)
// SC -> O(n)