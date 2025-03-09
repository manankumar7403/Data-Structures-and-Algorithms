// same as find peak index in a mountain array -> 25_852
// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains
// multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be
// strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Example 2:
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number
// 5 where the peak element is 6.

// Constraints:
// 1 <= nums.length <= 1000
// -2^31 <= nums[i] <= 2^31 - 1
// nums[i] != nums[i + 1] for all valid i.



#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;
    while(start < end)
    {
        if(nums[mid] < nums[mid+1])
        {
            // right search
            start = mid+1;
        }
        else
        {
            // left search
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the elements in the vector: " << endl;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    int result = findPeakElement(nums);
    cout << result << endl;
    return 0;
}

// Time complexity: O(logn)
// Space complexity: O(1)
