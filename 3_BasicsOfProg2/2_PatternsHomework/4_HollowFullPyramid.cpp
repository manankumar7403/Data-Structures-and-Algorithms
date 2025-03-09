#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<((2*rows)-1); j++)   /*For total number of characters including blank space*/
        {
            if(j<rows-i-1)  /* Prints the spaces present to the left of '*'. */
            {
                cout<<" ";
            }
        }

        for (int j=0; j<i+1; j++)
        {
            if(j==0 || j==i || i==rows-1)  /*Prints '*' at every first and last position of each row and at every position of the last row*/
            {
                cout<<"* ";
            }
            else
            {
                cout<<"  ";  /*Prints 2 blank spaces in place of each '*' that is not at first or last position*/
            }
        }
        cout<<endl;
    }
}