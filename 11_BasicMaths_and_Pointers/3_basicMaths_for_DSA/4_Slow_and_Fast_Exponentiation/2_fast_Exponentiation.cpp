#include <iostream>
using namespace std;

int fastExponentiation(int a, int b)
{
    int ans = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            // odd
            ans = ans * a;
        }
        a = a * a;
        b >>=1;
    }
    return ans;
}

// TC -> O(logb)

int main()
{   
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter a: " << endl;
    cin >> b;
    cout << fastExponentiation(a, b) << endl;
    return 0;
}

// Basically because we do b>>=1, at the last iteration before b becomes 0, b would always be 1,
// so we will visit the if case atleast once in any case. And there we would store the final result.

// For example:
// a = 5, b = 3    | Output: 125

// b is odd
// ans = ans * a
// ans = 1 * 5 = 5
// a = a * a
// a = 5 * 5  = 25
// b>>=1
// b = 1
// _______________________________________

// b is odd
// ans = ans * a 
// ans = 5 * 25 = 125
// a = a * a
// a = 25 * 25 = 625
// n>>=1
// n = 0
// ______________________________________
// breaks out of while loop
// returns ans = 125