// 🔴🔴LEETCODE 394 -> Decode String🔴🔴
/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly
k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed,
etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those
repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 10^5.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (ch == ']')
        {
            string stringToRepeat = "";
            while (!st.empty() && !isdigit(st.top()[0])) // checking first digit of stack's top as isdigit takes only 1 digit
            {
                string top = st.top();
                stringToRepeat += top == "[" ? "" : top;
                st.pop();
            }
            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                numericTimes = numericTimes + st.top();
                st.pop();
            }
            reverse(numericTimes.begin(), numericTimes.end()); // for 2 digit numbers
            int n = stoi(numericTimes);

            // final decoding
            string currentDecode = "";
            while (n--)
            {
                currentDecode = currentDecode + stringToRepeat;
            }
            st.push(currentDecode);
        }
        else
        {
            string temp(1, ch); // creating a string of 1 length
            st.push(temp);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end()); // resultant string is opp, reverse it to get the correct answer
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);
    cout << "The decoded string is: " << decodeString(s) << endl;
    return 0;
}