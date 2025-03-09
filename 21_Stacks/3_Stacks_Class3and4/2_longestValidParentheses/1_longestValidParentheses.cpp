// 🔴🔴🔴🔴 LEETCODE 32 -> Longest Valid Parentheses 🔴🔴🔴🔴
/*
Given a string containing just the characters '(' and ')', return the length of the longest valid
(well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
*/
// ______________________________________________________________________________________________

#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')          // opening bracket
        {
            st.push(i);
        }
        else                 // closing bracket
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int result = longestValidParentheses(s);
    cout << "Max Length is: " << result << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(n)