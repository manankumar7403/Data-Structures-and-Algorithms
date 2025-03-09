/*
✨✨✨✨ VERY IMPORTANT ✨✨✨✨
TREATING 1D Vector as 2D Vector
🔴🔴🔴🔴 LEETCODE 6 -> Zigzag Conversion 🔴🔴🔴🔴

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
// _________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> zigzag(numRows);
    int i = 0, row = 0; // i will traverse on the original string
    bool direction = 1; // 1 means Top to Bottom

    while (true)
    {
        if (direction) // if direction is 1 we will go top to bottom
        {
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else // direction is 0, so we will go bottom to top
        {
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        if (i >= s.size())
            break;
        direction = !direction; // changing the direction
    }
    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans = ans + zigzag[i];
        cout << zigzag[i] << endl;
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    getline(cin, s);
    int numRows;
    cout << "Enter the number of rows: " << endl;
    cin >> numRows;
    cout << convert(s, numRows);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(n)