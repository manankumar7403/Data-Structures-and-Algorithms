// 🔴🔴🔴🔴 LEETCODE 13 -> Roman To Integer 🔴🔴🔴🔴
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

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII,
which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four
is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it
making four. The same principle applies to the number nine, which is written as IX. There are six instances
where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

// __________________________________________________________________________________________

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            // for cases such as IV, CM, XL, DM etc....
            ans = ans - mp[s[i]];
        }
        else
        {
            ans = ans + mp[s[i]];
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter a string: " << endl;

    getline(cin, s);
    cout << romanToInt(s);
    cout << endl;
    return 0;
}

// TC -> O(n)
// SC -> O(1)
// _____________________________________________________________________________________
/*
Example 1:
Input: LVIII                    |    Output: 58

ans = 0;
s.length() = > LVIII length = 5
i = 0 to i < 5

1)  i = 0
    mp[s[0]] < mp[s[1]]?   => L < V?  => 50 < 5?  NO
    
    else condition
    ans = 0 + mp[s[i]] => 0 + mp[L] => 0+50 = 50

2)  i = 1
    mp[s[1]] < mp[s[2]]?   => V < I?  => 5 < 1?  NO
    
    else condition
    ans = 50 + mp[s[i]] => 50 + mp[V] => 50+5 = 55

3)  i = 2
    mp[s[2]] < mp[s[3]]?   => I < I?  => 1 < 1?  NO
    
    else condition
    ans = 55 + mp[s[i]] => 55 + mp[I] => 55+1 = 56

4)  i = 3
    mp[s[3]] < mp[s[4]]?   => I < I?  => 1 < 1?  NO
    
    else condition
    ans = 56 + mp[s[i]] => 56 + mp[I] => 56+1 = 57

5)  i = 4
    mp[s[4]] < mp[s[5]]?   => I < '\0'?  => 1 < '\0'?  NO
    
    else condition
    ans = 57 + mp[s[i]] => 57 + mp[I] => 57+1 = 58

Now i becomes 5, and 5 < 5 is not true so breaks out of for loop and return ans.
ans = 58
*/
// _______________________________________________________________________________________________

/*
Example 2:
Input: MCMXCIV                    |    Output: 1994

ans = 0;
s.length() = > MCMXCIV length = 7
i = 0 to i < 7

1)  i = 0
    mp[s[0]] < mp[s[1]]?   => M < C?  => 1000 < 100?  NO
    
    else condition
    ans = 0 + mp[s[i]] => 0 + mp[M] => 0+1000 = 1000

2)  i = 1
    mp[s[1]] < mp[s[2]]?   => C < M?  => 100 < 1000?  YES
    ans = 1000 - mp[s[i]] => 1000 - mp[C] => 1000-100 = 900

3)  i = 2
    mp[s[2]] < mp[s[3]]?   => M < X?  => 1000 < 10?  NO
    
    else condition
    ans = 900 + mp[s[i]] => 900 + mp[M] => 900+1000 = 1900

4)  i = 3
    mp[s[3]] < mp[s[4]]?   => X < C?  => 10 < 100?  YES
    ans = 1900 - mp[s[i]] => 1900 - mp[X] => 1900-10 = 1890

5)  i = 4
    mp[s[4]] < mp[s[5]]?   => C < I?  => 100 < 1?  NO
    
    else condition
    ans = 1890 + mp[s[i]] => 1890 + mp[C] => 1890+100 = 1990

6)  i = 5
    mp[s[5]] < mp[s[6]]?   => I < V?  => 1 < 5?  YES
    ans = 1990 - mp[s[i]] => 1990 - mp[I] => 1990-1 = 1989

7)  i = 6
    mp[s[6]] < mp[s[7]]?   => V < '\0'?  => 5 < '\0'?  NO
    
    else condition
    ans = 1989 + mp[s[i]] => 1989 + mp[V] => 1989+5 = 1994

Now i becomes 7, and 7 < 7 is not true so breaks out of for loop and return ans.
ans = 1994
*/