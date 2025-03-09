// 🔴🔴LEETCODE 3154 -> Find Number Of Ways To Reach The Kth Stair🔴🔴
/*
You are given a non-negative integer k. There exists a staircase with an infinite number of stairs, with the lowest
stair numbered 0.
Alice has an integer jump, with an initial value of 0. She starts on stair 1 and wants to reach stair k
using any number of operations. If she is on stair i, in one operation she can:
Go down to stair i - 1. This operation cannot be used consecutively or on stair 0.
Go up to stair i + 2jump. And then, jump becomes jump + 1.
Return the total number of ways Alice can reach stair k.
Note that it is possible that Alice reaches the stair k, and performs some operations to reach the stair k again.

Example 1:
Input: k = 0
Output: 2
Explanation:
The 2 possible ways of reaching stair 0 are:
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.

Example 2:
Input: k = 1
Output: 4
Explanation:
The 4 possible ways of reaching stair 1 are:
Alice starts at stair 1. Alice is at stair 1.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Alice starts at stair 1.
Using an operation of the second type, she goes up 20 stairs to reach stair 2.
Using an operation of the first type, she goes down 1 stair to reach stair 1.
Alice starts at stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 20 stairs to reach stair 1.
Using an operation of the first type, she goes down 1 stair to reach stair 0.
Using an operation of the second type, she goes up 21 stairs to reach stair 2.
Using an operation of the first type, she goes down 1 stair to reach stair 1.

Constraints:
0 <= k <= 10^9
*/
// _________________________________________________________________________________________________________________________________

// ⭐⭐Using Bit Manipulation⭐⭐

#include<iostream>
using namespace std;

int comb(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    long res = 1;
    for (int i = 0; i < k; i++)
    {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

int waysToReachStair(int k)
{
    int jump = 0;
    for (int j = 0; j < 31; j++)
    {
        jump = jump + comb(j + 1, (1 << j) - k);
    }
    return jump;
}

int main()
{
    int k;
    cout << "Enter the value of k:" << endl;
    cin >> k;
    int ans = waysToReachStair(k);
    cout << "Number of ways to reach the kth stair: " << ans << endl;
    return 0;
}

// TC -> O(1)
// SC -> O(1)

// ____________________________________________________________________________________________
/*
// ⭐⭐No Returning DP⭐⭐
// ⭐⭐Refer: https://www.youtube.com/watch?v=1e2un-t1Vzg⭐⭐

#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp; // i, wasLastDownJump, jump
int solveUsingMem(int i, int &k, int wasLastDownJump, int jump)
{
    // Base condition
    if (i > k + 1)
        return 0; // because only 1 go down operation to reach k will still result in i == k+1, so won't reach k at all

    if (dp.count(i) && dp[i].count(wasLastDownJump) && dp[i][wasLastDownJump].count(jump))
    {
        return dp[i][wasLastDownJump][jump]; // no need to check as answer is already present
    }

    int ans = (i == k) ? 1 : 0;                                 // if i is at k, we can still look for more ways like go up/down then go down/up etc, else 0
    ans = ans + solveUsingMem(i + (1 << jump), k, 0, jump + 1); // go up
    if (i != 0 && !wasLastDownJump)
    {
        ans = ans + solveUsingMem(i - 1, k, 1, jump); // go down
    }

    // Store the answer in dp and return
    dp[i][wasLastDownJump][jump] = ans;
    return ans;
}

int waysToReachStair(int k)
{
    int ans = solveUsingMem(1, k, 0, 0); // ith Position(Alice initial), k, lastDownJump true or false, jump variable for 2^jump
    return ans;
}

int main()
{
    int k;
    cout << "Enter the value of k:" << endl;
    cin >> k;
    int ans = waysToReachStair(k);
    cout << "Number of ways to reach the kth stair: " << ans << endl;
    return 0;
}
// TC -> O(klogk)
// SC -> O(klogk)
*/