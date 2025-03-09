#include <iostream>
using namespace std;

void transpose(int arr[][3], int rows, int cols, int transposeArr[][3])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            // swap(arr[i][j], arr[j][i]); -> won't work because the element would be swapped twice,......once (desired) but once again(bringing the elements to the same initial position)
            transposeArr[j][i] = arr[i][j];
        }
    }
}

void prinArray(int arr[][3], int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3];
    int rows = 3;
    int cols = 3;
    cout<<"Taking input: "<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Printing the matrix: "<<endl;
    prinArray(arr, rows, cols);

    int transposeArr[3][3];
    transpose(arr, rows, cols, transposeArr);

    cout<<"Printing the transpose: "<<endl;
    prinArray(transposeArr, rows, cols);

    return 0;
}