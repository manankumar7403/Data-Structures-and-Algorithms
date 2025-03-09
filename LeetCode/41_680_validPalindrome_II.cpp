// 🔴🔴🔴🔴 LEETCODE 680 - Valid Palindrome II 🔴🔴🔴🔴

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

// Constraints:
// 1 <= s.length <= 10^5
// s consists of lowercase English letters.

#include <iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            // either remove i or j which is not matching and then check if a palindrome or not
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else
        {
            // s[i] == s[j]
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string to check palindrome: " << endl;
    cin >> s;
    if (validPalindrome(s))
    {
        cout << "It is a valid palindrome according to the constraints." << endl;
    }
    else
    {
        cout << "Not a valid palindrome" << endl;
    }
    return 0;
}

// T.C. -> O(N^2)
// S.C. -> O(1)

