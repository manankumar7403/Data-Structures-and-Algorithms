// 🔴🔴🔴🔴 LEETCODE 20 -> Valid Parentheses 🔴🔴🔴🔴
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input
string is valid.
An input string is valid if:

1) Open brackets must be closed by the same type of brackets.
2) Open brackets must be closed in the correct order.
3) Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
*/
// _______________________________________________________________________________________________

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // opening bracket
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // Closing bracket
            if (!st.empty())
            {
                char topCh = st.top();
                if ((ch == ')' && topCh == '(') || (ch == '}' && topCh == '{') || (ch == ']' && topCh == '['))
                {
                    // Matching brackets
                    st.pop();
                }
                else
                {
                    return false; // brackets not matching
                }
            }
            else
            {
                return false; // opening bracket not present but closing bracket present
            }
        }
    }
    if (st.empty())
    {
        return true; // stack is empty so matching pairs found and popped.
    }
    return false;
}

int main()
{
    string input;

    cout << "Enter a string with brackets: ";
    getline(cin, input);

    if (isValid(input))
    {
        cout << "The brackets are valid." << endl;
    }
    else
    {
        cout << "The brackets are not valid." << endl;
    }

    return 0;
}

// TC -> O(n)
// SC -> O(n)