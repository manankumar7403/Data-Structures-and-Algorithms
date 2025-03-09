// ⭐⭐⭐⭐ Merge Sort is based on Divide and Conquer Approach ⭐⭐⭐⭐

#include <iostream>
using namespace std;

void merge(int* arr, int start, int end)
{
    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;  // length of left array
    int len2 = end - mid;  // length of right array

    // assume to create arrays for len1, len2 length
    int* left = new int[len1];   // dynamically memory allocation for creating left array
    int* right = new int[len2];  // dynamically memory allocation for crearing right array

    // copy values from start to mid of original array in the left array
    int k = start;
    for(int i=0; i<len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values from mid+1 to end of original array in the right array
    k = mid+1;
    for(int i=0; i<len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge both arrays - logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    // comparing each element of left and right array until one of the array exhausts
    while(leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // copying remaining values from left array into the main array
    while(leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copying remaining values from right array into the main array
    while(rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // TO DO: DELETE THE NEWLY CREATED LEFT AND RIGHT ARRAYS TO FREE UP MEMORY SPACE (AVOID MEMORY LEAKS).
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int start, int end)   // int* arr is same as int arr[]
{
    // Base Case
    // start == end -> single element
    // start > end -> invalid array

    if(start >= end) return;

    int mid = start + (end - start)/2;
    // sort the left part of the array using recursion
    mergeSort(arr,start,mid);

    // sort the right part of the array using recursion
    mergeSort(arr,mid+1,end);

    // now merge the 2 sorted arrays
    merge(arr,start,end);
}

int main()
{
    int arr[] = {4,13,5,13,2,12,6,7,8,5,6,9,10}; // creating an array
    int n = 13; // size of array arr

    int start = 0;  // starting index
    int end = n-1;  // last index
    mergeSort(arr, start, end);     // this function will define left and right arrays for sorting and merging

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";    // printing the sorted array
    }
    cout << endl;
    return 0;
}


/*
The provided C++ code implements the Merge Sort algorithm, which is based on the Divide and Conquer approach.
### Time Complexity:

**1. Merge Sort:**
   - In the `mergeSort` function, the array is divided into two halves recursively until individual elements are reached. The division happens in a binary fashion.
   - The time complexity of the `mergeSort` function is O(n log n), where 'n' is the number of elements in the array.

**2. Merge Operation:**
   - The `merge` function is called to merge two sorted halves of the array.
   - The merging operation takes O(n) time, where 'n' is the total number of elements in the merged arrays.

**Overall Time Complexity:**
   - The overall time complexity of the Merge Sort algorithm is dominated by the recursive calls and the merging operation.
   - Therefore, the overall time complexity is O(n log n).

### Space Complexity:

**1. Auxiliary Arrays:**
   - The `merge` function uses two auxiliary arrays (`left` and `right`) to store the divided halves of the array temporarily.
   - The space complexity of the auxiliary arrays is O(n), where 'n' is the total number of elements in the array.

**2. Recursion Stack:**
   - The space complexity is also influenced by the recursion stack during the execution of the `mergeSort` function.
   - The maximum depth of the recursion tree is log(n) (base 2), where 'n' is the number of elements in the array.
   - Therefore, the space complexity due to recursion is O(log n).

**Overall Space Complexity:**
   - The overall space complexity is the sum of the space used by the auxiliary arrays and the recursion stack.
   - So, the overall space complexity is O(n) + O(log n), which can be simplified to O(n).

In summary:
- Time Complexity: O(n log n)
- Space Complexity: O(n)
*/
