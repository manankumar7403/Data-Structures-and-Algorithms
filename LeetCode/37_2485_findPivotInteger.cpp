// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n
// inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will
// be at most one pivot index for the given input.

// Example 1:
// Input: n = 8
// Output: 6
// Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

// Example 2:
// Input: n = 1
// Output: 1
// Explanation: 1 is the pivot integer since: 1 = 1.

// Example 3:
// Input: n = 4
// Output: -1
// Explanation: It can be proved that no such integer exist.

// Constraints:
// 1 <= n <= 1000

#include <iostream>
using namespace std;

int pivotInteger(int n)
{
    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        totalSum = totalSum + i;
    }

    int left = 0;
    int right = totalSum;
    for (int i = 1; i <= n; i++)
    {
        right = right - i;
        if (left != right)
        {
            left = left + i;
        }
        else
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter an integer: " << endl;
    cin >> n;
    cout << "The pivot integer is: " << pivotInteger(n) << endl;
    return 0;
}

// T.C. -> O(N)
// S.C. -> O(1)

// ________________________________________________________________________________________________

// Explanation: n = 8      output = 6

// totalSum = 0;
// for i = 1 to n = 8

// totalSum = totalSum + i -> 1+2+3+4+5+6+7+8 = 36

// left = 0
// right = totalSum = 36

// for i = 1 to n = 8

// 1) i = 1
// right = right - i => right = 36-1 = 35
// left != right => 0 != 35
// left = left + i => left = 0+1 = 1

// 2) i = 2
// right = right - i => right = 35-2 = 33
// left != right => 1 != 33
// left = left + i => left = 1+2 = 3

// 3) i = 3
// right = right - i => right = 33-3 = 30
// left != right => 3 != 30
// left = left + i => left = 3+3 = 6

// 4) i = 4
// right = right - i => right = 30-4 = 26
// left != right => 6 != 26
// left = left + i => left = 6+4 = 10

// 5) i = 5
// right = right - i => right = 26-5 = 21
// left != right => 10 != 21
// left = left + i => left = 10+5 = 15

// 6) i = 6
// right = right - i => right = 21-6 = 15
// left != right => 15 == 35

// return i => returns 6

// Basically we initialized left = 0 and right = totalSum
// Now we keep on increasing left sum and decrease right sum simultaneously and equally
// so, we keep on comparing left sum and right sum and will eventually reach a point where
// left sum = right sum and will end there (return i).
