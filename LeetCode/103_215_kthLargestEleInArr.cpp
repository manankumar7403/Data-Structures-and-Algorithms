//Refer: https://www.youtube.com/watch?v=QFoNfrP7knk
// Refer 16_DnC -> 2_DnC_Level2 -> 3_QuickSelect_kthLargest -> Same Question
/*
⭐⭐ Microsoft ⭐⭐
🔴🔴 LEETCODE 215 -> kth Largest Element in An Array 🔴🔴
kth Largest Element in An Array

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

// _________________________________________________________________________________________________________
// ✅ Using Quick Select Algorithm ✅
// Time Complexity -> Average Case: O(n), Worst Case: O(n^2)
// Space Complexity -> O(1)

#include<iostream>
#include<vector>
using namespace std;

int partition_algo(vector<int> &nums, int L, int R)
{
    int P = nums[L];
    int i = L + 1;
    int j = R;

    while (i <= j)
    {
        if (nums[i] < P && nums[j] > P)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        if (nums[i] >= P) i++; // i will become 1 if i starts from 0 (Say only 1 element is present)
        if (nums[j] <= P) j--; // j will become -1 if j starts from 0 (Say only 1 element is present)
        // doing i=L+1 above,we ensure i<=j(1<=0) is false and doesn't enter while loop,returns ele as it is
    }
    // now swapping pivot element with jth element at the last
    swap(nums[L], nums[j]);
    return j; // now the pivot element is at the jth index
}

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    int L = 0;
    int R = n - 1;
    int pivot_idx = 0;

    // kth largest pivot element -> nums[k-1] (when we partition in descending order)
    while (true)
    {
        pivot_idx = partition_algo(nums, L, R);
        if (pivot_idx == k - 1) break;
        else if (pivot_idx > k - 1) R = pivot_idx - 1;
        else L = pivot_idx + 1;
    }
    return nums[pivot_idx];
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> n;
    vector<int>nums(n); 
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;
    int res = findKthLargest(nums, k);
    cout << "kth Largest Element is: " << res << endl;
}