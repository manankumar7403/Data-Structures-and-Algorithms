#include <iostream>
using namespace std;

// Function being declared - so, n is a parameter here
void printCounting(int n)
{
    for (int i=1; i<=n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

// Function being invoked - so, n is an argument here
int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    printCounting(n);
    return 0;
}

// 🔴🔴🔴🔴🔴🔴IMPORTANT🔴🔴🔴🔴🔴🔴
// An argument is a value or expression passed to a function when it is called.
// A parameter is a variable declared in a function definition. The main difference between
// an argument and a parameter is that arguments are passed when a function is called, while
// parameters are declared when a function is defined.