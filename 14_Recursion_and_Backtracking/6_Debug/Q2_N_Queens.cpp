// // Q2. Debug the code -> ⭐⭐⭐⭐ N Queens ⭐⭐⭐⭐

// 		bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
//         for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
//             if(nQueens[i][j] == 'Q'){
//                 return false;
//             }
//         }
//         for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
//             if(nQueens[i][j] == 'Q'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row){
//         if(row == n){
//             output.push_back(nQueens);
//             return;
//         }
//         for(int col=0; col<n; col++){
//             if(isSafePlace(n, nQueens, row, col)){
//                 nQueens[row][col] = 'Q';
//                 solveNQueens(n, output, nQueens, row+1);
//             }
//         }
//     }
// 		vector<vector<string>> solve(int n) {
//         vector<vector<string>> output;
//         vector<string> nQueens(n , string(n, '.'));
//         solveNQueens(n, output, nQueens, 0);
//         return output;
//     }
// _____________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

bool isSafePlace(int n, vector<string> &nQueens, int row, int col)
{
    for (int i = 0; i < n; i++)
    { // Necessary Check to check if queen is safe to place or not.
        if (nQueens[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (nQueens[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (nQueens[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, vector<vector<string>> &output, vector<string> &nQueens, int row)
{
    if (row == n)
    {
        output.push_back(nQueens);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafePlace(n, nQueens, row, col))
        {
            nQueens[row][col] = 'Q';
            solveNQueens(n, output, nQueens, row + 1);
            nQueens[row][col] = '.'; // Fix: Revert back if solution is not found
        }
    }
}
vector<vector<string>> solve(int n)
{
    vector<vector<string>> output;
    vector<string> nQueens(n, string(n, '.'));
    solveNQueens(n, output, nQueens, 0);
    return output;
}

int main()
{
    int n;
    cout << "Enter the value of n for N-Queens problem: ";
    cin >> n;

    vector<vector<string>> solutions = solve(n);

    cout << "Solutions for N-Queens problem with n = " << n << ":\n";
    for (const auto &solution : solutions)
    {
        for (const string &row : solution)
        {
            cout << row << '\n';
        }
        cout << "-----------------\n";
    }

    return 0;
}

// TC -> O(N!)
// SC -> O(N^2)