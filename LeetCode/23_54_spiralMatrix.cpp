// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1
// Input: matrix = [[1,2,3],
//                  [4,5,6],
//                  [7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2
// Input: matrix = [[1,2,3,4],
//                  [5,6,7,8],
//                  [9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    int total_elements = m * n;
    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = m - 1;
    int startingCol = 0;
    int count = 0;
    while (count < total_elements)
    {
        // printing starting row
        for (int i = startingCol; i <= endingCol && count < total_elements; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // printing ending col
        for (int i = startingRow; i <= endingRow && count < total_elements; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // printing ending row
        for (int i = endingCol; i >= startingCol && count < total_elements; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // printing starting col
        for (int i = endingRow; i >= startingRow && count < total_elements; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    int r, c;
    cout << "Enter the number of rows: " << endl;
    cin >> r;
    cout << "Enter the number of cols: " << endl;
    cin >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter the elements in the vector arr: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    vector<int> result = spiralOrder(matrix);

    for (int j : result)
    {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}