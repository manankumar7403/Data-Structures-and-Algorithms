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
    cout<<"Enter a number to check if it's prime or not: ";
    cin>>n;
    bool isPrime = checkPrime(n);
    if(isPrime)
    {
        cout<<n<<" is a prime number"<<endl;
    }
    else
    {
        cout<<n<<" is not a prime number"<<endl;
    }
}