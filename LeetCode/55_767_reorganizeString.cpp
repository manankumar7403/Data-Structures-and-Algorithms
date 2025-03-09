// 🔴🔴🔴🔴 LEETCODE 767 -> Reorganize String 🔴🔴🔴🔴
// Refer 10_Week5_Assignments
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

// Example 1:
// Input: s = "aab"
// Output: "aba"

// Example 2:
// Input: s = "aaab"
// Output: ""

// Constraints:
// 1 <= s.length <= 500
// s consists of lowercase English letters.

// _______________________________________________________________________________

#include <iostream>
using namespace std;

string reorganizeString(string s)
{
    int hash[26] = {0}; // as only lowercase characters are present (given)

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    // find the most frequent character
    char max_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }

    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = max_freq_char;
        max_freq--;
        index = index + 2;
    }

    if (max_freq != 0)
    {
        return "";
    }

    hash[max_freq_char - 'a'] = 0;

    // let's place the rest of the characters
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            // if index is out of bound then we put index equals to 1 or else index = index and we keep on placing the elements at alternate positions

            s[index] = i + 'a';
            hash[i]--;
            index = index + 2;
        }
    }
    return s;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    cout << reorganizeString(s);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)