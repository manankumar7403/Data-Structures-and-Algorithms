// You are given an m x n integer matrix matrix with the following two properties:
// 1) Each row is sorted in non-decreasing order.
// 2) The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0;
    int end = m * n - 1;
    int mid = start + (end - start) / 2;
    // all these calculated by visualizing them like a 1-D array formula c*i+j and then rowIndex and colIndex are derived

    while (start <= end)
    {
        int rowIndex = mid / n;
        int colIndex = mid % n;
        if (matrix[rowIndex][colIndex] == target)
        {
            return true;
        }
        else if (matrix[rowIndex][colIndex] < target)
        {
            // search right
            start = mid + 1;
        }
        else
        {
            // search left
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int m, n;
    cout << "Enter the number of rows: " << endl;
    cin >> m;
    cout << "Enter the number of columns: " << endl;
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements: " << endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target value: " << endl;
    cin >> target;

    bool result = searchMatrix(matrix, target);

    if(result)
    {
        cout << "Target found in the matrix." << endl;
    }
    else
    {
        cout << "Target not found in the matrix." << endl;
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

// LOOK UP 4_2dMatrixBinarySearch.cpp in 7_Searching_Sorting class 2