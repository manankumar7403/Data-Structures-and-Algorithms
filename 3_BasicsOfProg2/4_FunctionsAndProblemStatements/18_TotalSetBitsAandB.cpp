// a = 2 = 10
// b = 3 = 11
// Total set bits = 1+2=3

#include <iostream>
#include <math.h>
using namespace std;

int bitConverter(int n)                   // converting decimal to binary
{
    int i = 0;
    int ans = 0;
    while(n!=0)
    {
        int bit = n&1;
        ans = ans + bit*pow(10, i);
        n = n >> 1;
        i++;
    }
    return ans;
}

int bitCounter(int n)                    // counting bits in binary representation
{
    int num = bitConverter(n);
    int ans = 0;
    while(num!=0)
    {
        int digit = num%10;
        if(digit == 1)
        {
            ans = ans + digit;
        }
        num = num/10;
    }
    return ans;
}

int main()
{
    int a, b;
    cout << "Enter the value of a and b: " << endl;
    cin >> a >> b;

    int answer = bitCounter(a) + bitCounter(b);
    cout<<answer;
}