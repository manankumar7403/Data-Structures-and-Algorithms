// Given a number N. The task is to return a string S of asterisk(*) from 1 till N terms with increasing
// order and difference being 1.

// Example 1:
// Input:
// N=3

// Output:
// * ** ***

// Explanation:
// First, add 1 asterisk then space after
// that add 2 asterisk and space after that
// add 3 asterisk now stop as N is 3.

// Example 2:
// Input:
// N=5

// Output:
// * ** *** **** *****

// Your Task:
// You don't need to read input. Your task is to complete the function printPattern() which takes an
// integer N as an input parameter and return the above pattern.

// Expected time complexity -> O(N^2)
// Expected auxiliary space -> O(1)

// Constraints: 1 <= N <= 1000
// _____________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

vector<char> printPattern(int N)
{
    vector<char> result;
    int count = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < count; j++)
        {
            result.push_back('*');
        }
        if (i != N)
        {
            result.push_back(' ');
        }
        count++;
    }
    return result;
}

int main()
{
    int N;
    cout << "Enter the value of N: " << endl;
    cin >> N;
    vector<char> result = printPattern(N);
    for(auto j: result)
    {
        cout << j;
    }
    cout << endl;
    return 0;
}
