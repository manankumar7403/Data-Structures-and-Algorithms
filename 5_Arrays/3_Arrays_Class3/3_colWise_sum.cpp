#include <iostream>
using namespace std;

void printColWiseSum(int arr[][3], int rows, int cols)
{
    // col sum -> col-wise traversal
    cout<<"Printing col-wise sum: "<<endl;
    for(int i=0; i<rows; i++)
    {
        int sum = 0;
        for(int j=0; j<cols; j++)
        {
            sum = sum + arr[i][j];
        }
        cout<<sum<<endl;
    }
}

int main()
{
    int arr[3][3];
    int rows = 3;
    int cols = 3;

    // column-wise input
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin>>arr[j][i];
        }
    }

    cout<<"Printing column-wise: "<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    printColWiseSum(arr, rows, cols);
}