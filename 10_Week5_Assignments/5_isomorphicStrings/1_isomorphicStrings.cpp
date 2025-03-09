// 🔴🔴🔴🔴 LEETCODE 205 -> Isomorphic Strings 🔴🔴🔴🔴
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order
// of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

// Constraints:
// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

// _______________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0};
    bool isTCharsMapped[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && isTCharsMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isTCharsMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cout << "Enter the string s: " << endl;
    getline(cin, s);
    cout << "Enter the string t: " << endl;
    getline(cin, t);
    cout << isIsomorphic(s, t);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)