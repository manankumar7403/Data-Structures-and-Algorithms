#include <iostream>
using namespace std;
int main() {
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        //spaces
        for (int j=0; j<rows-i-1; j++)
        {
            cout<<" ";
        }

        //stars
        for (int j=0; j<2*i+1; j++)
        {
            // if first or last character
            if (j==0 || j==2*i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    for (int i=0; i<rows; i++)
    {
        //spaces
        for (int j=0; j<i; j++)
        {
            cout<<" ";
        }

        //stars -> Now if we want to print the stars which are opposite to the ones we printed previously, we need to subtract from rows.
        for (int j=0; j<2*rows - 2*i - 1; j++)
        {
            //if first or last character
            if(j==0 || j==2*rows - 2*i - 2)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}