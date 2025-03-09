// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in
// spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// They are in a spiral like
// 1 2 3
// 8 9 4
// 7 6 5
// BASICALLY THE ELEMENTS ARE INSERTED IN A SPIRAL 1->2->3->4->5->6->7->8->9 BUT ARE PRINTED IN 3x3
// LIKE [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int total_elements = n * n;
    int startingRow = 0;
    int endingCol = n - 1;
    int endingRow = n - 1;
    int startingCol = 0;
    int count = 1;
    while (count <= total_elements)
    {
        // printing starting row
        for (int i = startingCol; i <= endingCol && count <= total_elements; i++)
        {
            ans[startingRow][i] = count;
            count++;
        }
        startingRow++;

        // printing ending col
        for (int i = startingRow; i <= endingRow && count <= total_elements; i++)
        {
            ans[i][endingCol] = count;
            count++;
        }
        endingCol--;

        // printing ending row
        for (int i = endingCol; i >= startingCol && count <= total_elements; i--)
        {
            ans[endingRow][i] = count;
            count++;
        }
        endingRow--;

        // printing starting col
        for (int i = endingRow; i >= startingRow && count <= total_elements; i--)
        {
            ans[i][startingCol] = count;
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the square matrix: " << endl;
    cin >> n;
    vector<vector<int>> result = generateMatrix(n);

    for (vector<int> row : result)
    {
        for (int element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}