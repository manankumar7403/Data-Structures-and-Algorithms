// ⭐⭐Important Question⭐⭐
/*
#include<iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while(n != 0)
    {
        int lastBit = n & 1;
        if(lastBit)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int ans = countSetBits(n);
    cout << "Number of set bits in " << n << " are: " << ans <<endl;
    return 0;
}

// Number of significant digits in binary representation excluding few 0s from the MSB side is approx logn
// Therefore, TC -> O(logn)
*/

// _____________________________________________________________________________________________________________

// 🔴🔴Optimized Approach🔴🔴

#include<iostream>
using namespace std;

int countSetBitsOptimized(int n)
{
    int count = 0;
    while(n != 0)
    {
        // remove last set bit
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int ans = countSetBitsOptimized(n);
    cout << "Number of set bits in " << n << " are: " << ans <<endl;
    return 0;
}