// GFG
/*
Given an array A of N integers. The task is to find if there are two pairs (a, b) and (c, d) such that a+b = c+d.

Example 1:
Input:N=7 A[] = {3, 4, 7, 1, 2, 9, 8} Output: 1Explanation:(3, 7) and (9, 1) are the pairs whosesum are equal.  

Example 2:
Input:N=7 A[] = {65, 30, 7, 90, 1, 9, 8}Output: 0

Expected Time Complexity:O(N^2).
Expected Auxiliary Space:O(N^2).

Constraints:
1 ≤ N ≤ 10^3
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int findPairs(long long a[], long long n)
{
    unordered_map<int, bool> map; // sum and bool for if already present in map
    // pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if (map.find(sum) != map.end())
            {
                return true;
            }
            else
            {
                map[sum] = true;
            }
        }
    }
    return false;
}

int main()
{
    long long n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    long long a[n];
    cout << "Enter the elements in the array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    if(findPairs(a, n))
    {
        cout << "Pairs exists" << endl;
    }
    else
    {
        cout << "Pair doesn't exists" << endl;
    }
    return 0;
}

/*
Time Complexity:O(N^2) in most cases(avg) could go upto O(N^3) in worst, O(n) for insertion in map under 2 nested for loops.
Auxiliary Space:O(N).
*/