// 🔴🔴🔴🔴 LEETCODE 28 -> Find the Index of the First Occurrence in a String 🔴🔴🔴🔴

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1. 

// Constraints:
// 1 <= haystack.length, needle.length <= 10^4
// haystack and needle consist of only lowercase English characters.

// __________________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();
    for(int i=0; i<=n-m; i++)               // hs=sadbutsad, needle=sad, so n-m = 6 => should be found till index 6 otherwise no point of checking further
    {
        for(int j=0; j<m; j++)              // checking if all chars of needle are present in haystack, not just the first one
        {
            if(needle[j] != haystack[i+j])
            {
                break;
            }
            if(j == m-1)                   // if needle is found completely, we return i meaning we found the needle, so print the index at which it is found
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    string haystack, needle;
    cout << "Enter the string haystack: " << endl;
    getline(cin, haystack);
    cout << "Enter the string needle: " << endl;
    getline(cin, needle);
    cout << "Index: " << strStr(haystack, needle);
    cout << endl;
    return 0;
}

// TC -> O((n-m+1)*m) = O(n*m-m^2*m) = O(n*m)
// SC -> O(1)
// ⭐⭐⭐⭐✨✨✨✨
// FOR INTERVIEWS, Learn About:
//KMP (Knuth Morris Pratt) => https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
//Rabin-Karp => https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/