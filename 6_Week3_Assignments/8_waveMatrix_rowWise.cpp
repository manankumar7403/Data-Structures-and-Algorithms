// This is row-wise wave form
#include <iostream>
#include <vector>
using namespace std;

void wavePrintMatrix(vector<vector<int>>v)
{
    int row = v.size();
    int col = v[0].size();
    for(int startRow=0; startRow<row; startRow++)
    {
        // even num of rows -> left to right
        if((startRow & 1) == 0)
        {
            for(int i=0; i<col; i++)
            {
                cout << v[startRow][i] << " ";
            }
        }
        else
        {
            // odd num of rows -> right to left
            for(int i=col-1; i>=0; i--)
            {
                cout << v[startRow][i] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    wavePrintMatrix(v);
    return 0;
}