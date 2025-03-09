// ⭐⭐LEETCODE 1691 -> Maximum Height By Stacking Cuboids⭐⭐
/*
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed).
Choose a subset of cuboids and place them on each other.
You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any
cuboid's dimensions by rotating it to put it on another cuboid.
Return the maximum height of the stacked cuboids.

Example 1:
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

Example 3:
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 
Constraints:
n == cuboids.length
1 <= n <= 100
1 <= widthi, lengthi, heighti <= 100
*/

// _______________________________________________________________________________________________________________________

/*
// 🔴🔴RECURSION🔴🔴
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingRecursion(vector<vector<int>> &cuboids, int curr, int prev)
{
    // Base condition
    if (curr >= cuboids.size())
        return 0;

    // include
    int include = 0;
    if (prev == -1 || (cuboids[prev][0] <= cuboids[curr][0] && cuboids[prev][1] <= cuboids[curr][1] && cuboids[prev][2] <= cuboids[curr][2]))
    {
        include = cuboids[curr][2] + solveUsingRecursion(cuboids, curr + 1, curr);
    }
    // exclude
    int exclude = 0 + solveUsingRecursion(cuboids, curr + 1, prev);

    int ans = max(include, exclude);
    return ans;
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort the 2d array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    int curr = 0;  // curr index
    int prev = -1; // prev index
    int ans = solveUsingRecursion(cuboids, curr, prev);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    vector<vector<int>>cuboids(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<cuboids.size(); i++)
    {
        for(int j=0; j<cuboids[i].size(); j++)
        {
            cin >> cuboids[i][j];
        }
    }

    int ans = maxHeight(cuboids);
    cout << "Max Height by stacking the cuboids is: " << ans << endl;
    return 0;
}
*/
// ___________________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION (Top-Down)🔴🔴
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingMem(vector<vector<int>> &cuboids, int curr, int prev, vector<vector<int>> &dp)
{
    // Base condition
    if (curr >= cuboids.size())
        return 0;

    // Step2: Check if the answer is already present inside the array
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int include = 0;
    if (prev == -1 || (cuboids[prev][0] <= cuboids[curr][0] && cuboids[prev][1] <= cuboids[curr][1] && cuboids[prev][2] <= cuboids[curr][2]))
    {
        include = cuboids[curr][2] + solveUsingMem(cuboids, curr + 1, curr, dp);
    }
    // exclude
    int exclude = 0 + solveUsingMem(cuboids, curr + 1, prev, dp);

    // Step3: Store the answer in dp array
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort the 2d array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    int curr = 0;  // curr index
    int prev = -1; // prev index
    int n = cuboids.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = solveUsingMem(cuboids, curr, prev, dp);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    vector<vector<int>>cuboids(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<cuboids.size(); i++)
    {
        for(int j=0; j<cuboids[i].size(); j++)
        {
            cin >> cuboids[i][j];
        }
    }

    int ans = maxHeight(cuboids);
    cout << "Max Height by stacking the cuboids is: " << ans << endl;
    return 0;
}
*/

// ___________________________________________________________________________________________________________________

/*
// 🔴🔴TABULATION (Bottom-Up)🔴🔴
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingTab(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    // Step1: Create a dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= envelopes.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || (cuboids[prev][0] <= cuboids[curr][0] && cuboids[prev][1] <= cuboids[curr][1] && cuboids[prev][2] <= cuboids[curr][2]))
            {
                include = cuboids[curr][2] + dp[curr + 1][curr + 1];
            }
            // exclude
            int exclude = 0 + dp[curr + 1][prev + 1];

            // Store the answer in dp array
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][-1 + 1];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort the 2d array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    int ans = solveUsingTab(cuboids);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    vector<vector<int>>cuboids(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<cuboids.size(); i++)
    {
        for(int j=0; j<cuboids[i].size(); j++)
        {
            cin >> cuboids[i][j];
        }
    }

    int ans = maxHeight(cuboids);
    cout << "Max Height by stacking the cuboids is: " << ans << endl;
    return 0;
}
*/

// _________________________________________________________________________________________________________________

// 🔴🔴Space Optimization🔴🔴
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveUsingSO(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    // doing prev+1 everywhere as prev=-1 is a negative index that will give error so prev=-1+1=0, which is valid index
    // Step2: Check the Base condition -> dp array already init with 0 so no need of this
    // if(curr >= envelopes.size()) return 0;

    // Step3: Main iteration logic
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || (cuboids[prev][0] <= cuboids[curr][0] && cuboids[prev][1] <= cuboids[curr][1] && cuboids[prev][2] <= cuboids[curr][2]))
            {
                include = cuboids[curr][2] + nextRow[curr + 1];
            }
            // exclude
            int exclude = 0 + nextRow[prev + 1];

            // Store the answer in dp array
            currRow[prev + 1] = max(include, exclude);
        }
        // Shifting
        nextRow = currRow;
    }
    return currRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort the 2d array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    int ans = solveUsingSO(cuboids);
    return ans;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    cout << "Enter the number of cols: " << endl;
    cin >> cols;
    vector<vector<int>>cuboids(rows, vector<int>(cols));
    cout << "Enter the elements in the array: " << endl;
    for(int i=0; i<cuboids.size(); i++)
    {
        for(int j=0; j<cuboids[i].size(); j++)
        {
            cin >> cuboids[i][j];
        }
    }

    int ans = maxHeight(cuboids);
    cout << "Max Height by stacking the cuboids is: " << ans << endl;
    return 0;
}