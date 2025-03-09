// GFG
// ⭐⭐ Searching an element in a sorted array (ternary search)
/*
Given a sorted array arr[] of size N and an integer K. The task is to check if K is present in the array or not using
ternary search.
Ternary Search- It is a divide and conquer algorithm that can be used to find an element in an array. In this algorithm,
we divide the given array into three parts and determine which has the key (searched element).

1) Initialization:
Set two pointers, left and right, initially pointing to the first and last elements of our search space.

2) Divide the search space:
Calculate two midpoints, mid1 and mid2, dividing the current search space into three roughly equal parts:
mid1 = left + (right – left) / 3
mid2 = right – (right – left) / 3
The array is now effectively divided into [left, mid1], (mid1, mid2), and [mid2, right].

3) Comparison with Target:.
If the target is equal to the element at mid1 or mid2, the search is successful, and the index is returned
If the target is less than the element at mid1, update the right pointer to mid1 – 1.
If the target is greater than the element at mid2, update the left pointer to mid2 + 1.
If the target is between the elements at mid1 and mid2, update the left pointer to mid1 + 1 and the right pointer to
mid2 – 1.

4) Repeat or Conclude:
Repeat the process with the reduced search space until the target is found or the search space becomes empty.
If the search space is empty and the target is not found, return a value indicating that the target is not present in the array.

Example 1:
Input:
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is 1.

Example 2:
Input:
N = 5, K = 2
arr[] = {1,3,4,5,6}
Output: -1
Exlpanation: Since, 2 is not present in the array, output is -1.
*/

#include<iostream>
using namespace std;

int ternarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n-1;

    while(right >= left)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check if key is present at any mid
        if(arr[mid1] == key) return mid1;
        if(arr[mid2] == key) return mid2;

        // not present at mid, check at other location
        if(key < arr[mid1])
        {
            right = mid1 - 1;
        }
        else if(key > arr[mid2])
        {
            left = mid2 + 1;
        }
        else
        {
            // key lies between mid1 and mid2
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    // key not found
    return -1;
}

int main()
{
    int n, k;
    cout << "Enter the size of the sorted array:" << endl;
    cin >> n;
    cout << "Enter the target:" << endl;
    cin >> k;
    int arr[n];
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int res = ternarySearch(arr, n, k);
    if(res == -1)
    {
        cout << k <<" not present in the array." << endl;
    }
    else
    {
        cout << k << " is present at index " << res << endl;
    }
    return 0;
}

// Time Complexity: O(2 * log3n), where n is the size of the array.
// Auxiliary Space: O(1)

/*
Binary search Vs Ternary Search:
The time complexity of the binary search is less than the ternary search as the number of comparisons in ternary search is
much more than binary search. Binary Search is used to find the maxima/minima of monotonic functions where as
Ternary Search is used to find the maxima/minima of unimodal functions.

Note: We can also use ternary search for monotonic functions but the time complexity will be slightly higher as compared to
binary search.

Advantages:
1) Ternary search can find maxima/minima for unimodal functions, where binary search is not applicable.
2) Ternary Search has a time complexity of O(2 * log3n), which is more efficient than linear search and comparable to
binary search.
3) Fits well with optimization problems.

Disadvantages:
1) Ternary Search is only applicable to ordered lists or arrays, and cannot be used on unordered or non-linear data sets.
2) Ternary Search takes more time to find maxima/minima of monotonic functions as compared to Binary Search.
*/