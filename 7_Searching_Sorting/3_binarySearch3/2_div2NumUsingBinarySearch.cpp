// Basically, we need to get the quotient
// dividend = 22
// divisor = 7
// quotient = 3
// remainder = 1
// quotient*divisor+remainder = dividend

// #include <iostream>
// using namespace std;

// int solve(int dividend, int divisor)
// {
//     int start = 0;
//     int end = dividend;
//     int mid = start + (end-start)/2;
//     int ans = 0;
//     while(start<=end)
//     {
//         // perfect solution
//         if(mid*divisor == dividend)
//         {
//             return mid;
//         }

//         // not perfect solution
//         if(mid*divisor > dividend)
//         {
//             // search left
//             end = mid-1;
//         }
//         else
//         {
//             // store ans
//             ans = mid;
//             // search right
//             start = mid+1;
//         }
//         mid = start+(end-start)/2;
//     }
//     return ans;
// }

// int main()
// {
//     int dividend = 22;
//     int divisor = 7;

//     int ans = solve(dividend, divisor);
//     cout << "Ans is " << ans << endl;
//     return 0;
// }
// ________________________________________________________________________________________________

// This was for positive numbers only, now making changes for division of both pos and neg numbers:
#include <iostream>
#include <cmath>
using namespace std;

int solve(int dividend, int divisor)
{
    int start = 0;
    int end = abs(dividend);
    int mid = start + (end - start) / 2;
    int ans = 0;
    while (start <= end)
    {
        // perfect solution
        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }

        // not perfect solution
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

    int result = solve(dividend, divisor);

    cout << "Quotient is " << result << endl;
    return 0;
}