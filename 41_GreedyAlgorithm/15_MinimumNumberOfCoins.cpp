// GFG
/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target
value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the
value of coins required. 

Example 1:
Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed to make 43. 

Example 2:
Input: N = 1000
Output: 500 500
Explaination: minimum possible notes is 2 notes of 500.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minPartition() which takes the value
N as input parameter and returns a list of integers in decreasing order.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^6
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> minPartition(int N)
{
    // solved similar question using dp on leetcode -> coin change
    // now doing this one using greedy
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (coins[i] <= N)
        {
            ans.push_back(coins[i]);
            N = N - coins[i];
        }
    }
    return ans;
}

int main()
{
    int N;
    cout << "Enter the target value:" << endl;
    cin >> N;
    vector<int> ans = minPartition(N);
    for(auto i: ans)
    {
        cout << i << " ";
    }
    return 0;
}
// TC -> O(n)
// SC -> O(n)