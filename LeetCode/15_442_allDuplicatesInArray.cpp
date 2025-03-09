// Given an integer array nums of length n where all the integers of nums are in the range [1, n]
// and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1,2]
// Output: [1]

// Example 3:
// Input: nums = [1]
// Output: []
// ____________________________________________________________________________

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> findDuplicates(vector<int> &nums)
// {
//     vector<int> ans;
//     if (nums.size() == 1)
//     {
//         return ans;
//     }
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             ans.push_back(nums[i]);
//             i++;
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

//     vector<int> result = findDuplicates(nums);

//     if (result.size() > 0)
//     {
//         cout << "Values that appear twice are: " << endl;
//         for(int num: result)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         cout << "No value appears twice." << endl;
//     }
//     return 0;
// }

// Time complexity - O(nlogn)
// ________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    unordered_set<int> seen;
    for (int num : nums)
    {
        if (seen.count(num) > 0)
        {
            ans.push_back(num);
        }
        else
        {
            seen.insert(num);
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

    vector<int> result = findDuplicates(nums);

    if (result.size() > 0)
    {
        cout << "Values that appear twice are: " << endl;
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No value appears twice." << endl;
    }
    return 0;
}

// Time Complexity - O(n)