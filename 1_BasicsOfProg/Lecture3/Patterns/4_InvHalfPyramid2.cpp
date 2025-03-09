#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    for(int i=rows; i>0; i--)
    {
        for(int k=rows-i; k>0; k--)
        {
            cout<<" ";
        }
        for(int j=i; j>0; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}