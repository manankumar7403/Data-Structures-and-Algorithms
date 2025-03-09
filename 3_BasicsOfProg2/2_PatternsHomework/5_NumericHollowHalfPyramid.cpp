#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<i+1; j++)
        {
            if (j==0 || j==i || i==rows-1)
            {
                cout<<j+1<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}