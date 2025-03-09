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
using namespace std;

vector<vector<string> >groupAnagrams(vector<string>& strs)
{
    map<string, vector<string> >mp;
    for(auto str: strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string> >ans;
    for(auto j = mp.begin(); j != mp.end(); j++)
    {
        ans.push_back(j -> second);
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
    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }
    
    vector<vector<string> >result = groupAnagrams(strs);

    cout << "Grouped Anagrams: " << endl;
    for(auto i: result)
    {
        cout << "[ ";
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}

// TC -> O(m * klogk) => where m is the string length and nlogn is TC of in-built sort function.
// SC -> O(m * k) => where m is the parent string length and k is the length of the longest string.
