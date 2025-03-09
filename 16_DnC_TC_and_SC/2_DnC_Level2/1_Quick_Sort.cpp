#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    // Step 1: Choose the pivot element
    int pivotIndex = start;
    int pivotElement = arr[start];

    // Step 2: Find the right position for the pivot element and place it there
    int count = 0;
    for(int i=start+1; i<=end; i++)   // as pivot element is on start, so we start comparing from start+1
    {
        if(arr[i] <= pivotElement)
        {
            count++;
        }
    }

    // Jab main for loop se bahar aaya tab mere paas pivot ki right position ka index ready hai
    int rightIndex = start + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // Step 3: left me chote aur right me bade
    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivotElement)
        {
            i++;
        }
        while(arr[j] > pivotElement)
        {
            j--;
        }

        // Ab yaha 2 CASE ho sakte hai
        // Case1: You found the elements to swap (left me kuch bade ya right me kuch chote elements hai)
        // Case2: No need to swap (left me saare chote aur right me saare bade elements hai)
        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    // Base Case
    // start == end -> single element
    // start > end -> invalid array
    if(start >= end)
    {
        return;
    }

    // Partition Logic -> (Return Pivot Index)
    int p = partition(arr, start, end);   // p -> pivot element

    // Recursive Calls
    // Left  (from starting to the left of the pivot element)
    quickSort(arr, start, p-1);

    // Right (all elements to the right of the pivot element till the end)
    quickSort(arr, p+1, end);
}

int main()
{
    int arr[] = {8,1,20,30,6,5,60,5};
    int n = 8;
    int start = 0;
    int end = n-1;

    quickSort(arr, start, end);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity:
Best Case: Ω (N log (N))
The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into
roughly equal halves.
In this case, the algorithm will make balanced partitions, leading to efficient Sorting.

Average Case: θ ( N log (N))
Quicksort’s average-case performance is usually very good in practice, making it one of the fastest
sorting Algorithm.

Worst Case: O(N2)
The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly
unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or
largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good
pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element
before sorting.

Space Complexity:
Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack
space then, in the worst case quicksort could make O(N).
*/