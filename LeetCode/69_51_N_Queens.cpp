// 🔴🔴🔴🔴 LEETCODE 51 -> N Queens 🔴🔴🔴🔴
// Refer 16_DnC_Level4 -> Optimized N Queens
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens
attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in
any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
1 <= n <= 9
*/
// _________________________________________________________________________________________________

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans)
{
    vector<string> temp;
    for (int i = 0; i < n; i++)
    {
        string output = "";
        for (int j = 0; j < n; j++)
        {
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    if (rowCheck[row] == true) // yaani queen padi hai left row me, kaat degi, mat rakho waha queen
        return false;
    if (upperLeftDiagonalCheck[n + 1 + col - row] == true) // yaani queen padi hai upper left diagonal me, kaat degi
        return false;
    if (bottomLeftDiagonalCheck[row + col] == true) // yaani queen padi hai bottom left diagonal me, kaat degi
        return false;
    return true;

    // bas left row, upper left diagonal aur bottom left diagonal check karne hai ki yaha se koi queen kaat
    // toh nahi degi, bas left me check karenge kyuki queen jaha place karni hai uski safe position check kar
    // rahe hai, toh obviosuly right me toh abhi tak koi queen place nhi hui hai.
    // bas horziontal(left row) aur diagonal check karo coz hum col wise traverse karte hai and ek col me ek
    // queen dalte hai toh vertcially check karne ki zarurat nahi hai
}

void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans)
{
    // Base Case
    if (col >= n) // agar koisa column na bache matlab solution mil gya hai
    {
        storeSolution(board, n, ans); // agar saari queens place kardi toh solution print kardo
        return;
    }

    // 1 case solve karna hai baaki recursion sambhal lega
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n)) // for loop me hai, pehle col=0 ke liye saari rows me dekhenge queen place karke, then col=1 ke liye saari rows me ....till col=3
        {
            // toh rakh de bhai
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n + 1 + col - row] = true;
            bottomLeftDiagonalCheck[row + col] = true;

            // recursion baaki check karega
            solve(board, col + 1, n, ans);

            // Backtracking -> jaha queen rakhi thi waha se hatao -> other possible sol check karne ke liye
            board[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n + 1 + col - row] = false;
            bottomLeftDiagonalCheck[row + col] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.')); // 2-d vector -> nxn chess board
    vector<vector<string>> ans;
    int col = 0;
    // . -> empty cell
    // Q -> Queen at the cell
    solve(board, col, n, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

// TC -> number of recursive calls is by O(n!), where n is the size of the chessboard (number of columns).
// SC -> The chessboard is represented by a 2D vector of size n x n, resulting in O(n^2) space.