// 🔴🔴🔴🔴 LEETCODE 44 -> WildCard Matching 🔴🔴🔴🔴
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'
// where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Constraints:
// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

// ⭐⭐⭐⭐ THIS SOLUTION GIVES TLE AND MLE ERROR. CHECK OPTIMIZED SOLUTION USING DP. ⭐⭐⭐⭐
//  _______________________________________________________________________________________

#include <iostream>
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
    cout << "Enter string s: " << endl;
    cin >> s;
    cout << "Enter pattern p: " << endl;
    cin >> p;
    cout << isMatch(s, p) << endl;
    return 0;
}
// TC -> O(2^n)  // For every case we have 2 branches
// SC -> O(n)
