// 🔴🔴🔴🔴 LEETCODE 179 -> Largest Number 🔴🔴🔴🔴
// Given a list of non-negative integers nums, arrange them such that they form the largest number and =
// return it.
// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 10^9

// _________________________________________________________________________________________

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static bool mycomp(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &nums)
{
    vector<string> snums;
    for (auto n : nums)
    {
        snums.push_back(to_string(n));
    }

    sort(snums.begin(), snums.end(), mycomp); // mycomp is a custom comparator -> for sorting elements in descending order

    if (snums[0] == "0")
    {
        return "0";
    }

    string ans = "";
    for (auto str : snums)
    {
        ans = ans + str;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    cout << "Enter the elements in the array: " << endl;
    vector<int>nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "The largest number is: " << largestNumber(nums) << endl;
    return 0;
}

// T.C. -> O(nlogn)
// S.C. -> O(n)