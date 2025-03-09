#include <iostream>
using namespace std;

long long int PowMod(long long int x, long long int n, long long int m)
{
    long long int ans = 1;
    while(n > 0)
    {
        // odd
        if(n&1)
        {
            ans = (ans * x) % m; 
        }
        // even
        x = (x * x) % m;
        n >>=1;
    }
    return ans % m;
}

int main()
{
    long long int x, n, m;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter n: " << endl;
    cin >> n;
    cout << "Enter m: " << endl;
    cin >> m;
    cout << PowMod(x, n, m) << endl;
    return 0;
}


// Basically because we do n>>=1, at the last iteration before n becomes 0, n would always be 1,
// so we will visit the if case atleast once in any case. And there we would store the final result.

// For example:
// x = 2, n = 3, m = 5    | Output: 3

// n is odd
// ans = (ans*x) % m
// ans = (1*2) % 5 = 2
// x = (x*x) % m
// x = (2*2) % 5 = 4
// n>>=1
// n = 1
// _______________________________________

// n is odd
// ans = (ans*x) % m
// ans = (2*4) % 5 = 3
// x = (x*x) % m
// x = (4*4) % 5 = 16
// n>>=1
// n = 0
// ______________________________________
// breaks out of while loop
// returns ans = 3
