// LEETCODE 658
// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
// The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

// Constraints:
// 1 <= k <= arr.length
// 1 <= arr.length <= 10^4
// arr is sorted in ascending order.
// -10^4 <= arr[i], x <= 10^4

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoPtrMethod(vector<int>& arr, int k, int x)
{
    int l=0, h=arr.size()-1;
    while(h-l >= k)
    {
        if(x - arr[l] > arr[h] - x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return vector<int>(arr.begin()+l, arr.begin()+h+1);
}

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    return twoPtrMethod(arr, k, x);
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
    cout << "Enter the value of k: " << endl;
    int k;
    cin >> k;
    cout << "Enter the size of x: " << endl;
    int x;
    cin >> x;
    
    vector<int> result = findClosestElements(arr,k,x);
    for(auto j: result)
    {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}

// Time complexity - O(n-k)
// Space complexity - O(k)

// This is Top to Bottom Approach.
// Reducing the window size.