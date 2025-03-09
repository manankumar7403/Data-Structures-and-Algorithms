// 🔴🔴🔴🔴 LEETCODE 49 -> Group Anagrams 🔴🔴🔴🔴
// Refer 10_Week5_Assignments
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

// _________________________________________________________________________________________________

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
using namespace std;

std::array<int, 256> getHash(string s)
{
    std::array<int, 256> hash = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<std::array<int, 256>, vector<string>> mp;
    for (auto str : strs)
    {
        mp[getHash(str)].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto j = mp.begin(); j != mp.end(); j++)
    {
        ans.push_back(j->second);
    }
    return ans;
}

int main()
{
    cout << "Enter the number of strings: " << endl;
    int n;
    cin >> n;
    vector<string> strs;
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "Grouped Anagrams: " << endl;
    for (auto i : result)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}

// TC -> O(m * k)
// SC -> O(m * k)
// where m is the length of the string and k is the length of the longest string.
