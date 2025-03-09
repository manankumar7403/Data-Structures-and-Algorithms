// 🔴🔴🔴🔴 LEETCODE 1155 -> Number of Dice Rolls with Target Sum 🔴🔴🔴🔴
/*
You have n dice, and each die has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways)
to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large,
return it modulo 10^9 + 7.

Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 10^9 + 7.

Constraints:
1 <= n, k <= 30
1 <= target <= 1000
*/
// ____________________________________________________________________________________________________

#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    // Base conditions
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++) // each die could give a value between 1 and k
    {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }
    const int MOD = 1000000007;
    return ans % MOD;
}

int main()
{
    int n, k, target;
    cout << "Enter the total number of dice: " << endl;
    cin >> n;
    cout << "Enter the total number of faces: " << endl;
    cin >> k;
    cout << "Enter the target: " << endl;
    cin >> target;
    cout << "Total number of possible ways to roll the dice: " << numRollsToTarget(n, k, target);
    cout << endl;
    return 0;
}

// TC -> O(k^n) -> For every case we make k calls (as there are k faces) -> so possible solution lies between
// 1 to <= k at every call.
// SC -> O(n) -> Depth of recursive tree (stack) is n+1.
// This recursive solution gives TLE Error due to O(k^n) TC, will learn DP and revisit this problem.
