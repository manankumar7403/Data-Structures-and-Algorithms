// i/p -> n
// o/p -> nth fibonacci num
// 0, 1, 1, 2, 3, 5, 8, 13.....
// n = 4
// o/p -> 3

#include <iostream>
using namespace std;

int nthFibonacci(int n)
{
    int a = 0;
    int b = 1;
    int ans;
    if(n==0)
    {
        return a;
    }
    for(int i=2; i<=n; i++)
    {
        ans = a+b;
        a=b;
        b=ans;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the nth fibonacci num: ";
    cin >> n;
    cout << nthFibonacci(n);
    return 0;
}