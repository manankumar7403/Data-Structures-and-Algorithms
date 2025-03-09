// #include <iostream>
// #include <climits>   // For INT_MIN and INT_MAX
// using namespace std;
// int main()
// {
//     int x;
//     cout<<"Enter a number: ";
//     cin>>x;
//     int ans = 0;
//         bool isNeg = false;
//         if(x <= INT_MIN)
//         {
//             cout<<0;
//             return 0;
//         }
//         if(x < 0)
//         {
//             isNeg = true;
//             x = -x;
//         }
//         while(x > 0)
//         {
//             if(ans > INT_MAX / 10)
//             {
//                 cout<<0;
//                 return 0;
//             }
//             int digit = x % 10;
//             ans = ans * 10 + digit;
//             x = x / 10;
//         }
//         if(isNeg)
//         {
//             cout<<-ans;
//         }
//         else{
//             cout<<ans;
//         }
// }

/*
int ans = 0;
int digit = x % 10;
            ans = ans * 10 + digit;
            x = x / 10;

say x = 123
digit = x%10=3
ans=0*10+3=3
x = 123/10=12
-----
digit=12%10=2
ans=3*10+2=32
x=12/10=1
-----
digit=1%10=1
ans=32*10+1=321
x=1/10=0
*/

// ________________________________________________
/*
bool isNeg = false;
if(x < 0)
        {
            isNeg = true;
            x = -x;
        }
We use bool isNeg to check if a number is negative, if it is negative we make it positive
(x=-x) and then

if(isNeg)
        {
            cout<<-ans;
        }
        else{
            cout<<ans;
        }

if isNeg was true(number was negative and we made it positive), we make it negative again
(-ans), else just print the ans. */

// _________________________________________________________
/*
INT_MAX = 2147483647
INT_MAX / 10 = 214748364
if(ans > INT_MAX / 10)
            {
                cout<<0;
                return 0;
            }

suppose ans = 214748365
Now when
// int digit = x % 10;
//             ans = ans * 10 + digit;
//             x = x / 10;
is executed
say the least digit = 0
ans = 214748365 * 10 + 0 = 2147483650 which is an overflow condition.
So we are stopping it at INT_MAX / 10 only making it OPTIMIZABLE
*/

// _________________________________________________________________

// if(x <= INT_MIN)
//         {
//             cout<<0;
//             return 0;
//         }

// Why have we used <= instead of <?
// INT_MIN = -2147483648
// If we take any value of x which is less than or equal to INT_MIN 
// and then convert x = -x, then it becomes positive and greater than INT_MAX which
// results in an overflow condition.

// _____________________________________________________________
// _____________________________________________________________
// _____________________________________________________________

// 2nd method
#include <iostream>
#include <climits>   // For INT_MIN and INT_MAX
using namespace std;
int main()
{
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    int ans = 0;
    while(x!=0)
    {
        int digit = x % 10;

        if(ans > INT_MAX/10 || ans < INT_MIN/10)
        {   
            cout<<0;
            return 0;
        }

        ans = (ans*10) + digit;;
        x = x/10;
    }
    cout<<ans;
}






