// 🔴🔴🔴🔴 Refer to 7_Searching Sorting -> Binary Search class 1 and 2 to 
// understand more clearly 🔴🔴🔴🔴

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown
// pivot index k (1 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target
// if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// Constraints:
// 1 <= nums.length <= 5000
// -10^4 <= nums[i] <= 10^4
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -10^4 <= target <= 10^4



#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = arr[mid];
        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // Search in left
            end = mid - 1;
        }
        else
        {
            // Search in right
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    // element not found
    return -1;
}

int findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }
        else if (arr[start] >= arr[mid])
        {
            // search left
            end = mid - 1;
        }
        else if (arr[start] < arr[mid])
        {
            // search right
            start = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int search(vector<int> &nums, int target)
{
    int pivotIndex = findPivot(nums);
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        // search in Array A
        int ans = binarySearch(nums, target, 0, pivotIndex);
        return ans;
    }

    if (pivotIndex + 1 < nums.size() &&
        target >= nums[pivotIndex + 1] && target <= nums[nums.size() - 1])
    {
        // search in Array B
        int ans = binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
        return ans;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the value of the target: " << endl;
    cin >> target;
    int result = search(nums, target);
    cout << result;
    cout << endl;
    return 0;
}

// arr = [4,5,6,7,0,1,2], target = 0
// First we find the pivot element using findPivot function. In the above array, 7 is the pivot element
// as numbers before 7 are sorted (inc order) and numbers after 7 are sorted (inc order).

// 7 is the pivot element (index 3).
// Now we have 2 sorted arrays on either side of the pivot element.
// A = [4,5,6] on the left and B = [0,1,2] on the right.

// Now we come to the binary search function after the pivot element has been found => 7
// In search function we check
// target >= nums[0] && target <= nums[pivotIndex]
// 0 >= nums[0] && 0 <= nums[3]
// 0 >= 4 && 0 <= 7 -> False
// Therefore target is not in Array A = [4,5,6]


// pivotIndex + 1 < nums.size() && target >= nums[pivotIndex + 1] && target <= nums[nums.size() - 1]
// 0 >= nums[4] && 0 <= nums[6]
// 0 >= 0 && 0 <= 2 -> True
// So target is in Array B

// Now we call the binary search function

// int ans = binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
// return ans;

// and find the target 0 in sorted array B = [0,1,2]