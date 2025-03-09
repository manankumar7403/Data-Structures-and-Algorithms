// GFG
/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray
with sum 0.

Examples:
Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 10^5
-1000 <= arr[i] <= 1000, for each valid i
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxLen(vector<int> &arr, int n)
{
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // max length of subarr with 0 sum

    for (int i = 0; i < n; i++)
    {
        csum = csum + arr[i];
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
    vector<int>arr(n);
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Length of max subarray with 0 sum: " << maxLen(arr, n) << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(n)