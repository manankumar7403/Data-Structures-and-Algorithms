// Given two integers dividend and divisor, divide two integers without using multiplication,
// division, and mod operator.
// The integer division should truncate toward zero, which means losing its fractional part.
// For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
// Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed
// integer range: [-2^31, 2^31 - 1]. For this problem, if the quotient is strictly greater than 2^31 - 1,
// then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

// Constraints:
// -2^31 <= dividend, divisor <= 2^31 - 1
// divisor != 0

#include <iostream>
#include <cmath>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    long int start = 0;
    long int end = abs(dividend);
    long int mid = start + (end - start) / 2;
    int ans = 0;
    while (start <= end)
    {
        // perfect solution
        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }
        // not a perfect solution
        else if (abs(mid * divisor) > abs(dividend))
        {
            // search left
            end = mid - 1;
        }
        else
        {
            // store ans
            ans = mid;
            // search right
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0))
    {
        // if both dividend and divisor are positive or both are neagtive, then upon dividing we get a positive number
        return ans;
    }
    else
    {
        // either of them is negative, upon dividing we get a negative number
        return -ans;
    }
}

int main()
{
    int dividend, divisor;
    cout << "Enter the dividend: " << endl;
    cin >> dividend;
    cout << "Enter the divisor: " << endl;
    cin >> divisor;

    int result = divide(dividend, divisor);

    cout << "Quotient is " << result << endl;
    return 0;
}