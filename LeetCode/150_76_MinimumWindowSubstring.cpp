// 🔴🔴LEETCODE 76 -> Minimum Window Substring🔴🔴
// Same as 4_SmallestWindowInAStringContainingAllCharsOfAnotherString.cpp
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character 
in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
// _________________________________________________________________________________________________________

#include<iostream>
using namespace std;

string minWindow(string s, string p)
{
    const int no_of_chars = 256;
    int len1 = s.length();
    int len2 = p.length();
    int start = 0;
    int ansIndex = -1;
    int ansLen = INT_MAX;

    if (len1 < len2)
        return "";

    int strMap[no_of_chars] = {0};
    int patMap[no_of_chars] = {0};

    // to keep track of all characters of P string
    for (int i = 0; i < p.length(); i++)
    {
        char ch = p[i];
        patMap[ch]++;
    }

    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        strMap[ch]++;

        // valid character(count) or not -> whether it exists in the pattern or not
        if (strMap[ch] <= patMap[ch])
        {
            count++;
        }
        if (count == len2)
        {
            // window is ready
            // minimize the window -> freq decrement, ans update, increment start
            while (strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0) // extra char in s str or char absent in pattern
            {
                if (strMap[s[start]] > patMap[s[start]])
                    strMap[s[start]]--;
                start++;
            }
            // ans update
            int lengthOfWindow = i - start + 1;
            if (lengthOfWindow < ansLen)
            {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }
    if (ansIndex == -1)
        return "";
    else
        return s.substr(ansIndex, ansLen);
}

int main()
{
    string s, p;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "Enter the pattern:" << endl;
    cin >> p;
    string ans = minWindow(s, p);
    cout << "Smallest window in the string: " << ans << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)
