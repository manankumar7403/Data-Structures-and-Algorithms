// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> arr{10, 1, 7, 6, 14, 9};
//     sort(arr.begin(), arr.end());

//     // printing the sorted array
//     for(int i=0; i<arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// _______________________________________________________________________________________
// To implement the in-built sort function on an array:
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 1, 7, 6, 14, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size);

    // printing the sorted array
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// cout << sizeof(arr) << endl; -> Total size of array - 4*6 = 24
// cout << sizeof(arr[0]) << endl; -> Size of one element = 4

// int size = sizeof(arr) / sizeof(arr[0]);
// cout << size << endl;

// Total size (number of elements) = 24/4 = 6
// _______________________________________________________________________________________

// The built-in sort function in C++ uses a hybrid sorting algorithm called 'Introsort'.
// Introsort is a combination of three sorting algorithms: quicksort, heapsort, and insertion sort.
// It chooses the most efficient algorithm to use based on the size and characteristics of the input data.

// * Quicksort is a divide-and-conquer algorithm that works by partitioning the input data into
// two subarrays, one containing elements smaller than a pivot element and the other containing
// elements larger than the pivot element. It then recursively sorts the two subarrays.

// * Heapsort is a sorting algorithm that uses a heap data structure. A heap is a complete binary tree
// where the parent node is always greater than or equal to its child nodes. Heapsort works by building
// a heap from the input data and then repeatedly removing the largest element from the heap until the
// heap is empty.

// * Insertion sort is a simple sorting algorithm that works by iterating over the input data and inserting
// each element into its correct position in the sorted sequence.

// Introsort works by first using quicksort to sort the first few elements of the input data.
// It then switches to heapsort if the input data is too large or if quicksort is not performing well.
// Finally, it switches to insertion sort if the input data is very small.

// This hybrid approach allows Introsort to achieve good performance on a wide variety of input data.
// In the worst case, Introsort has a time complexity of O(n log n), but in the average case, it has a
// time complexity of O(n log n).

// In addition to Introsort, the C++ standard library also provides a number of other sorting algorithms,
// such as merge sort and selection sort. However, Introsort is the algorithm that is typically used by
// the built-in sort function.