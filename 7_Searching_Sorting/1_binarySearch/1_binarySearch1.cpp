// Assume that the array is sorted
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        int element = arr[mid];
        if(element == target)
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
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    // element not found
    return -1;
}

int main()
{
    int arr[] = {2,4,6,8,10,12,16};
    int size = 7;
    int target = 2;

    int indexOfTarget = binarySearch(arr, size, target);
    if(indexOfTarget == -1)
    {
        cout << "Target not found!" << endl;
    }
    else
    {
        cout << "Target found at index " << indexOfTarget << endl;
    }
    return 0;
}

// Time complexity - O(logn)
// Say first iteration has n elements
// 1 - n
// 2 - n/2
// 3 - n/4
// 4 - n/8....
// So, n,n/2,n/4,n/8.......n/2^k = 1
// n/2^k = 1
// n = 2^k
// logn = k
// => T.C. = O(logn)


// Pre-defined binary search function using STL -> binary_search(vector_name.begin(), vector_name.end(), number_to_be_searched)
// #include <algorithm>
// #include <vector>
// vector<int> v{1,2,3,4,5,6}
// if(binary_search(v.begin(), v.end(), 3))
// {
//     cout << "Found!" << endl;
// }
// else
// {
//     cout << "Not found!" << endl;
// }
// return 0;