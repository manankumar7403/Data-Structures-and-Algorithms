#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    if(n<=1)
    {
        return false;
    }
    for (int i=2; i<n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    int n;
    cout<<"Enter a number to print primes from 1 to num: ";
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        bool isiPrime = checkPrime(i);
        if(isiPrime)
        {
            cout<<i<<" ";
        }
    }
}