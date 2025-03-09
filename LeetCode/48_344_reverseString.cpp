// 🔴🔴🔴🔴 LEETCODE 344 -> Reverse String 🔴🔴🔴🔴

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

// Constraints:
// 1 <= s.length <= 10^5
// s[i] is a printable ascii character.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    cout << "Enter a string: " << endl;
    string input;
    getline(cin, input);

    // Convert the string to a vector<char>
    vector<char> charVector(input.begin(), input.end());

    reverseString(charVector);
    cout << "Reversed string: " << endl;
    for (char c : charVector)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}

// T.C. -> O(N)
// S.C. -> O(1)
