// 🔴🔴🔴🔴 LEETCODE 415 -> Add strings 🔴🔴🔴🔴
/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2
as a string.
You must solve the problem without using any built-in library for handling large integers
(such as BigInteger). You must also not convert the inputs to integers directly. 

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"

Constraints:
1 <= num1.length, num2.length <= 10^4
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/
// ________________________________________________________________________________________

#include <iostream>
#include <algorithm>
using namespace std;

void addRE(string&num1, int p1, string&num2, int p2, int carry, string& ans)
{
    // Base Case
    if(p1 < 0 && p2 < 0)
    {
        if(carry != 0)
        {
            ans.push_back(carry + '0'); // if non-zero carry we will push back the carry and convert to str. 
        }
        return;  // if carry is zero, return as it is.
    }

    // Ek case solve kardo
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';  // -'0' to convert str to integer
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';  // -'0' to convert str to integer
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    ans.push_back(digit + '0');  // + '0' to convert integer to str

    // Baaki recursion sambhal lega
    addRE(num1, p1-1, num2, p2-1, carry, ans);
}

string addStrings(string num1, string num2)
{
    string ans = "";
    addRE(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
    reverse(ans.begin(), ans.end());      // Reverse the string as addition took place from right to the left.
    return ans;
}

int main()
{
    string num1, num2;
    cout << "Enter the first string: " << endl;
    cin >> num1;
    cout << "Enter the second string: " << endl;
    cin >> num2;
    cout << addStrings(num1, num2);
    cout << endl;
    return 0;
}

// NOTE: p1 and p2 are the pointers and first I have initialized them to the particular size of the str
// p1 is size-1 of string 1 and p2 is size-1 of string 2

// TC -> O(n)
// SC -> O(n)