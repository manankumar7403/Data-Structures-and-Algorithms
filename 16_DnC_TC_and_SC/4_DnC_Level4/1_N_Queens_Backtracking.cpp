#include <iostream>
#include <vector>
using namespace std;

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
    // check karna chahte hai ki kya main current cell([row][col]) par queen rakh sakta hu ki nahi
    int i=row;
    int j=col;

    // bas left row, upper left diagonal aur bottom left diagonal check karne hai ki yaha se koi queen kaat
    // toh nahi degi, bas left me check karenge kyuki queen jaha place karni hai uski safe position check kar
    // rahe hai, toh obviosuly right me toh abhi tak koi queen place nhi hui hai.
    // bas horziontal(left row) aur diagonal check karo kyuki hum col wise traverse karte hai and ek col me ek hi
    // queen dalte hai toh vertcially check karne ki zarurat nahi hai

    // check left row
    while(j >= 0)
    {
        if(board[i][j] == 'Q')   // queen padi hai, kaat degi, mat rakho
        {
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i=row;
    j=col;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // check bottom left diagonal
    i=row;
    j=col;
    while(i < n && j >= 0)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    // matlab left me aisi kisi jagah queen nhi mili jo hame kaat de, yaani ye position safe hai
    return true;
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

            // recursion baaki check karega
            solve(board, col+1, n);

            // Backtracking -> jaha queen rakhi thi waha se hatao -> other possible sol check karne ke liye
            board[row][col] = '.';
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
   - In the worst case, the algorithm needs to explore all possible configurations of placing queens on the
     board to find all solutions.
   - The time complexity is generally expressed in terms of the number of recursive calls made during the
     backtracking process.
   - The number of recursive calls can be exponential in the input size (n), but it is generally less than n!
     (factorial) due to pruning using the isSafe function.
   - The worst-case time complexity is O(n!) since there are n columns, and for each column, we try n rows.

2. **Space Complexity:**
   - The space complexity is primarily determined by the space required for the chessboard representation and
     the recursive call stack.
   - The chessboard is represented by a 2D vector of size n x n, resulting in O(n^2) space.
   - The recursive call stack can go up to the depth of the recursion tree, which is equal to the number of
     columns (n).
   - Therefore, the overall space complexity is O(n^2 + n) = O(n^2).

It's important to note that the actual runtime and memory usage may vary based on the specific implementation
and the pruning techniques used to reduce the search space. Backtracking algorithms often benefit from pruning,
which helps avoid unnecessary exploration of certain paths.
*/