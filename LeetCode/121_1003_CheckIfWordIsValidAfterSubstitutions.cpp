// 🔴🔴LEETCODE 1003 -> Check If Word Is Valid After Substitutions🔴🔴
/*
Given a string s, determine if it is valid.
A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the
following operation any number of times:
Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright.
Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

Example 1:
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.

Example 2:
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

Example 3:
Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

Constraints:
1 <= s.length <= 2 * 10^4
s consists of letters 'a', 'b', and 'c'
*/

// ___________________________________________________________________________________________________________________
// 🔴🔴METHOD 1 -> Brute Force🔴🔴
/*
#include<iostream>
using namespace std;

bool isValid(string s)
{
    if (s.size() == 0)
    {
        return true;
    }
    int found = s.find("abc");
    if (found != string::npos)
    {
        // found
        string left = s.substr(0, found);
        string right = s.substr(found + 3, s.size());
        return isValid(left + right);
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);
    if(isValid(s))
    {
        cout << "The given string is valid" << endl;
    }
    else
    {
        cout << "The given string is not valid" << endl;
    }
    return 0;
}
*/
// TC -> O(n^2) -> each call O(n) for find and substr ops and n/3 total calls
// SC -> O(n^2) -> new substrs created in every call, total n/3 calls

// ___________________________________________________________________________________________________________________
// 🔴🔴METHOD 2 -> Using Stack🔴🔴

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)
{
    if (s[0] != 'a')
        return false;

    stack<char> st;
    for (char ch : s)
    {
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push(ch);
            }
            else
            {
                return false;
            }
        }
        else
        {
            // ch == 'c'
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                return false;
        }
    }
    return st.empty() ? true : false;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);
    if(isValid(s))
    {
        cout << "The given string is valid" << endl;
    }
    else
    {
        cout << "The given string is not valid" << endl;
    }
    return 0;
}

// TC -> O(n)
// sC -> O(n)