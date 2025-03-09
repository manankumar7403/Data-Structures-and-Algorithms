#include <iostream>
using namespace std;

void printRowWiseSum(int arr[][3], int rows, int cols)  // In a 2D array(minimum) only leave the first bracket empty, have to give value for all other brackets
{
    // row sum -> row-wise traversal
    cout<<"Printing row-wise sum: "<<endl;
    for(int i=0; i<rows; i++)
    {
        int sum=0;
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
    int rows=3;
    int cols=3;

    // row-wise input
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Printing row-wise"<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    printRowWiseSum(arr, rows, cols);

}