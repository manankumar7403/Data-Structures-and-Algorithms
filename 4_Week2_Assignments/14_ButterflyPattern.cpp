//🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴 VERY IMPORTANT!!!!!!!!!!! 🔴🔴🔴🔴🔴🔴🔴🔴🔴🔴
#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for (int i=0; i<2*rows; i++)
    {
        int cond = i < rows ? i : rows + (rows-i-1);
        int space_count = i < rows ? 2*(rows-cond-1) : i-cond-1; 
        for (int j=0; j<2*rows; j++)
        {
            if(j<=cond)
            {
                cout<<"* ";
            }
            else if(space_count > 0)
            {
                cout<<"  ";
                space_count--;
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}