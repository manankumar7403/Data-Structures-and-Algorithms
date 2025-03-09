#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int ans = 0;
    while (n!=0)
    {
        if (n & 1)         // if n & 1 is true meaning if n&1 == 1
        {
            ans++;
        }

        n = n >> 1;
    }

    cout<<"Number of set bits: "<<ans<<endl;
}


// Suppose n = 11
// ans = 0
// 11 in binary = 00001011
// 00001011
// 00000001
// --------
// 00000001

// ans=1

// n = 00000101
// ___________________

// 00000101
// 00000001
// --------
// 00000001

// ans = 2

// n = 00000010
// _____________________
// 00000010
// 00000001
// --------
// 00000000

// ans = 2

// n = 00000001
// _____________________
// 00000001
// 00000001
// --------
// 00000001

// ans = 3

// n = 00000000

// Not possible to do it for a negative number as
// say -11
// binary of -11 = -1011
// 00001011
// Now 1s complement
// 11110100
// Now 2s complement
// 11110101
// If we do right shift we'll get infinite ones -> (while n!=0) would stuck in 
// an infinite loop.
