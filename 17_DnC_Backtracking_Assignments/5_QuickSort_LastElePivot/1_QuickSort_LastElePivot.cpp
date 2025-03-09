// Last time in 16_DnC_Level 2, we learned to implement Quick Sort taking first element as pivot.
// ⭐ Here, we will implement Quick Sort taking last element as the pivot.

#include <iostream>
using namespace std;

void quickSort(int arr[], int start, int end)
{
    // Base Case
    // start == end -> single element
    // start > end -> invalid array
    if(start >= end)
    {
        return;
    }

    int pivot = end;   // taking pivot as last element
    int i = start - 1;
    int j = start;
    while(j < pivot)
    {
        if(arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);  // i ko -1 se start kar rhe aur j ko 0 se aur agar arr[j] < arr[pivot] hai toh i ko aage badha ke arr[i] ko arr[j] se swap karte rahenge. 
        }
        j++; // jab j pivot ke equal hua toh j++ kar denge kyuki vo less than pivot nahi hai aur vo out of bound chala jayega.
    }
    i++;
    // yaha i++ kiya kyuki is i++ krne se pehle jaha i tha us i se leke piche start tak sab i+1 se chote hai
    // aur i+1 pivot ki right position hai, toh agar hum i+1 karke, pivot(last element) ko i (now i+1)
    // se swap kar denge toh initial pivot wala element apni right position par pahuch jayega and then us
    // element (pivot) ke left me usse chote aur right me usse bade elements honge 
    // now i is the right position for the pivot element
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i-1); // jo abhi pivot nikala uske left side wali subarray ko sort karne ke liye
    quickSort(arr, i+1, end); // jo abhi pivot nikala uske right side wali subarray ko sort karne ke liye
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

Worst Case: O(N^2)
The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly
unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or
largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good
pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element
before sorting.

Space Complexity:
Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack
space then, in the worst case quicksort could make O(N).
*/