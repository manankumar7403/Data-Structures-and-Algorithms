// Using Merge Sort
// Array already sorted -> Inversion count is 0.
// Array reverse sorted -> Inversion count is maximum.
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// _______________________________________________________________________________
// Example 1:
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// _______________________________________________________________________________
// Example 2:
// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// _______________________________________________________________________________
// Example 3:
// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.
// _______________________________________________________________________________

#include <iostream>
using namespace std;

long long merge(int* arr, int start, int end)
{
    int mid = start + (end - start)/2;
    int len1 = mid - start + 1;     // length of left array
    int len2 = end - mid;           // length of right array

    // assume to create arrays for len1, len2 length
    int* left = new int[len1];         // dynamically memory allocation for left array
    int* right = new int[len2];        // dynamically memory allocation for right array

    // copy values from start to mid of original array to left array
    int k = start;
    for(int i=0; i<len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values from mid+1 to end of original array to right array
    k = mid+1;
    for(int i=0; i<len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge both arrays
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;
    long long inversionCount = 0;    // will keep track of the inversion counts.

    // comparing each element of the left and right array until one or both array exhausts.
    while(leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] <= right[rightIndex])   // doing <= instead of < because in case of 10 10 10 -> number of inversions should be 0, so we need to skip the equal elements
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
            inversionCount = inversionCount + (len1 - leftIndex);
        }
    }

    // copying the remaining values from left arr to main arr.
    while(leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copying the remaining values from right arr to main arr.
    while(rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // TODO: Delete the newly created left and right arrays to free up memory space (avoid memory leaks)
    delete[] left;
    delete[] right;

    return inversionCount;
}

long long mergeSort(int* arr, int start, int end)
{
    // BASE CASE
    // start == end -> single element
    // start > end -> invalid array
    if(start >= end) return 0;

    int mid = start + (end-start)/2;
    long long inversionCount = 0;

    // store inversion count and sort the left part of the array using recursion
    inversionCount = inversionCount + mergeSort(arr, start, mid);

    // store inversion count and sort the right part of the array using recursion
    inversionCount = inversionCount + mergeSort(arr, mid+1, end);

    // Now store the inversion count and merge the 2 sorted arrays.
    inversionCount = inversionCount + merge(arr, start, end);

    return inversionCount;
}

int main()
{
    int arr[] = {2,4,1,3,5};
    int n = 5;   // size of the array
    int start = 0; // starting index
    int end = n-1;  // last index

    long long inversions = mergeSort(arr, start, end);
    cout << "Number of inversions: " << inversions << endl;

    cout << "Sorted array using merge sort: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)