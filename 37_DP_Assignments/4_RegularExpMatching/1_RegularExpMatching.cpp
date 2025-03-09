// 🔴🔴LEETCODE 10 -> Regular Expression Matching🔴🔴
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/
// ________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴
#include<iostream>
using namespace std;

bool isMatchHelper(string s, int si, string p, int pi)
{
    // If we have reached the end of the pattern
    if (pi == p.size())
    {
        // Return true if we have also reached the end of the string
        return si == s.size();
    }

    // Check if the next character in the pattern is '*'
    bool next_is_star = (pi + 1 < p.size() && p[pi + 1] == '*');

    if (next_is_star)
    {
        // Try to match zero or more of the preceding element
        // Case 1: Treat '*' as zero occurrences of the preceding element
        if (isMatchHelper(s, si, p, pi + 2))
        {
            return true;
        }

        // Case 2: Match one or more occurrences of the preceding element
        while (si < s.size() && (p[pi] == s[si] || p[pi] == '.'))
        {
            si++;
            if (isMatchHelper(s, si, p, pi + 2))
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        // Single character matching
        if (si < s.size() && (p[pi] == s[si] || p[pi] == '.'))
        {
            return isMatchHelper(s, si + 1, p, pi + 1);
        }
        // Character doesn't match
        return false;
    }
}

bool isMatch(string s, string p)
{
    return isMatchHelper(s, 0, p, 0);
}

int main()
{
    string s, p;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else
    {
        cout << "Not matched!";
    }
    return 0;
}
*/
// ___________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴
#include<iostream>
#include<vector>
using namespace std;

bool solveUsingMem(string &s, int si, string &p, int pi, vector<vector<int>> &dp)
{
    // Base case
    // If we have reached the end of the pattern and string
    if (pi == p.size() && si == s.size())
    {
        return true;
    }

    // Step2: Check if the answer is already present inside the dp array or not
    if (dp[si][pi] != -1)
    {
        return dp[si][pi];
    }

    bool match = false;
    // Check if the next character in the pattern is '*'
    bool next_is_star = (pi + 1 < p.size() && p[pi + 1] == '*');

    if (next_is_star)
    {
        // Try to match zero or more of the preceding element
        // Case 1: Treat '*' as zero occurrences of the preceding element
        match = solveUsingMem(s, si, p, pi + 2, dp);

        // Case 2: Match one or more occurrences of the preceding element
        while (!match && si < s.size() && (p[pi] == s[si] || p[pi] == '.'))
        {
            si++;
            match = solveUsingMem(s, si, p, pi + 2, dp);
        }
    }
    else
    {
        // Single character matching
        if (si < s.size() && (p[pi] == s[si] || p[pi] == '.'))
        {
            match = solveUsingMem(s, si + 1, p, pi + 1, dp);
        }
    }
    // Step3: Store the answer in dp array and return
    dp[si][pi] = match;
    return dp[si][pi];
}

bool isMatch(string s, string p)
{
    // Step1: Create a dp array: 2d dp as si and pi are changing
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return solveUsingMem(s, 0, p, 0, dp);
}

int main()
{
    string s, p;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else
    {
        cout << "Not matched!";
    }
    return 0;
}
*/
// ___________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION(Bottom-Up)🔴🔴
#include<iostream>
using namespace std;

bool solveUsingTab(string &s, string &p)
{
    int m = s.length();
    int n = p.length();

    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));

    // Step2: Check the base case
    dp[m][n] = true;

    // Step3: Main iteration logic
    for (int i = m; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // Check if the next character in the pattern is '*'
            bool next_is_star = (j + 1 < n && p[j + 1] == '*');

            if (next_is_star)
            {
                // Try to match zero or more of the preceding element
                // Case 1: Treat '*' as zero occurrences of the preceding element
                dp[i][j] = dp[i][j + 2];

                // Case 2: Match one or more occurrences of the preceding element
                if (i < m && (p[j] == s[i] || p[j] == '.'))
                {
                    dp[i][j] = dp[i][j] || dp[i + 1][j];
                }
            }
            else
            {
                // Single character matching
                if (i < m && (p[j] == s[i] || p[j] == '.'))
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }
    }
    return dp[0][0];
}

bool isMatch(string s, string p)
{
    return solveUsingTab(s, p);
}

int main()
{
    string s, p;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else
    {
        cout << "Not matched!";
    }
    return 0;
}
*/
// _______________________________________________________________________________________________________________

// 🔴🔴SPACE OPTIMIZATION🔴🔴
#include<iostream>
#include<vector>
using namespace std;

bool solveUsingTab(string &s, string &p)
{
    int m = s.length();
    int n = p.length();

    vector<int> curr(n + 1);
    vector<int> next(n + 1);

    // Step2: Check the base case
    next[n] = true;

    // Step3: Main iteration logic
    for (int i = m; i >= 0; i--)
    {
        // ⭐⭐ Chances of mistake
        if (i == m)
            curr[n] = true; // have to set curr[n] for each i as above outside the for loop we only had 2 rows, here we are doing for every row
        else
            curr[n] = false;

        for (int j = n - 1; j >= 0; j--)
        {
            // Check if the next character in the pattern is '*'
            bool next_is_star = (j + 1 < n && p[j + 1] == '*');

            if (next_is_star)
            {
                // Try to match zero or more of the preceding element
                // Case 1: Treat '*' as zero occurrences of the preceding element
                curr[j] = curr[j + 2];

                // Case 2: Match one or more occurrences of the preceding element
                if (i < m && (p[j] == s[i] || p[j] == '.'))
                {
                    curr[j] = curr[j] || next[j];
                }
            }
            else
            {
                // Single character matching
                if (i < m && (p[j] == s[i] || p[j] == '.'))
                {
                    curr[j] = next[j + 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
        }
        // Shifting
        next = curr;
    }
    return next[0];
}

bool isMatch(string s, string p)
{
    return solveUsingTab(s, p);
}

int main()
{
    string s, p;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the pattern: " << endl;
    cin >> p;
    if(isMatch(s, p))
    {
        cout << "Matched!";
    }
    else
    {
        cout << "Not matched!";
    }
    return 0;
}