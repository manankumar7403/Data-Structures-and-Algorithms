// 🔴🔴LEETCODE 1878 -> Get Biggest 3 Rhombus Sums in a Grid🔴🔴
/*
You are given an m x n integer matrix grid​​​.
A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have
the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four
valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three
distinct values, return all of them.

Example 1:
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211

Example 2:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)

Example 3:
Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 10^5
*/
// ________________________________________________________________________________________________________
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkBounds(vector<vector<int>> &grid, vector<pair<int, int>> &v)
{
    int m = grid.size();
    int n = grid[0].size();
    for (auto pt : v)
    {
        if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n)
        {
            return false;
        }
    }
    return true;
}

bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, pair<int, int> c, int &delta) // c->center, v->vertice
{
    pair<int, int> A(c.first - delta, c.second);
    pair<int, int> B(c.first, c.second + delta);
    pair<int, int> C(c.first + delta, c.second);
    pair<int, int> D(c.first, c.second - delta);
    // We took out all the vertices(coordinates) and now we are pushing them into the vector v
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;
    if (checkBounds(grid, v))
        return true;
    return false;
}

void getAllSum(vector<vector<int>> &grid, int &cx, int &cy, priority_queue<int> &pq)
{
    // push rhombus sum of rhombus with area 0
    pq.push(grid[cx][cy]);
    int delta = 1;
    vector<pair<int, int>> v(4);
    while (getAllVertices(grid, v, {cx, cy}, delta))
    {
        pair<int, int> &A = v[0];
        pair<int, int> &B = v[1];
        pair<int, int> &C = v[2];
        pair<int, int> &D = v[3];

        int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        // all cells b/w AB
        for (int i = 1; i < (B.first - A.first); i++)
        {
            csum = csum + grid[A.first + i][A.second + i];
        }
        // all cells b/w BC
        for (int i = 1; i < (C.first - B.first); i++)
        {
            csum = csum + grid[B.first + i][B.second - i];
        }
        // all cells b/w CD
        for (int i = 1; i < (C.first - D.first); i++)
        {
            csum = csum + grid[C.first - i][C.second - i];
        }
        // all cells b/w DA
        for (int i = 1; i < (D.first - A.first); i++)
        {
            csum = csum + grid[D.first - i][D.second + i];
        }

        pq.push(csum); // Rhombus sum has been pushed
        delta++;
    }
}

bool canPush(vector<int> &ans, int &top)
{
    for (auto val : ans)
    {
        if (val == top)
        {
            return false;
        }
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    vector<int> ans;
    priority_queue<int> pq; // set can be used as well
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, pq);
        }
    }
    while (!pq.empty() && ans.size() < 3)
    {
        int top = pq.top();
        pq.pop();
        if (canPush(ans, top)) // writing a function to check if the sum is distinct
        {
            ans.push_back(top);
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows: " << endl;
    cin >> n;
    cout << "Enter the number of columns: " << endl;
    cin >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<int> ans = getBiggestThree(grid);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

// TC -> O(n*m*max(n,m))
// SC -> O(k) -> where k is the distinct pair of sums