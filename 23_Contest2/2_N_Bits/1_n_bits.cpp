// GFG
/*
Given a positive integer number N. The task is to generate all the binary strings of N bits.
These binary strings should be in ascending order. Note the space between two characters of the string.

Examplel:
Input:
1
Output:
0
1

Example2:
Input:
2
Output:
0 0
0 1
1 0
1 1

Constraints:
1 <= T <= 10
1 <= N <= 15
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve(int n, int arr[], int i)
{
    if (i == n)
    {
        printArray(arr, n);
        return;
    }

    // First assign "0" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 0;
    solve(n, arr, i + 1);

    // And then assign "1" at ith position
    // and try for all other permutations
    // for remaining positions
    arr[i] = 1;
    solve(n, arr, i + 1);
}

void generateAllBinaryStrings(int n)
{
    int arr[n];
    int i = 0;
    solve(n, arr, i);
}

int main()
{
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;
    cout << "The binary strings of " << n << " bits are:" << endl;
    generateAllBinaryStrings(n);
    return 0;
}