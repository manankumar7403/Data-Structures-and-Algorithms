#include <iostream>
using namespace std;
int main ()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<i+1; j++)
        {
            cout<<i+1;
            if(j!=i)          /*Counting started from j=0 to i+1, and we don't have to print * at last so we make sure * is only printed when j not equal to i+1-1=i*/
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }

    for (int i=0; i<rows; i++)
    {   
        for (int j=0; j<rows-i; j++)
        {
            cout<<rows-i;
            if(j!=rows-i-1)  /*Counting started from j=0 to rows-i, and we don't have to print * at last so we make sure * is only printed when j not equal to rows-i-1*/
            {
                cout<<"*";
            }

        }
        cout<<endl;
    }
}