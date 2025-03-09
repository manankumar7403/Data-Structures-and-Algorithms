// It's the same as Week1_Assignments 18_PQ4_HollowFullPyramid but could be done without using 'k'.
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<((2*rows)-1); j++)  /*This is to make sure there are exact number of char required in the pyramid, e.g., in a rows=5 pyramid, there are 10 chars*/
        {
            if(j<rows-i-1)          /*Prints the spaces on the left of the numbers*/
            {
                cout<<" ";
            }   
        }

        for (int j=0; j<i+1; j++)
        {
            if(j==0 || j==i || i==rows-1)      /*Prints j+1 at start and at last of every row and the entire bottom row. Prints a space after every number*/
            {
                cout<<j+1<<" ";
            }
            else
            {
                cout<<"  ";             /*Prints 2 blank spaces in place of every number that is not at first or last position*/
            }
        }
        cout<<endl;
    }
}

// It's the same as Week1_Assignments 18_PQ4_HollowFullPyramid but done without using 'k'.






