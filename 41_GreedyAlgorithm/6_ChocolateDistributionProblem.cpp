//GFG
/*
Given an array A[] of positive integers of size N, where each value represents the number of chocolates in a packet.
Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among
M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student
is minimum.

Example 1:
Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M
packets :{3, 4, 9, 7, 9}.

Example 2:
Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following M
packets :{3, 2, 4}.
Your Task:
You don't need to take any input or print anything. Your task is to complete the function findMinDiff() which takes array A[],
N and M as input parameters and returns the minimum possible difference between maximum number of chocolates given to a student
and minimum number of chocolates given to a student.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^9
1 ≤ M ≤ N
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    // check differences in m sized window
    int i = 0;
    int j = m - 1;
    int diff = INT_MAX;
    while (j < n)
    {
        int newDiff = a[j] - a[i];
        diff = min(diff, newDiff);
        j++;
        i++;
    }
    return diff;
}

int main()
{
    long long n;
    cout << "Enter the number of packets:" << endl;
    cin >> n;
    vector<long long>a(n);
    cout << "Enter the number of chocolates in each packet:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    long long m;
    cout << "Enter the number of children:" << endl;
    cin >> m;
    long long result = findMinDiff(a, n, m);
    cout << "Minimum possible difference: " << findMinDiff(a, n, m);
    return 0;
}

// Time Complexity: O(N*Log(N))
// Auxiliary Space: O(1)