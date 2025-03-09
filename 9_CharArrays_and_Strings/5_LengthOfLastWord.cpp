// 🔴🔴LEETCODE 58 -> Length of Last Word🔴🔴
/*
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:
1 <= s.length <= 10^4
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

#include<iostream>
using namespace std;

int lengthOfLastWord(string s)
{
    int length = 0;
    bool flag = false;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            length++;
            flag = true;
        }
        else if (flag == true)
        {
            break;
        }
    }
    return length;
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    cin >> s;
    cout << "Length of the last word is: " << lengthOfLastWord(s); 
    return 0;
}

// TC -> O(n)
// SC -> O(1)