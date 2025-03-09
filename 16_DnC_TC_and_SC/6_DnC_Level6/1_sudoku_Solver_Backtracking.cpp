#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int value, int board[][9], int curr_row, int curr_col)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (board[curr_row][i] == value)
            return false;

        // column check
        if (board[i][curr_col] == value)
            return false;

        // 3*3 box check
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == value)  // check image for this logic explanation
            return false;
    }
    // upar ki 3 conditions me nahi atke yaani rakhna safe hai
    return true;
}

// This function returns true or false, basis on whether we found a solution or not
bool solve(int board[9][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check for empty cell
            if (board[i][j] == 0)
            {
                // is empty, so we check to fill it from values ranging from 1 to 9
                for (int value = 1; value <= 9; value++)
                {
                    // Check for safety
                    if (isSafe(value, board, i, j))
                    {
                        // insert
                        board[i][j] = value;

                        // baaki recursion sambhal lega
                        bool aageKaSolution = solve(board, n);  // pehle value insert kar di current position par agar safe hai toh fir baaki cells ki recursion khud value nikalega
                        if (aageKaSolution == true) // ek solution ke milte hi true return kardo, no need to search for multiple solutions
                        {
                            return true;
                        }

                        else
                        {
                            // Backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false; // 1 se 9 tak koi value nhi dal sakti toh false return kar diya kyuki piche kahi par galti hai
            }
        }
    }
    // all cells filled
    return true;
}

int main()
{
    // 0 -> represents empty cell
    int board[9][9] = {
        {4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 0, 6, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 8},
        {0, 0, 0, 9, 5, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 6, 0, 0, 7, 5, 0},
        {0, 0, 0, 0, 0, 0, 4, 7, 6},
        {0, 7, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 9, 0, 0, 0}};

    int n = 9;
    solve(board, n);

    cout << "Printing the sudoku solution: " << endl;
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
- Time Complexity: O(9^n)  // n is nxn -> total size of the board
- Space Complexity: O(n^2)

It's important to note that the exact time complexity can vary depending on the Sudoku instance.
In practice, the algorithm often performs much better than the worst-case time complexity suggests,
as it uses backtracking to efficiently explore the solution space. The space complexity is reasonable and
depends on the size of the Sudoku grid.
*/