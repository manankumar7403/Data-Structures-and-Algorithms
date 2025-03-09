// 🔴🔴🔴🔴 LEETCODE 647 - Palindromic Substrings 🔴🔴🔴🔴

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

int expandAroundIndex(string s, int i, int j)
{
    int count = 0;
    // increment count until it matches, else i-- and j++
    while(i >= 0 && j < s.length() && s[i]==s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s)
{
    int count = 0;
    int n = s.length();
    for(int i=0; i<n; i++)
    {
        // odd length of substr
        int oddAns = expandAroundIndex(s, i, i);
        count = count + oddAns;

        // even length of substr
        int evenAns = expandAroundIndex(s, i, i+1);
        count = count + evenAns;
    }
    return count;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "The number of palindromic strings in " << s << " are " << countSubstrings(s) << endl;
    return 0;
}