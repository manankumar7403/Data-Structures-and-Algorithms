//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"*"<<endl;
    for (int i=0; i<rows; i++)
    {
        cout<<"*"<<" ";
        int cond = i <= rows/2 ? 2*i : 2*(rows-i-1);
        //input rows=5
        // When i is <=rows/2 (growing phase -> till middle row), then j will go till 2*i,...else 2*(rows-i-1)
        // In 0th row we have nums at 0th index
        // In 1st row we have nums at 0,1,2 index
        // In 2nd row we have nums at 0,1,2,3,4 index
        for(int j=0; j<=cond; j++) // this will print the numbers in the growing phase 
        {
            if(j<=cond/2)     // will print the increasing numbers 1(1st row), 12(2nd row), 123(3rd row) only
            {
                cout<<j+1<<" ";
            }
            else
            {
                cout<<cond-j+1<<" "; // will print the decreasing numbers (for middle row after 123 is printed, we have to print 21.)
                                // so cond=4 right now as j would go till 4.
                                // j=3
                                // so, 4-3+1=2 then, 4-4+1=1
            }
        }
        cout<<"*";
        cout<<endl;
    }
    cout<<"*";
}

// int cond = i <= rows/2 ? 2*i : 2*(rows-i-1);
// cond = i is assigned
// i<=rows/2 is the test expression

// 2*i is the row-wise growing phase condition
// 2*(rows-i-1) is the row-wise shrinking phase condition

// if(j<=cond/2)
// {
//     cout<<j+1;         // this is the column wise growing phase condition
// }

// else
// {
//     cout<<cond-j+1        // this is the column wise sinking phase condition
// }