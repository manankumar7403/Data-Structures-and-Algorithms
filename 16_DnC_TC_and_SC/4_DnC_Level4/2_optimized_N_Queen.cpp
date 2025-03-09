#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char> > &board, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char> > &board, int n)
{
    if(rowCheck[row] == true)   // yaani queen padi hai left row me, kaat degi, mat rakho waha queen
        return false;
    if(upperLeftDiagonalCheck[n+1+col-row] == true) // yaani queen padi hai upper left diagonal me, kaat degi
        return false;
    if(bottomLeftDiagonalCheck[row+col] == true)   // yaani queen padi hai bottom left diagonal me, kaat degi
        return false;

    return true;

    // bas left row, upper left diagonal aur bottom left diagonal check karne hai ki yaha se koi queen kaat
    // toh nahi degi, bas left me check karenge kyuki queen jaha place karni hai uski safe position check kar
    // rahe hai, toh obviosuly right me toh abhi tak koi queen place nhi hui hai.
    // bas horziontal(left row) aur diagonal check karo kyuki hum col wise traverse karte hai and ek col me ek hi
    // queen dalte hai toh vertcially check karne ki zarurat nahi hai
}

void solve(vector<vector<char> > &board, int col, int n)
{
    // Base Case
    if(col >= n)  // agar koisa column na bache matlab solution mil gya hai
    {
        printSolution(board, n);    // agar saari queens place kardi toh solution print kardo
        return;
    }

    // 1 case solve karna hai baaki recursion sambhal lega
    for(int row=0; row<n; row++)
    {
        if(isSafe(row, col, board, n))    // for loop me hai, pehle col=0 ke liye saari rows me dekhenge queen place karke, then col=1 ke liye saari rows me ....till col=3
        {
            // toh rakh de bhai
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n + 1 + col - row] = true;
            bottomLeftDiagonalCheck[row + col] = true;

            // recursion baaki check karega
            solve(board, col+1, n);

            // Backtracking -> jaha queen rakhi thi waha se hatao -> other possible sol check karne ke liye
            board[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n + 1 + col - row] = false;
            bottomLeftDiagonalCheck[row + col] = false;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<vector<char> > board(n, vector<char>(n, '.'));   // 2-d vector -> nxn chess board
    
    int col = 0;
    // . -> empty cell
    // Q -> Queen at the cell

    solve(board, col, n);
    return 0;
}

/*
1. **Time Complexity:**
   - The time complexity of this solution is still exponential in the worst case, but it is generally more
     efficient than the previous solution without pruning.
   - Pruning using the unordered_map reduces the number of unnecessary checks, especially for diagonal positions.
   - In the worst case, the number of recursive calls is still bounded by O(n!), where n is the size of the
     chessboard (number of columns).
   - The pruning, however, significantly reduces the number of positions that need to be checked, making the
     algorithm more efficient in practice.

2. **Space Complexity:**
   - The space complexity is determined by the space required for the chessboard representation and the
     unordered_map data structures.
   - The chessboard is represented by a 2D vector of size n x n, resulting in O(n^2) space.
   - The unordered_map instances (`rowCheck`, `upperLeftDiagonalCheck`, and `bottomLeftDiagonalCheck`)
     also contribute to space complexity. In the worst case, they can have up to n entries each,
     resulting in O(n) space complexity for each map.
   - Therefore, the overall space complexity is O(n^2 + n + n) = O(n^2).

It's important to note that the actual runtime and memory usage may still vary based on the specific
implementation and the characteristics of the input. Pruning strategies, like the one used in this solution,
are crucial for improving the practical efficiency of backtracking algorithms.
*/