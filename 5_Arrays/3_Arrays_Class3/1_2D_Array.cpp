/*
#include <iostream>
using namespace std;
int main()
{
    // Declare 2D Array
    int arr[3][3];             // [row][column]

    // Initialization
    int brr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << brr[2][2] << endl;     // prints 9
    cout << brr[1][3] << endl;     // prints 7 -> not advisable could give segment, out of bound error in some compilers
    cout << brr[1][5] << endl;     // prints 9 -> not advisable could give segment, out of bound error in some compilers
    cout << brr[2][4] << endl;     // prints garbage value -> not advisable could give segment, out of bound error in some compilers
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // row-wise print
    cout<<"Printing row-wise: "<<endl;
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // column-wise print
    cout<<"Printing column-wise: "<<endl;
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/


// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[3][3];
//     int rows=3;
//     int cols=3;

//     // row-wise input
//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     cout<<"Printing row-wise"<<endl;
//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout<<endl;
//     }
// }

#include <iostream>
using namespace std;
int main()
{
    int arr[3][3];
    int rows=3;
    int cols=3;

    // column-wise input
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> arr[j][i];
        }
    }

    cout<<"Printing column-wise"<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << arr[i][j] << " ";    // since we have taken input as arr[j][i] instead of arr[i][j], no need to print reverse now, just print the column values as it is.
        }
        cout<<endl;
    }
}


// The values in 2-D array are stored like 1-D array only, just for visualization we assume a grid
// representation. Then how does the compiler locate the value with indexing of any element in 2-D array?
// r -> number of rows
// c -> number of cols
// i -> current row in loop
// j -> current col in loop
// The formula used to locate the element using indexing in a 2-D array is
// c*i+j

// Also, when you pass an array row and cols, say in a function like,
// printArray(int arr[][3], int rows, int cols)
// You can only leave the first bracket(row) empty but need to fill all the other brackets(cols)
// so that the element location is specified using indexing.
// NOTE: Forumla used is c*i+j, so we need c, i, and j only. r could be empty.