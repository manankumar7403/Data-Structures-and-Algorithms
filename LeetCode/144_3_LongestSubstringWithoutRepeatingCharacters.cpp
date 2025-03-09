// 🔴🔴LEETCODE 3 -> Longest Substring Without Repeating Characters🔴🔴
//⭐⭐ Sliding Window Question ⭐⭐

/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/
// ________________________________________________________________________________________________________

#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int count[256] = {0};
    int left = 0;  // starting index of the window
    int right = 0; // ending index of the window
    int ans = 0;   // length of longest substring of no repeating character
    while (right < s.length())
    {
        count[s[right]]++;
        while (count[s[right]] > 1)
        {
            count[s[left]]--; // shrink the window
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "Length of longest substr without rep chars: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)