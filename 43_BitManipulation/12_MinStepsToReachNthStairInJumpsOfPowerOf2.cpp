// GFG
// https://www.geeksforgeeks.org/minimum-steps-to-reach-the-nth-stair-in-jumps-of-perfect-power-of-2/
// Minimum steps to reach the Nth stair in jumps of perfect power of 2

// ⭐⭐Same as count set bits logic⭐⭐
/*
Given N stairs, the task is to find the minimum number of jumps of perfect power of 2 requires to reach the Nth stair.

Examples: 
Input: N = 5 
Output: 
Explanation: 
We can take jumps from 0->4->5.
So the minimum jumps require are 2.

Input: N = 23 
Output: 4 
Explanation: 
We can take jumps from 0->1->3->7->23. 
So the minimum jumps required are 4. 
*/

#include<iostream>
using namespace std;

int countSetBitsOptimized(int n)
{
    int count = 0;
    while(n != 0)
    {
        // remove last set bit
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int ans = countSetBitsOptimized(n);
    cout << "Number of set bits in " << n << " are: " << ans <<endl;
    return 0;
}

// Time Complexity: O(log N)
// Auxiliary Space: O(1)