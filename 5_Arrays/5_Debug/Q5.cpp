// Q5. This code attempts to rotate a matrix by 90 degrees. Debug it.
// #include <iostream>
// #include <vector>

// using namespace std;

// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i + j < n) {
//                 swap(matrix[i][j], matrix[n - i - j - 1][n - j - 1]);
//             }
//         }
//     }
// }

// int main() {
//     vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     rotate(matrix);

//     for (int i = 0; i < matrix.size(); i++) {
//         for (int j = 0; j < matrix.size(); j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();                 // here, size=3
    for (int i = 0; i < n / 2; i++) { // Fix 1: Only rotate the first half of rows
        for (int j = i; j < n - i - 1; j++) { // Fix 2: Update the column loop to n-i-1
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}