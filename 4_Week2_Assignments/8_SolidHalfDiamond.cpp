//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴

#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<2*rows-1; i++)
    {
        int cond=0;
        if(i<rows)      //growing phase of diamond
        {
            cond=i;
        }
        else            // shrinking phase of diamond
        {
            cond = rows - (i%rows) - 2;
        }
        for (int j=0; j<=cond; j++)
        {   
            cout<<"* ";
        }
        cout<<endl;
    }
}

// The if condition makes sure that the '*' till the specified rows, say 5 is printed (growing phase), from index 0 to 4 or first 5 rows.
// The else block is for the shrinking phase (from index 5 to 8 or last 4 rows).

// Calculation for else block: cond = rows - (i%rows) - 2;
//                             j=0; j<=cond; j++

// Say rows = 5
// i=5
// So for the 5th row
// I) 5 - (5%5) - 2 = 3 -> so cond = 3 ->
//    j=0 to 3, therefore 4 "* " are printed.

// II) 5 - (6%5) - 2 = 2 -> so cond = 2 ->
//     j=0 to 2, therefore 3 "* " are printed.

// III) 5 - (7%5) - 2 = 1 -> so cond = 1 ->
//      j=0 to 1, therefore 2 "* " are printed.

// IV) 5 - (8%5) - 2 = 0 -> so cond = 0 ->
//      j=0 to 0 (inclusive), therefore 1 "* " is printed.

//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 CAN ALSO USE THE TERNARY OPERATOR INSTEAD OF IF ELSE 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴

// int cond = i < rows ? i : rows - (i%rows) - 2;