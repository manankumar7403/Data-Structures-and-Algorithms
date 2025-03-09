// 🔴🔴LEETCODE 516 -> Longest Palindromic Subsequence🔴🔴
/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the
order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.
*/
// ______________________________________________________________________________________________________________
// ⭐⭐Logic and code exactly the same as Longest Common Subsequence just that the second string would be reverse of first⭐⭐

/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
#include<algorithm>
using namespace std;
int solveUsingRecursion(string a, string b, int i, int j)
{
    // Base conditions
    if (i == a.length())
        return 0;
    if (j == b.length())
        return 0;

    int ans = 0;
    // Char matches
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    }
    // Char not matched
    else
    {
        ans = 0 + max(solveUsingRecursion(a, b, i, j + 1), solveUsingRecursion(a, b, i + 1, j));
    }
    return ans;
}

int longestPalindromeSubseq(string s)
{
    string text1 = s;
    reverse(s.begin(), s.end());
    string text2 = s;
    int i = 0;
    int j = 0;
    return solveUsingRecursion(text1, text2, i, j);
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int ans = longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence is: " << ans << endl;
}
*/
// ______________________________________________________________________________________________________________

// 🔴🔴MEMOIZATION(Top-Down)🔴🔴
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
// a and b passed by reference as string copy is expensive, takes time and could lead to TLE (TLE in 1 test case)
{
    // Base conditions
    if (i == a.length())
        return 0;
    if (j == b.length())
        return 0;

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // Char matches
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    // Char not matched
    else
    {
        ans = 0 + max(solveUsingMem(a, b, i, j + 1, dp), solveUsingMem(a, b, i + 1, j, dp));
    }
    // Step3: Store the answer in dp array
    dp[i][j] = ans;
    return dp[i][j];
}

int longestPalindromeSubseq(string s)
{
    string text1 = s;
    reverse(s.begin(), s.end());
    string text2 = s;
    int i = 0;
    int j = 0;
    // Step1: Create the dp array
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solveUsingMem(text1, text2, i, j, dp);
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int ans = longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence is: " << ans << endl;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/

// ______________________________________________________________________________________________________________
/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solveUsingTab(string &a, string &b)
// a and b passed by reference as string copy is expensive, takes time and could lead to TLE (TLE in 1 test case)
{
    // Step1: Create the dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    // Step2: Check the Base conditions -> already dp array init with 0
    // if(i==a.length()) return 0;
    // if(j==b.length()) return 0;

    // Step3: Main iteration logic
    // i and j started from 0 to length of a and b respectively so here it would be opposite
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // Char matches
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            // Char not matched
            else
            {
                ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
            }
            // Store the answer in dp array
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestPalindromeSubseq(string s)
{
    string text1 = s;
    reverse(s.begin(), s.end());
    string text2 = s;
    return solveUsingTab(text1, text2);
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int ans = longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence is: " << ans << endl;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/

// ______________________________________________________________________________________________________________

// 🔴🔴Space Optimized Approach🔴🔴
// dp[i][j] is dependent on dp[i+1][j], dp[i][j+1], and dp[i+1][j+1]
// so curr row is dependent on next row
// we can create two arrays curr and next and solve it in SC: O(2m) instead of O(nxm)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solveUsingSO(string &a, string &b)
// a and b passed by reference as string copy is expensive, takes time and could lead to TLE (TLE in 1 test case)
{
    vector<int> curr(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    // Step3: Main iteration logic
    // i and j started from 0 to length of a and b respectively so here it would be opposite
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            // Char matches
            if (a[i] == b[j])
            {
                ans = 1 + next[j + 1];
            }
            // Char not matched
            else
            {
                ans = 0 + max(curr[j + 1], next[j]);
            }
            // Store the answer in dp array
            curr[j] = ans;
        }
        // Shifting
        next = curr;
    }
    return curr[0];
}

int longestPalindromeSubseq(string s)
{
    string text1 = s;
    reverse(s.begin(), s.end());
    string text2 = s;
    return solveUsingSO(text1, text2);
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int ans = longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence is: " << ans << endl;
}

// TC -> O(nxm)
// SC -> O(n+m)