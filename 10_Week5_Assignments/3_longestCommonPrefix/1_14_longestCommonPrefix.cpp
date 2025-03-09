// 🔴🔴🔴🔴 LEETCODE 14 -> Longest Common Prefix 🔴🔴🔴🔴

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.

// __________________________________________________________________________________
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int i = 0;
    while (true)
    {
        char curr_ch = 0;
        for (auto str : strs)
        {
            if (i >= str.size())
            {
                // out of bound
                curr_ch = 0;
                break;
            }
            // just started
            if (curr_ch == 0)
            {
                curr_ch = str[i];
            }
            else if (str[i] != curr_ch)
            {
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0)
        {
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of strings: " << endl;
    cin >> n;
    vector<string> strs(n);
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    cout << "Longest common prefix is: " << longestCommonPrefix(strs);
    cout << endl;
    return 0;
}
*/
// TC -> O(m*n)
// SC -> O(1)

// _____________________________________________________________________________________

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    // loop on first string
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        bool match = true;

        // compare this char with all the remaining str chars at the same index
        for (int j = 1; j < strs.size(); j++)
        {
            // compare
            if (strs[j].size() < i || ch != strs[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of strings: " << endl;
    cin >> n;
    vector<string> strs(n);
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    cout << "Longest common prefix is: " << longestCommonPrefix(strs);
    cout << endl;
    return 0;
}
// TC -> O(n*m)
// SC -> O(1)