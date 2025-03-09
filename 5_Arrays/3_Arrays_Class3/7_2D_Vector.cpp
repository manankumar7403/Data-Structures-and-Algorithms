/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int> > arr;

    vector<int> a{1,2,3,4,5};
    vector<int> b{6,7,8};
    vector<int> c{9,10};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    for(int i=0; i<arr.size(); i++)               // arr.size() for number of rows
    {
        for(int j=0; j<arr[i].size(); j++)        //  arr[i].size() for number of cols
        {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;

}
*/

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     int row = 3;
//     int col = 5;
//     vector<vector<int> > arr(row, vector<int>(col, 0));
//     for(int i=0; i<arr.size(); i++)
//     {
//         for(int j=0; j<arr[i].size(); j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// Prints
// 0 0 0 0 0 
// 0 0 0 0 0 
// 0 0 0 0 0 

// vector<vector<int> > arr          -> 2D array of integer
// row                               -> size of outer vector (number of rows)
// vector<int>(col, 0)               -> size of inner vector (col) initialized with 0


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row = 5;
    int col = 5;
    vector<vector<int> > arr(row, vector<int>(col, -8));
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Prints
// -8 -8 -8 -8 -8 
// -8 -8 -8 -8 -8 
// -8 -8 -8 -8 -8 
// -8 -8 -8 -8 -8 
// -8 -8 -8 -8 -8 