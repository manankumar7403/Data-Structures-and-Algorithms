// 🔴🔴LEETCODE 1047 -> Remove All Adjacent Duplicate Strings🔴🔴
/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent
and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is
unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (st.empty())
        {
            st.push(ch);
        }
        else if (!st.empty() && st.top() == ch)
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = removeDuplicates(s);
    cout << ans << endl;
    return 0;
}