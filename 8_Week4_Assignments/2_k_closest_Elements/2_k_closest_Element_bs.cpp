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

int lowerBound(vector<int> &arr, int x)   // lower bound is the closest element to x
{
    int start = 0, end = arr.size() - 1;
    int ans = end;                       // in sorted array the rightmost element will be the closest, say arr = [3,5,8,10], k=2, x=15. The closest to 15 if all the elements are lower than 15(sorted arr), the end would be the closest so [8,10] would be the answer.
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= x)
        {
            ans = mid; // searching in left
            end = mid - 1;
        }
        else if (x > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> bs_Method(vector<int> &arr, int k, int x)
{
    int h = lowerBound(arr, x);  // lower bound is the closest element to x
    int l = h - 1;
    while (k--)         // keep reducing k unitl it becomes zero to get the desired k values.
    {
        if (l < 0)    // if the lowerbound(h) is at leftmost position then l=h-1 = 0-1=-1 => it will go to negative index(error), so if lowerbound is leftmost then the remaining closest elements would be towards the left, so we keep doing h++. 
        {
            h++;
        }
        else if (h >= arr.size()) // similarly if lowerbound(h) is at the righmost position then all the remaining closest elements would be on the left, so we keep doing l--.
        {
            l--;
        }
        else if (x - arr[l] > arr[h] - x)
        {
            h++;
        }
        else
        {
            l--;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + h);  // at end we get l-1 and h+1 so we write l+1 to get the lower position and since last element is excluded and h is already at h+1, we simply wrote h to get h+1-1 elements
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    return bs_Method(arr, k, x);
}

int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the elements in the vector: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of k: " << endl;
    int k;
    cin >> k;
    cout << "Enter the size of x: " << endl;
    int x;
    cin >> x;

    vector<int> result = findClosestElements(arr, k, x);
    for (auto j : result)
    {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}

// Time complexity - O(logn + k)
// Space complexity - O(k)

// If k is significantly smaller than n, the binary search might be more efficient. However,
// if k is close to n, the two pointer method might be more favorable due to its linear time complexity.

// This is the Bottom to Top Approach.
// Expanding the window size.