// 🔴🔴🔴🔴🔴 IMPORTANT  🔴🔴🔴🔴🔴
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the k value: ";
    cin>>k;
    int mask = 1 << k;
    int ans = n | mask;
    cout<<ans;
}

/*
//Example Explanation GFG
n = 10     k = 2

10 in binary = 1010
0th bit from right = 0
1st bit from right = 1
2nd bit from right = 0

mask = 1 << 2
mask = 0100

n | mask
1010
0100
----
1110 = 14
ans = 14
*/

/*
n = 15     k = 3
15 in binary = 1111
3rd bit from right = 1

mask = 1<<3
mask = 1000

n | mask
1111
1000
----
1111 = 15
ans = 15
*/