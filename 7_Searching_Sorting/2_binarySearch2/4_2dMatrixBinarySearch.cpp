#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int target)
{
    int start = 0;
    int end = rows*cols-1;
    int mid = start + (end-start)/2;
    // all these calculated by visualizing them like a 1-D array formula c*i+j and then rowIndex and colIndex are derived
    
    while(start <= end)
    {
        int rowIndex = mid/cols;
        int colIndex = mid%cols;
        
        if(arr[rowIndex][colIndex] == target)
        {
            cout << "Found at " << rowIndex << " " << colIndex << endl;   
            return true;
        }
        else if(arr[rowIndex][colIndex] < target)
        {
            // search right
            start = mid + 1;
        }
        else
        {
            // search left
            end = mid -1 ;
        }
        mid = start + (end-start)/2;
    }
    return false;
}

int main()
{
    int arr[5][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};
    int rows = 5;
    int cols = 4;
    
    int target = 19;
    bool ans = binarySearch(arr, rows, cols, target);
    if(ans)
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }
    
    return 0;
}

// Even a 2-D matrix is stored like a normal matrix at a particular location where the index of the 2-D matrix
// equals c*i+j
// c*i+j
// here, c = number of columns
//       i = row index
//       j = column index

// Now, here we have the c*i+j index and we need to get the rowIndex and the colIndex
// rowIndex i = x / c
// colIndex j = x % c
// x is the 1-D index