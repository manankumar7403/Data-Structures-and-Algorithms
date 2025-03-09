// 🔴🔴 LEETCODE 1143 -> Longest Common Subsequence 🔴🔴
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence,
return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without
changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/
// _________________________________________________________________________________________________________________

/*
// 🔴🔴Solve Using Recursion🔴🔴

#include<iostream>
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

int longestCommonSubsequence(string text1, string text2)
{
    int i = 0;
    int j = 0;
    return solveUsingRecursion(text1, text2, i, j);
}

int main()
{
    string text1;
    string text2;
    cout << "Enter string1: " << endl;
    getline(cin, text1);
    cout << "Enter string2: " << endl;
    getline(cin, text2);
    int ans = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl;
    return 0;
}
// TC -> O(2^n)
*/

// _________________________________________________________________________________________________________________________
/*
// 🔴🔴MEMOIZATION (Top-Down)🔴🔴

#include<iostream>
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

int longestCommonSubsequence(string text1, string text2)
{
    int i = 0;
    int j = 0;

    // Step1: Create the dp array
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solveUsingMem(text1, text2, i, j, dp);
}

int main()
{
    string text1;
    string text2;
    cout << "Enter string1: " << endl;
    getline(cin, text1);
    cout << "Enter string2: " << endl;
    getline(cin, text2);
    int ans = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl;
    return 0;
}
*/
// TC -> O(nxm)
// SC -> O(nxm)
// ___________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION (Bottom-Up)🔴🔴

#include<iostream>
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

int longestCommonSubsequence(string text1, string text2)
{
    return solveUsingTab(text1, text2);
}

int main()
{
    string text1;
    string text2;
    cout << "Enter string1: " << endl;
    getline(cin, text1);
    cout << "Enter string2: " << endl;
    getline(cin, text2);
    int ans = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl;
    return 0;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/

// _________________________________________________________________________________________________________________________

// 🔴🔴Space Optimized Approach🔴🔴
// dp[i][j] is dependent on dp[i+1][j], dp[i][j+1], and dp[i+1][j+1]
// so curr row is dependent on next row
// we can create two arrays curr and next and solve it in SC: O(2m) instead of O(nxm)

#include<iostream>
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

int longestCommonSubsequence(string text1, string text2)
{
    return solveUsingSO(text1, text2);
}

int main()
{
    string text1;
    string text2;
    cout << "Enter string1: " << endl;
    getline(cin, text1);
    cout << "Enter string2: " << endl;
    getline(cin, text2);
    int ans = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl;
    return 0;
}

// TC -> O(nxm)
// SC -> O(n+m)