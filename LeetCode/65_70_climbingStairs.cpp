// 🔴🔴🔴🔴 LEETCODE 70 ->  Climbing Stairs 🔴🔴🔴🔴

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:
// 1 <= n <= 45

// ____________________________________________________________________________________

#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    int prev=1, curr=1;
    for(int i=2; i<=n; i++)
    {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << climbStairs(n);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)

// _______________________________________________________________________

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 0 || n == 1)
//         {
//             return 1;
//         }
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// };
// TLE error as TC is O(2^n)