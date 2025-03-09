// 🔴🔴🔴🔴 LEETCODE 345 -> Reverse Vowels Of A String 🔴🔴🔴🔴

// Refer 10_Week5_Assignments

// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases,
// more than once.

// Example 1:
// Input: s = "hello"
// Output: "holle"

// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:
// 1 <= s.length <= 3 * 10^5
// s consist of printable ASCII characters.

// __________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (isVowel(s[start]) && isVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (isVowel(s[start]) == 0)
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
    cout << "Resultant string is: " << reverseVowels(s);
    cout << endl;
    return 0;
}

// T.C. -> O(n)
// S.C. -> O(1)