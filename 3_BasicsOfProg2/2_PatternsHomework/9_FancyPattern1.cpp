//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴

#include <iostream>
#include "assert.h"
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    assert(rows<=9);
    for (int i=0; i<rows; i++)
    {
        int start_num_index = 8-i; // Have to print the numbers from 8-i (8-0=8 for index of 1, 8-1=7 for index of 2...)
        int num = i+1;             // The number to be printed is i+1 (0+1=1 in 1st row, 1+1=2 in 2nd row.....)
        int count_num = num;       // How many times the number is printed (0+1=1 -> 1 is printed once, 1+1=2 -> 2 is printed twice...)
        for (int j=0; j<17; j++)
        {
            if(j==start_num_index && count_num > 0) // count_num>0 -> printing till it's greater than 0.
            {
                cout<<num;           // print the num
                start_num_index +=2; // printing same number in the row after every 2 spaces(alternate).
                count_num--;         // reduing count_num after every iteration, e.g. first 6 has to be printed 6 more times, then 5 more times....
            }
            else
            {
                cout<<"*";          // print '*' at each place where num is not printed.
            }
        }
        cout<<endl;
    }
}



// assert is used in industry to to specify the input condition, here the input
// shouldn't exceed more than 9.