// 🔴🔴LEETCODE 3226 -> Number of Bit Changes To Make 2 Integers Equal (Contest 407)🔴🔴
/*
You are given two positive integers n and k.
You can choose any bit in the binary representation of n that is equal to 1 and change it to 0.
Return the number of changes needed to make n equal to k. If it is impossible, return -1.

Example 1:
Input: n = 13, k = 4
Output: 2
Explanation:
Initially, the binary representations of n and k are n = (1101)2 and k = (0100)2.
We can change the first and fourth bits of n. The resulting integer is n = (0100)2 = k.

Example 2:
Input: n = 21, k = 21
Output: 0
Explanation:
n and k are already equal, so no changes are needed.

Example 3:
Input: n = 14, k = 13
Output: -1
Explanation:
It is not possible to make n equal to k.

Constraints:
1 <= n, k <= 10^6
*/

// _____________________________________________________________________________________________________________________

#include<iostream>
using namespace std;

int minChanges(int n, int k)
{
    if ((n & k) == k) // checks whether k can be formed by changing some 1 bits of n to 0.
    {
    // bitwise XOR (^) b/w n and k will result in a number where each bit is 1 if the corresponding bits of n and k are diff.
    // Counting the no. of 1 bits in the res of n^k, we get the no. of bits to be changed from 1 to 0 in n to make it equal to k.
        return __builtin_popcount(n ^ k); //__builtin_popcount counts the no. of 1 bits in the binary representation of a no.
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Enter k:" << endl;
    cin >> k;
    cout << "Number of changes: " << minChanges(n, k);
    return 0;
}

// TC -> O(1)
// SC -> O(1)