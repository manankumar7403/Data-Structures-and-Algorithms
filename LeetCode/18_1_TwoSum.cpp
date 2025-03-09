// 🔴🔴LEETCODE 1 -> Two Sum🔴🔴
// Given an array of integers nums and an integer target, return indices of the two numbers
// such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same
// element twice.
// You can return the answer in any order. 

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]
// ___________________________________________________________________________

// ⭐⭐Method 1: Brute Force⭐⭐
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> twoSum(vector<int>& nums, int target)
// {
//     vector<int> ans;
//     for(int i=0; i<nums.size()-1; i++)
//     {
//         for(int j=i+1; j<nums.size(); j++)
//         {
//             if(nums[i]+nums[j] == target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;

//     vector<int> nums(n);
//     cout << "Enter the elements in the array: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     int target;
//     cout << "Enter the target: " << endl;
//     cin >> target;

//     vector<int> result = twoSum(nums, target);

//     for(int j: result)
//     {
//         cout << j << " ";
//     }
//     return 0;
// }

// TC -> O(n^2)
// SC -> O(1)
// __________________________________________________________________________________________

// ⭐⭐Method 2: Using sliding window⭐⭐
/*
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

static bool myComp(pair<int, int>a, pair<int, int>b)
{
    return a.first < b.first;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<pair<int, int>> data;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++)
    {
        int val = nums[i];
        int index = i;
        data.push_back({val, index});
    }

    sort(data.begin(), data.end(), myComp);

    int start = 0;
    int end = data.size()-1;
    while(start < end)
    {
        if(data[start].first + data[end].first == target)
        {
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if(data[start].first + data[end].first > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}   

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;

    vector<int> result = twoSum(nums, target);

    for(int j: result)
    {
        cout << j << " ";
    }
    return 0;
}
// TC -> O(nlogn)
// SC -> O(n)
*/

// ___________________________________________________________________________________________________________________

// ⭐⭐Method 3: Using unordered map⭐⭐
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> numToIndex;
    vector<int> ans;
    for(int i=0; i<nums.size(); i++)
    {
        int complement = target - nums[i];
        if(numToIndex.find(complement) != numToIndex.end())
        {
            ans.push_back(numToIndex[complement]);
            ans.push_back(i);
            break;
        }
        numToIndex[nums[i]] = i;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;

    vector<int> result = twoSum(nums, target);

    for(int j: result)
    {
        cout << j << " ";
    }
    return 0;
}

// TC -> O(n)
// SC -> O(n)