// Nearly sorted array : [10, 3, 40, 20, 50, 80, 70]
// Sorted array        : [3, 10, 20, 40, 50, 70, 80]
// In nearly sorted array the element is either present at i/i-1/i+1 compared to ith element in sorted 
// array

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(mid-1 >= start && arr[mid-1] == target)
        {
            return mid-1;
        }
        else if(mid+1 <= end && arr[mid+1] == target)
        {
            return mid+1;
        }
        else if(target > arr[mid])
        {
            // right search
            start = mid + 2; // doing +2 instead of +1 because mid+1 has already been searched
        }
        else
        {
            // left search
            end = mid - 2; // doing -2 instead of -1 because mid-1 has already been searched
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main()
{
    vector<int> arr{10, 3, 40, 20, 50, 80, 70};
    int target;
    cout << "Enter the value of target: " << endl;
    cin >> target;

    int ans = binarySearch(arr, target);
    cout << "index of " << target << " is " << ans << endl;
    return 0;
}