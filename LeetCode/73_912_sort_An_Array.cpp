// 🔴🔴🔴🔴 LEETCODE 912 -> Sort an Array 🔴🔴🔴🔴
// Refer 17_DnC_Assignments_ -> 1_in_Place_MergeSort
// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the
// smallest space complexity possible.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3),
// while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

// Constraints:
// 1 <= nums.length <= 5 * 10^4
// -5 * 10^4 <= nums[i] <= 5 * 10^4
// _______________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void mergeInPlace(vector<int> &nums, int start, int mid, int end)
{
    int total_len = end - start + 1;  // total length of the array
    int gap = (total_len / 2) + (total_len % 2);  // same formula as ceil
    
    while(gap > 0)
    {
        int i = start, j = start + gap;
        while(j <= end)
        {
            if(nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2); // same ceil wala method
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    // Base Case
    // start == end -> single element
    // start > end -> invalid array

    if(start >= end) return;

    int mid = start + (end - start)/2;
    // sort the left part of the array using recursion
    mergeSort(nums,start,mid);

    // sort the right part of the array using recursion
    mergeSort(nums,mid+1,end);

    // now merge the 2 sorted arrays
    mergeInPlace(nums,start,mid,end);
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    
    vector<int>nums(n);
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    
    int start = 0;  // starting index
    int end = n-1;  // last index
    
    mergeSort(nums, start, end);

    for(int i=0; i<n; i++)
    {
        cout << nums[i] << " ";    // printing the sorted array
    }
    cout << endl;
    return 0;
}

// TC -> O(nlogn) -> keep on dividing the 'gap' to half
// SC -> O(1) -> ignoring the recursive stack, O(n) without ignoring