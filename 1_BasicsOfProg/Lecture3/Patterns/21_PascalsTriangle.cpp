#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of rows: ";
    int rows;
    cin>>rows;
    for (int i=1; i<=rows; i++)
    {
        int coef=1;
        for (int k=rows-i; k>0 ;k--)
        {
            cout<<" ";
        }
        for (int j=1; j<=i; j++)
        {
            cout<<coef<<" ";
            coef=coef*(i-j)/j;
        }
        cout<<endl;
    }
    return 0;
}