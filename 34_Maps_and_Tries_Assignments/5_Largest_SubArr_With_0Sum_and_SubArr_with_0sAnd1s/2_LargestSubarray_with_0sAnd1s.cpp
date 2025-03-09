// GFG -> similar to Largest Subarray with 0 sum
/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:
Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.

Example 2:
Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array
arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
0 <= A[] <= 1
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int maxLen(int arr[], int N)
{
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // max length of subarr with 0 sum

    for (int i = 0; i < N; i++)
    {
        int val = arr[i] == 0 ? -1 : 1;
        csum = csum + val;
        if (csum == 0)
        {
            ans = max(ans, i + 1); // jaha par hai currently uska sum hi 0 hai
        }
        else if (map.find(csum) == map.end()) // end tak pahuch gye lekin sum nhi mila toh us sum ko uske index ke corresponding store kar diya
        {
            map[csum] = i;
        }
        else
        {
            // map ke andar csum ke entry mil gyi hai
            ans = max(ans, i - map[csum]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Length of max subarray with 0s and 1s: " << maxLen(arr, n) << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(n)