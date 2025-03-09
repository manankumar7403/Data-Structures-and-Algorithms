// An array arr is a mountain if the following properties hold:

// 1) arr.length >= 3
// 2) There exists some i with 0 < i < arr.length - 1 such that:
//     arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
//     arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > 
// arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    while(start < end)
    {
        if(arr[mid] < arr[mid+1])
        {
            // right search
            start = mid+1;
        }
        else
        {
            // left search
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the elements in the vector: " << endl;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int result = peakIndexInMountainArray(arr);
    cout << result << endl;
    return 0;
}

// Time complexity: O(logn)
// Space complexity: O(1)