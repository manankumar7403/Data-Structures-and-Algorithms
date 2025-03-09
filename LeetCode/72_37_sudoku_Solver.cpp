// 🔴🔴🔴🔴 LEETCODE 37 -> LeetCode Solver 🔴🔴🔴🔴
// Refer 16_DnC_ DnC_Level_6 -> Sudoku Solver Backtracking
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:

1) Each of the digits 1-9 must occur exactly once in each row.
2) Each of the digits 1-9 must occur exactly once in each column.
3) Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Input:
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/
// _________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(char value, vector<vector<char>> &board, int curr_row, int curr_col)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[curr_row][i] == value)
            return false;

        // column check
        if (board[i][curr_col] == value)
            return false;

        // 3*3 box check
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == value)
            return false;
    }
    // upar ki 3 conditions me nahi atke yaani rakhna safe hai
    return true;
}

// This function returns true or false, basis on whether we found a solution or not
bool solve(vector<vector<char>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check for empty cell
            if (board[i][j] == '.')
            {
                // is empty, so we check to fill it from values ranging from 1 to 9
                for (char value = '1'; value <= '9'; value++)
                {
                    // Check for safety
                    if (isSafe(value, board, i, j))
                    {
                        // insert
                        board[i][j] = value;

                        // baaki recursion sambhal lega
                        bool aageKaSolution = solve(board);
                        if (aageKaSolution == true) // 1 sol ke milte hi return true, don't search for multiple sol
                        {
                            return true;
                        }
                        else
                        {
                            // Backtracking
                            board[i][j] = '.';
                        }
                    }
                }
                return false; // 1 se 9 tak koi val nhi dal sakti current cell par, so return false and go back kyuki piche kahi par galti hai
            }
        }
    }
    // all cells filled
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    cout << "Sudoku Solution:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
### Time Complexity:
The time complexity is determined by the number of recursive calls and the work done in each call.
In the worst case, the function explores all possible combinations of numbers for each empty cell in the
Sudoku grid.

Let n be the number of rows or columns in the Sudoku grid (which is typically 9 for a standard Sudoku).
In each empty cell, the function tries values from 1 to 9, so the time complexity is O(9^n). This is because
for each empty cell, the function potentially explores 9 possibilities, and there are (n^2) cells in total.

### Space Complexity:
The space complexity is influenced by the space required for the recursion stack.

1. **Recursion Stack:**
   - The maximum depth of the recursion stack is (n^2) since each recursive call corresponds to processing
     one cell in the (n x n) Sudoku grid.
   - Therefore, the space complexity due to the recursion stack is O(n^2).

### Summary:
- Time Complexity: O(9^n)
- Space Complexity: O(n^2)

It's important to note that the exact time complexity can vary depending on the Sudoku instance.
In practice, the algorithm often performs much better than the worst-case time complexity suggests,
as it uses backtracking to efficiently explore the solution space. The space complexity is reasonable and
depends on the size of the Sudoku grid.
*/