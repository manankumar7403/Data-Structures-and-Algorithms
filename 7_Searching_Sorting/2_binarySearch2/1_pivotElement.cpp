// Pivot element is the element where the left and right side of elements are both in increasing order
// like 3,4,5,6,7,1,2
// 3,4,5,6 are in inc order and 1,2 are in inc order so 7 is the pivot element

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& arr)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end)
    {
        if (start == end)
        {
            // single element
            return start;
        }
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1])   // say 7 is mid, so 7>1
        {
            return mid;
        }
        else if(mid-1 >= 0 && arr[mid-1] > arr[mid])  // say 1 is mid, so mid-1=7 is greather than 1
        {
            return mid-1;
        }
        else if(arr[start] >= arr[mid])
        {
            // search left  
            end = mid-1;
        }
        else if(arr[start] < arr[mid])
        {
            // search right
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
// start = 0
// end = 6
// mid = 3
// arr[mid] > arr[mid+1] => 6>7? -> No
// arr[mid-1] > arr[mid] => 5>6 -> No
// arr[start] >= arr[mid] => 3>6 -> No
// arr[start] < arr[mid] => 3<6 -> Yes
//     so we do start=mid+1
// start = 4
// end = 6
// mid = 5
// arr[mid] > arr[mid+1] => 1>2? -> No
// arr[mid-1] > arr[mid] => 7>1 -> Yes
//     return mid-1 => 5-1=4
// ans=4
// arr[ans] = arr[4] = 7

int main()
{
    vector<int> arr{3,4,5,6,7,1,2};
    int ans = findPivot(arr);
    cout << "Pivot element is " << arr[ans] << endl;
    return 0;
}