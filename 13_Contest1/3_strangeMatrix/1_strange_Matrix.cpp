/*
🔴🔴🔴🔴 IMPORTANT QUESTION 🔴🔴🔴🔴
https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/

Matrix[][] is a (r x c) boolean matrix such that each of its element is either 0 or 1. Each row of the matrix is sorted.
Find the index of the row which has the maximum number of ones. If there are multiple such rows then return the smallest
index.
An array zerosInRow[] of size r is used to construct matrix Matrix such that zerosInRow[i] denotes the number of zeroes in
the ith row.

Example 1:
INPUT:
r=3, c=3
zerosInRow[] = {1,0,2}

OUTPUT: 1

Explanation:
Matrix[][] = [[0,1,1], [1,1,1], [0,0,1]]
Row with index 1 has maximum number of 1s.

Expected Time Complexity: O(r+c)
Expected Space Auxiliary: O(1)

Constraints:
1 <= r,c <= 10^5

Sample i/o
{{0, 0, 0, 1},
{0, 1, 1, 1},
{1, 1, 1, 1},
{0, 0, 0, 0}};
3 1 0 4
o/p is 2

*/


// ____________________________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rowAndMaximumOnes(int r, int c, vector<int> &zerosInRow)
{
    int rowWithMaxOnes = -1;
    int maxOnes = -1;

    for (int i = 0; i < r; ++i)
    {
        int onesCount = c - zerosInRow[i]; // Since zerosInRow[i] gives number of zeros, we can get number of ones
        if (onesCount > maxOnes)
        {
            maxOnes = onesCount;
            rowWithMaxOnes = i;
        }
    }

    return rowWithMaxOnes;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    vector<int> mat(rows);
    cout << "Enter the number of zeros in each row: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cin >> mat[i];
    }
    cout << "Row index with max ones: " << rowAndMaximumOnes(rows, cols, mat) << endl;
    return 0;
}