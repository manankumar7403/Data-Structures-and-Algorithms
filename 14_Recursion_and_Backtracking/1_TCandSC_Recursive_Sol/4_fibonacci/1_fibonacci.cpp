#include <iostream>
using namespace std;

int fib(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << fib(n);
    cout << endl;
    return 0;
}

// TC -> O(2^n)
// SC -> O(n)