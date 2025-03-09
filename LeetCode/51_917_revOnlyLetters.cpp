// 🔴🔴🔴🔴 LEETCODE 917 - Reverse Only Letters 🔴🔴🔴🔴
// Refer 10_Week5_Assignments
// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

// Example 1:
// Input: s = "ab-cd"
// Output: "dc-ba"

// Example 2:
// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"

// Example 3:
// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// Constraints:
// 1 <= s.length <= 100
// s consists of characters with ASCII values in the range [33, 122].
// s does not contain '\"' or '\\'.

// _________________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

string reverseOnlyLetters(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (isalpha(s[start]) && isalpha(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (!isalpha(s[start]))
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return s;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s);
    cout << reverseOnlyLetters(s);
    cout << endl;
    return 0;
}

// TC -> O(N)
// SC -> O(1)
