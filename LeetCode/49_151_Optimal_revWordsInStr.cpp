// 🔴🔴🔴🔴 LEETCODE 151 -> Reverse Words in a String 🔴🔴🔴🔴
// Space Optimal Solution

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at
// least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra
// spaces.

// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Constraints:
// 1 <= s.length <= 10^4
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

// _________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    // Reverse the entire string
    reverse(s.begin(), s.end());

    int start = 0;    // Start index of the current word
    int end = 0;      // End index of the current word
    int i = 0;        // Current index
    int n = s.size(); // Size of the string

    while (i < n)
    {
        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Find the end of the current word
        while (i < n && s[i] != ' ')
            s[end++] = s[i++];

        if (start < end)
        {
            // Reverse the current word
            reverse(s.begin() + start, s.begin() + end);

            // Add a space after the reversed word
            s[end++] = ' ';

            // Update the start index for the next word
            start = end;
        }
        i++;
    }

    // Remove extra space at the end if present
    if (end > 0)
        s.resize(end - 1);

    return s;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    cout << reverseWords(s);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)