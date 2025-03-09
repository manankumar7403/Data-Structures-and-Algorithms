// Given an array of integers nums sorted in non-decreasing order, find the starting and ending
// position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(logn) runtime complexity.
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start <= end)
    {
        if(nums[mid] == target)
        {
            // ans store and then move left to check whether the first occurrence is there on the left or the mid is the first occurrence
            ans = mid;
            // search left
            end = mid-1;
        }
        else if(target > nums[mid])
        {
            // search right
            start = mid+1;
        }
        else if(target < nums[mid])
        {
            // search left
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int lastOccurrence(vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start <= end)
    {
        if(nums[mid] == target)
        {
            // ans store and then move right to check whether the last occurrence is there on the right or the mid element is the last occurrence
            ans = mid;
            // right search
            start = mid+1;
        }
        else if(target < nums[mid])
        {
            // left search
            end = mid-1;
        }
        else if(target > nums[mid])
        {
            // right search
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    int left = firstOccurrence(nums, target);
    int right = lastOccurrence(nums, target);
    if(left <= right)
    {
        return {left, right};
    }
    else{
        return {-1, -1};
    }
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the vector: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the value of the target: " << endl;
    cin >> target;
    vector<int> result = searchRange(nums, target);
    for(auto j: result)
    {
        cout << j <<" ";
    }
    cout << endl;
    return 0;
}