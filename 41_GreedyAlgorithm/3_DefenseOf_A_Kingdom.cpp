//Refer: https://www.spoj.com/problems/DEFKIN/
/*
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is
represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends
all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on
the picture has penalty 12.
This position has a penalty of 12.
Help Theodore write a program that calculates the penalty of the given position.
Input
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number
of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower
(1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by
the towers.

Example
Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    int t = n;
    vector<int>rowC;
    vector<int>colC;

    rowC.push_back(0);
    colC.push_back(0);

    while(t--)
    {
        int a, b;
        cin >> a >> b;
        rowC.push_back(a);
        colC.push_back(b);
    }

    // size of 2D grid
    rowC.push_back(x+1);
    colC.push_back(y+1);

    sort(rowC.begin(), rowC.end());
    sort(colC.begin(), colC.end());

    for(auto i: rowC)
    {
        cout << i << " ";
    }
    cout << endl;

    for(auto i: colC)
    {
        cout << i << " ";
    }
    cout << endl;

    int maxLen = INT_MIN;
    for(int i=1; i<rowC.size(); i++)
    {
        int a = rowC[i-1];
        int b = rowC[i];
        maxLen = max(maxLen, b-a-1);
    }

    int maxWidth = INT_MIN;
    for(int i=1; i<colC.size(); i++)
    {
        int a = colC[i-1];
        int b = colC[i];
        maxWidth = max(maxWidth, b-a-1);
    }

    cout << "Max area: " << maxLen * maxWidth << endl;
    return 0;
}