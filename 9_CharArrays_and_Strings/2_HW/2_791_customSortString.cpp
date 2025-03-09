// // 🔴🔴🔴🔴 LEETCODE 791 -> Custom Sort String 🔴🔴🔴🔴

// You are given two strings order and s. All the characters of order are unique and were sorted in some
// custom order previously.
// Permute the characters of s so that they match the order that order was sorted. More specifically,
// if a character x occurs before a character y in order, then x should occur before y in the permuted
// string.
// Return any permutation of s that satisfies this property.

// Example 1:
// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation:
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba",
// "cbda" are also valid outputs.

// Example 2:
// Input: order = "cbafg", s = "abcd"
// Output: "cbad"

// Constraints:
// 1 <= order.length <= 26
// 1 <= s.length <= 200
// order and s consist of lowercase English letters.
// All the characters of order are unique.

// __________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

string customSortString(string order, string s)
{
    string s1, s2;
    int a[26] = {0};
    for (char ch : order)
    {
        a[ch - 'a']++;
    }
    for (char ch : s)
    {
        if (a[ch - 'a'] == 0)
        {
            s2 = s2 + ch;
        }
        else
        {
            a[ch - 'a']++;
        }
    }
    for (char ch : order)
    {
        while (a[ch - 'a'] > 1)
        {
            s1 = s1 + ch;
            a[ch - 'a']--;
        }
    }
    return s1 + s2;
}

int main()
{
    string order, s;
    cout << "Enter the order: " << endl;
    cin >> order;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "The resultant string is: " << customSortString(order, s);
    cout << endl;
    return 0;
}

/*
T.C. -> O(n)
S.C. -> O(n)


for(char ch: order)
{
    while(a[ch-'a'] > 1)
    {
        s1 = s1 + ch;
        a[ch-'a']--;
    }
}

The outer loop iterates over all characters in the order string, which has a constant length
(26 for lowercase English letters).
The while loop inside the outer loop will execute for each character as long as its count in the array a
is greater than 1. However, after the while loop executes for a character and decreases the count to 1,
it will not enter the while loop again for the same character in subsequent iterations of the outer loop.

As a result, the overall number of iterations of the while loop is at most the total number of characters
in the input string s. Therefore, the time complexity of this section is O(N), where N is the length of
the input string s.
*/