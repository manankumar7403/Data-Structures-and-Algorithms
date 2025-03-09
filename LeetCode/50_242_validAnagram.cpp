// 🔴🔴🔴🔴 LEETCODE 242 - Valid Anagram 🔴🔴🔴🔴
// Refer 10_Week5_Assignments

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.

// _________________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    int freqTable[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freqTable[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        freqTable[t[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freqTable[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cout << "Enter string s: " << endl;
    cin >> s;
    cout << "Enter string t: " << endl;
    cin >> t;
    cout << isAnagram(s, t) << endl;
    return 0;
}

// TC -> O(N+M)
// SC -> O(1)