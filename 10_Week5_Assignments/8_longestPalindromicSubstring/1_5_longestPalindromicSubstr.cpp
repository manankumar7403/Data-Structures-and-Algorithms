// 🔴🔴🔴🔴 LEETCODE 5 => Longest Palindromic Substring 🔴🔴🔴🔴

// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// ______________________________________________________________________________

// ⭐⭐Expand around center (Space Optimized)⭐⭐
#include <iostream>
#include <string>
using namespace std;

string ans = "";
void findPalindrome(string &s, int left, int right)
{
    while (left >= 0 && right < s.size())
    {
        if (s[left] != s[right])
        {
            break;
        }
        left--;
        right++;
    }
    if (ans.size() < right - left)
    {
        ans = s.substr(left + 1, right - left - 1);
    }
}

string longestPalindrome(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        findPalindrome(s, i, i + 1); // even palindrome
        findPalindrome(s, i, i);     // odd palindrome
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    string result = longestPalindrome(s);
    cout << result;
    cout << endl;
    return 0;
}

// TC -> O(n^2)
// SC -> O(1)
// SC is O(1) as for 'ans' string which is used for storing output, its size is not dependent on the input size,
// it's only updated when a longer palindrome is found. 