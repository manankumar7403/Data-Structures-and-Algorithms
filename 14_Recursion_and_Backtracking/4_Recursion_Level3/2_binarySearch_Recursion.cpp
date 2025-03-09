#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>&arr, int start, int end, int target)
{
    // Base case
    // Case 1 -> key not found
    if(start > end)
    {
        return -1;
    }

    int mid = start + (end-start)/2;
    // Case 2 -> key found
    if(arr[mid] == target)
    {
        return mid;
    }

    // Baaki recursion sambhal lega
    else if(arr[mid] > target)
    {
        return binarySearch(arr, start, mid-1, target);
    }
    else
    {
        return binarySearch(arr, mid+1, end, target);
    }
}

int main()
{
    vector<int>arr = {10, 20, 40, 60, 70, 90, 99};
    int target = 99;
    int n = arr.size();
    int start = 0;
    int end = n-1;
    int ans = binarySearch(arr, start, end, target);
    cout << "Answer found at index: " << ans << endl;
    return 0;
}