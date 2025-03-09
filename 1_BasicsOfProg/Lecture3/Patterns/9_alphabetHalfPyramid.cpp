#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of rows: ";
    int rows;
    cin>>rows;
    char alphabet = 'a';
    for(int i=1; i<=rows; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cout<<alphabet;
        }
        alphabet++;
        cout<<endl;
    }
}