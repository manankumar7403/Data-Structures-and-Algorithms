// 🔴🔴🔴🔴 LEETCODE 279 -> Perfect Squares 🔴🔴🔴🔴
// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some
// integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Example 2:
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// Constraints:
// 1 <= n <= 10^4
// ________________________________________________________________________________________________

#include <iostream>
#include <cmath>
using namespace std;

int numSquareHelper(int n)
{
    // Base condition
    if (n == 0)
        return 1;
    if (n < 0)
        return 0; // can't find the perfect square as it does not exist for this num. Say for n=12, we comes across i=3, so perfectSquare = 9 => 12-9=3....now 3-9 = -6....so we need to return 0.

    int ans = INT_MAX; // COZ we want least number of perfect squares.
    int i = 1;
    int end = sqrt(n);
    while (i <= end) // say for 12 we only have to check till sqrt(12)=3....3*3=9<=12 but 4*4=16>=12
    {
        int perfectSquare = i * i;
        int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
        if (numberOfPerfectSquares < ans)
        {
            ans = numberOfPerfectSquares; // if condition gives the least number of perfect square numbers that sum upto n.
        }
        i++;
    }
    return ans;
}

int numSquares(int n)
{
    return numSquareHelper(n) - 1; // becuase for every number we get +1 -> example number is 5 so for 5 we
                                   // get 5-1=4 => 4-1=3 => 3-1=2 => 2-1=1 => 1-1=0.........now at 0 we return 1
                                   // at one we return 1+1=2...at 2 we get 2+1=3...at 3 we get 3+1=4...at 4 we get
                                   // 4+1=5...and at last at 5 we get 5+1=6...so we do -1 to make it 5. This is the
                                   // case if we want to make 5(or any other number) from perfect square 1.
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "Least num of perfect squares: " << numSquares(n) << endl;
    return 0;
}

// TC -> sqrt(n)^n => O(n^n) //In fibonacci,we make 2 calls for every case(2 divisions for every case)...TC = O(2^n)
//  Here, we take out root of n and thats how many calls we make(sqrt(n) divisions for every case) so => (sqrt(n)^n) => O(n^n)

// SC -> (n+1) => O(n)

// So, we get TLE Error -> will solve this later using DP instead of Recursion
// _________________________________________________
