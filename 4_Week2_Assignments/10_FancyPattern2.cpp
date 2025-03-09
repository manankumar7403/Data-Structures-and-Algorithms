//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴

#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;

    //growing phase
    int c=1;
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            cout<<c;
            c++;

            if(j<i)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }

    // Now value of c at end for 4 rows = 11
    // but we need to start from 7, so formula = c-rows = 11-4=7

    //shrinking phase
    int start = c-rows;
    for(int i=0; i<rows; i++)
    {
        int k=start;
        for(int j=0; j<rows-i; j++)
        {
            cout<<k;
            k++;

            if(j<rows-i-1)
            {
                cout<<"*";
            }
        }
        start = start - (rows-i-1);  // updating start for each row (shrinking) e.g. start=7-(4-0-1)=4 which is the starting no. of the next row.
        cout<<endl;
    }
}