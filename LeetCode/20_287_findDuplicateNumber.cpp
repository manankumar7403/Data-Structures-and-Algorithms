// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n]
// inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

// 🔴🔴🔴🔴 Using Floyd's Tortoise and Hare (Cycle Detection) algorithm -> without modifying the array
// and using time complexity O(n) and space complexity - O(1) 🔴🔴🔴🔴🔴

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    int n;
    cout << "Enter the size of the vector array: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the vector array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int result = findDuplicate(nums);
    cout << result << endl;
    return 0;
}