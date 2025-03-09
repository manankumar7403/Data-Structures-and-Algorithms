// GFG
/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i

Example 2:
Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and
returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <= 10^5
*/

#include<iostream>
#include<algorithm>
using namespace std;

string reverseWords(string S)
{
    string ans = "";
    string temp = "";
    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] == '.')
        {
            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }
        else
        {
            temp.push_back(S[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
}

int main()
{
    string S;
    cout << "Enter the string:" << endl;
    cin >> S;
    cout << "Reversed string: " << reverseWords(S) << endl;
    return 0;
}

// Time Complexity: O(|S|)
// Auxiliary Space: O(|S|)