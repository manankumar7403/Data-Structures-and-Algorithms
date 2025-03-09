// 🔴🔴LEETCODE 44 -> Wildcard Matching🔴🔴
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Constraints:
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/
// ___________________________________________________________________________________________________________________
/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
using namespace std;

bool isMatchHelper(string s, int si, string p, int pi)
{
    // Base Case
    if (si == s.size() && pi == p.size())
    { // all char have matched -> we reached the end of the string
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        // we can only return true in this case if all the remaining chars of p are '*'
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }

    // single character matching
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    // if we encounter '*', we need to make cases.
    if (p[pi] == '*')
    {
        // treat '*' as empty or null
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        // let '*' consume one character
        bool caseB = isMatchHelper(s, si + 1, p, pi);
        return caseA || caseB; // either case is true meaning the string is matched
    }

    // character doesn't match
    return false;
}

bool isMatch(string s, string p)
{
    int si = 0; // pointer index for s string.
    int pi = 0; // pointer index for pattern string.
    return isMatchHelper(s, si, p, pi);
}

int main()
{
    string s, p;
    cout << "Enter string: " << endl;
    cin >> s;
    cout << "Enter pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else cout << "Not matched!";
    return 0;
}
// TC -> O(2^n)  // For every case we have 2 branches
// SC -> O(n)
*/
// __________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION (Top-Down)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

bool solveUsingMem(string &s, int si, string &p, int pi, vector<vector<int>> &dp)
{
    // Base Case
    if (si == s.size() && pi == p.size())
    { // all char have matched -> we reached the end of the string
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        // we can only return true in this case if all the remaining chars of p are '*'
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[si][pi] != -1)
    {
        return dp[si][pi];
    }

    // single character matching
    if (s[si] == p[pi] || p[pi] == '?')
    {
        dp[si][pi] = solveUsingMem(s, si + 1, p, pi + 1, dp);
        return dp[si][pi];
    }

    // if we encounter '*', we need to make cases.
    if (p[pi] == '*')
    {
        // treat '*' as empty or null
        bool caseA = solveUsingMem(s, si, p, pi + 1, dp);

        // let '*' consume one character
        bool caseB = solveUsingMem(s, si + 1, p, pi, dp);

        // Step3: Store the answer in dp array and return
        dp[si][pi] = caseA || caseB;
        return dp[si][pi]; // either case is true meaning the string is matched
    }

    // character doesn't match
    return false;
}

bool isMatch(string s, string p)
{
    int si = 0; // pointer index for s string.
    int pi = 0; // pointer index for pattern string.

    // Step1: Create a dp array: 2d array as si and pi are changing
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return solveUsingMem(s, si, p, pi, dp);
}

int main()
{
    string s, p;
    cout << "Enter string: " << endl;
    cin >> s;
    cout << "Enter pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else cout << "Not matched!";
    return 0;
}

// TC -> O(nxm)
// SC -> O(nxm)
*/
// ___________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION (Bottom-Up)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

bool solveUsingTab(string &s, string &p)
{
    // Step1: Create a dp array: 2d array as si and pi are changing
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));

    // Step2: Check the base case
    dp[s.size()][p.size()] = true;
    for (int j = p.size() - 1; j >= 0; j--)
    {
        // The loop should continue marking positions as true as long as * is encountered.
        // If a character other than * is found, it should stop marking further positions as true.
        if (p[j] == '*')
        {
            dp[s.size()][j] = dp[s.size()][j + 1];
        }
        else
            break;
    }

    // Step3: Main iteration logic
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = p.size() - 1; j >= 0; j--)
        {
            // single character matching
            if (s[i] == p[j] || p[j] == '?')
            {
                dp[i][j] = dp[i + 1][j + 1];
            }

            // if we encounter '*', we need to make cases.
            else if (p[j] == '*')
            {
                // treat '*' as empty or null
                bool caseA = dp[i][j + 1];

                // let '*' consume one character
                bool caseB = dp[i + 1][j];

                // Step3: Store the answer in dp array and return
                dp[i][j] = caseA || caseB; // either case is true meaning the string is matched
            }
            else
            {
                // character doesn't match
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}

bool isMatch(string s, string p)
{
    // int si = 0; // pointer index for s string.
    // int pi = 0; // pointer index for pattern string.
    return solveUsingTab(s, p);
}

int main()
{
    string s, p;
    cout << "Enter string: " << endl;
    cin >> s;
    cout << "Enter pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else cout << "Not matched!";
    return 0;
}
// TC -> O(nxm)
// SC -> O(nxm)
*/
// ___________________________________________________________________________________________________________

// 🔴🔴Space Optimization🔴🔴
#include<iostream>
#include<vector>
using namespace std;

bool solveUsingSO(string &s, string &p)
{
    vector<int> curr(p.length() + 1);
    vector<int> next(p.length() + 1);

    // Step2: Check the base case
    next[p.size()] = true;
    for (int j = p.size() - 1; j >= 0; j--)
    {
        // The loop should continue marking positions as true as long as * is encountered.
        // If a character other than * is found, it should stop marking further positions as true.
        if (p[j] == '*')
        {
            next[j] = next[j + 1];
        }
        else
            break;
    }

    // Step3: Main iteration logic
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = p.size() - 1; j >= 0; j--)
        {
            // single character matching
            if (s[i] == p[j] || p[j] == '?')
            {
                curr[j] = next[j + 1];
            }

            // if we encounter '*', we need to make cases.
            else if (p[j] == '*')
            {
                // treat '*' as empty or null
                bool caseA = curr[j + 1];

                // let '*' consume one character
                bool caseB = next[j];

                // Step3: Store the answer in dp array and return
                curr[j] = caseA || caseB; // either case is true meaning the string is matched
            }
            else
            {
                // character doesn't match
                curr[j] = false;
            }
        }
        // Shifting
        next = curr;
    }
    return next[0];
}

bool isMatch(string s, string p)
{
    // int si = 0; // pointer index for s string.
    // int pi = 0; // pointer index for pattern string.
    return solveUsingSO(s, p);
}

int main()
{
    string s, p;
    cout << "Enter string: " << endl;
    cin >> s;
    cout << "Enter pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else cout << "Not matched!";
    return 0;
}

// TC -> O(nxm)
// SC -> O(n+m)