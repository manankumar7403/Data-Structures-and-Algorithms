// Leetcode 767 question already solved in week 10 assignments and heaps class 4
/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

string reorganizeString(string s)
{
    unordered_map<char, int> freqMap;

    for (char c : s)
    {
        freqMap[c]++;
    }

    // for(auto it: freqMap)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // find the most frequent character
    char max_freq_char;
    int max_freq = INT_MIN;
    for (auto [c, freq] : freqMap)
    {
        if (freq > max_freq)
        {
            max_freq = freq;
            max_freq_char = c;
        }
    }

    // Check if it's possible to reorganize the string
    if (max_freq > (s.length() + 1) / 2)
    {
        return "";
    }

    // Reorganize the string -> first handling the max char by putting it on alternate locations
    string result(s.length(), ' ');
    int index = 0;
    while (max_freq > 0)
    {
        result[index] = max_freq_char;
        max_freq--;
        index = index + 2;
    }

    // let's place the rest of the characters
    for (auto [c, freq] : freqMap)
    {
        if (c != max_freq_char)
        {
            while (freq > 0)
            {
                index = (index >= result.length()) ? 1 : index;
                result[index] = c;
                freq--;
                index = index + 2;
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "Reorganized string: " << reorganizeString(s) << endl;
    return 0;
}