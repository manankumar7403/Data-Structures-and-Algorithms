#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        int j;
        for (j=0; j<i+1; j++)
        {
            //To print num
            // cout<<j+1;

            //To print alphabet
            int ans = j+1;
            char ch = ans + 'A' -1;
            cout<<ch;
        }

        for (j=i; j>=1; j--)
        {
            //To print num
            // cout<<j;

            //To print alphabet
            int ans = j;
            char ch = ans + 'A' -1;
            cout<<ch;
        }
        cout<<endl;
    }
}