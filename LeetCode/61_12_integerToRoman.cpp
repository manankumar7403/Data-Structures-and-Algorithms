// 🔴🔴🔴🔴 LEETCODE 12 -> Integer To Roman 🔴🔴🔴🔴
// Refer 10_Week5_Assignments
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is
not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making
four. The same principle applies to the number nine, which is written as IX. There are six instances where
subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
1 <= num <= 3999
*/

// ____________________________________________________________________________________________________

#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num)
{
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans = ans + romanSymbols[i];
            num = num - values[i];
        }
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;
    cout << intToRoman(num);
    cout << endl;
    return 0;
}

// TC -> O(1)
// SC -> O(1)

// ________________________________________________________________
/*
Example 1:

Input: 58    | Output:  LVIII
num = 58;

i=0 to i < 13;

1) 58 >= values[i]?  => values[0] = 1000?  NO
2) 58 >= values[i]?  => values[1] = 900?  NO
3) 58 >= values[i]?  => values[2] = 500?  NO
4) 58 >= values[i]?  => values[3] = 400?  NO
5) 58 >= values[i]?  => values[4] = 100?  NO
6) 58 >= values[i]?  => values[5] = 90?  NO
7) 58 >= values[i]?  => values[6] = 50?  YES

        ans = "" + romanSymbols[6] => ans = "" + L = L
        num = 58 - values[i] => num = 58 - 50 = 8

8) 8 >= values[i]?  => values[7] = 40?  NO
9) 8 >= values[i]?  => values[8] = 10?  NO
10) 8 >= values[i]?  => values[9] = 9?  NO
11) 8 >= values[i]?  => values[10] = 5?  YES

        ans = L + romanSymbols[10] => ans = L + V = LV
        num = 8 - values[i] => num = 8 - 5 = 3

12) 3 >= values[i]?  => values[11] = 4?  NO
13) 3 >= values[i]?  => values[12] = 1?  YES

        ans = LV + romanSymbols[12] => ans = LV + I = LVI
        num = 3 - values[i] => num = 3 - 1 = 2

    2 >= values[i]? => values[12] = 1? YES

        ans = LVI + romanSymbols[12] => ans = LVI + I = LVII
        num = 2 - values[i] => num = 2 - 1 = 1

    1 >= values[i]? => values[12] = 1? YES

        ans = LVII + romanSymbols[12] => ans = LVII + I = LVIII
        num = 1 - values[i] => num = 1 - 1 = 0

14) i = 13 => breaks out of for loop and returns ans

    ans = LVIII
*/

// ___________________________________________________________________________________________________
/*
Example 2:

Input: 1994    | Output:  MCMXCIV
num = 1994;

i=0 to i < 13;

1) 1994 >= values[i]?  => values[0] = 1000?  YES

        ans = "" + romanSymbols[0] => ans = "" + M = M
        num = 1994 - values[i] => num = 1994 - 1000 = 994

2) 994 >= values[i]?  => values[1] = 900?  YES

        ans = M + romanSymbols[1] => ans = M + CM = MCM
        num = 994 - values[i] => num = 994 - 900 = 94

3) 94 >= values[i]?  => values[2] = 500?  NO
4) 94 >= values[i]?  => values[3] = 400?  NO
5) 94 >= values[i]?  => values[4] = 100?  NO
6) 94 >= values[i]?  => values[5] = 90?  YES

        ans = MCM + romanSymbols[5] => ans = MCM + XC = MCMXC
        num = 94 - values[i] => num = 94 - 90 = 4

7) 4 >= values[i]?  => values[6] = 50?  NO
8) 4 >= values[i]?  => values[7] = 40?  NO
9) 4 >= values[i]?  => values[8] = 10?  NO
10) 4 >= values[i]?  => values[9] = 9?  NO
11) 4 >= values[i]?  => values[10] = 5?  NO
12) 4 >= values[i]?  => values[11] = 4?  YES

        ans = MCMXC + romanSymbols[11] => ans = MCMXC + IV = MCMXCIV
        num = 4 - values[i] => num = 4 - 4 = 0

13) i = 12 
            => 0 >= 1? NO
14) i=13 => breaks out of for loop and return ans

    ans = MCMXCIV
*/
