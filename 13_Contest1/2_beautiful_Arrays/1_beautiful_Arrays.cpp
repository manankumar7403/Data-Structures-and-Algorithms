/*
Q -> Given an array arr[] of length, N. One has to partition the array into multiple beautiful arrays.
Definition of a Beautiful Array: If we sort the array, no two neighbor elements have a difference of more than K.
The task is to find the minimum number of beautiful arrays one can create from the given array
Note: To minimize the number of beautiful arrays, one can add X numbers of elements in the original array.

Example 1:
Input: arr[] = {1,1,3,1,1,6,1,1,8,10}
X = 3, K = 1
Output: 2
Explanation: You can add atmost 3 elements in the original array to make the array beautiful from the given
array.
So lets say you add 2, 7 and 9 in the original array. Now we can make two beautiful array from it.
arr1[] = {1,1,1,1,1,1,2,3}
arr2[] = {6,7,8,9,10}
So, the output will be 2.


Example 2:
Input: arr[] = {1,7,10}
X = 3, K = 2
Output: 1
Explanation: You can add 3, 5, and 8 in the original array to make itself a beautiful array.
new arr[] = {1,3,5,7,8,10}
Here no two neighboring elements difference greater than X.

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^9
1 <= k <= 10^9
0 <= x <= 10^9
*/

// ___________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int beautifulArray(vector<int>&a, int x, int k)
{
    int n = a.size();   // stores the size of the array

    // Sorting the input array in ascending order
    sort(a.begin(), a.end());

    // Find the differences between consecutive elements in the sorted vector a
    // and then pushing them in a vector if the difference is more than the given difference k.
    vector<int> diff;
    for(int i=1; i < n; i++)
    {
        int temp = a[i] - a[i-1];
        if(temp > k)
        {
            diff.push_back(temp);
        }
    }

    // Sorting the differences vector in ascending order.
    sort(diff.begin(), diff.end());

    int count = 0;
    for(int i=0; i < diff.size(); i++)
    {
        int val = diff[i];

        // Compute how many elements of difference k are needed to reduce val to <= k
        int res = val/k;
        if(val % k == 0)
        {
            res = res - 1;
        }

        // In some cases, the value of res could be more than x (max elements available to be inserted initially)
        int mini = min(res, x);
        x = x - mini;   // updates the number of elements available after inserting.

        val = val - mini * k;
        if(val <= k)
        {
            count++;
        }

        // If no more elements are available to be inserted to reducethe difference to <=k, we break out.
        if(x <= 0)
        {
            break;
        }
    }
    
    // Computing the final ans
    int ans = diff.size() - count + 1;
    // diff.size() - count is done to check how many differences were we able to successfully reduce to <= k

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array a:" << endl;
    cin >> n;
    vector<int>a(n);
    cout << "Enter the elements in the array a:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int x, k;
    cout << "Enter the value of x:" << endl;
    cin >> x;
    cout << "Enter the value of k:" << endl;
    cin >> k;
    cout << "Number of beautiful arrays that can be formed are: " << beautifulArray(a, x, k);
    cout << endl;
    return 0;
}

// TC -> O(n log n + m log m)
// SC -> O(m)