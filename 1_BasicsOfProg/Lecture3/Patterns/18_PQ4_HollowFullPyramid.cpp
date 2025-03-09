#include <iostream>
using namespace std;
int main() {
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<rows; i++)
    {
        int k=0;
        for (int j=0; j<((2*rows)-1); j++)
        {
            if (j < rows-i-1)
            {
                cout<<"  ";
            }
            else if (k < 2*i+1)
            {
                if (k==0 || k==2*i || i==rows-1)
                {
                    cout<<"* ";
                }
                else {
                    cout<<"  ";
                }
                k++;
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
// else if condition is just to print *.
// Check Patterns Q4 in Week1-Assignments for more explanation