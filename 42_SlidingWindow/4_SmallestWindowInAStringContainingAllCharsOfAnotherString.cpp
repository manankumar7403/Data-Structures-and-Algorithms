// 🔴🔴GFG🔴🔴
// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Smallest window in a string containing all the characters of another string
/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates)
of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length,
return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 

Example 1:
Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Example 2:
Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S
and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are
multiple such windows of same length, return the one with the least starting index. 
Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(n) n = len(p)

Constraints: 
1 ≤ |S|, |P| ≤ 10^5
*/
// ___________________________________________________________________________________________________________

#include<iostream>
using namespace std;

const int no_of_chars = 256;
string smallestWindow(string s, string p)
{
    int len1 = s.length();
    int len2 = p.length();
    int start = 0;
    int ansIndex = -1;
    int ansLen = INT_MAX;

    if (len1 < len2)
        return "-1";

    int strMap[no_of_chars] = {0};
    int patMap[no_of_chars] = {0};

    // to keep track of all characters of P string
    for (int i = 0; i < p.length(); i++)
    {
        char ch = p[i];
        patMap[ch]++;
    }

    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        strMap[ch]++;

        // valid character(count) or not -> whether it exists in the pattern or not
        if (strMap[ch] <= patMap[ch])
        {
            count++;
        }
        if (count == len2)
        {
            // window is ready
            // minimize the window -> freq decrement, ans update, increment start
            while (strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0) // extra char in s str or char absent in pattern
            {
                if (strMap[s[start]] > patMap[s[start]])
                    strMap[s[start]]--;
                start++;
            }
            // ans update
            int lengthOfWindow = i - start + 1;
            if (lengthOfWindow < ansLen)
            {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }
    if (ansIndex == -1)
        return "-1";
    else
        return s.substr(ansIndex, ansLen);
}

int main()
{
    string s, p;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "Enter the pattern:" << endl;
    cin >> p;
    string ans = smallestWindow(s, p);
    cout << "Smallest window in the string: " << ans << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)