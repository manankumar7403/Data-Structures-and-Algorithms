//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=1; i<=rows; i++)
    {
        int C = 1;
        for (int j=1; j<=i; j++)
        {
            cout<<C<<" ";
            C = C * (i-j) / j;        // Formula for Pascal's Triangle Pattern
        }
        cout<<endl;
    }
}