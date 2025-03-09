// Question: Count the number of primes less than n.
// 🔴🔴🔴🔴 LEETCODE 204 -> Count Primes 🔴🔴🔴🔴
// Given an integer n, return the number of prime numbers that are strictly less than n.
// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Example 2:
// Input: n = 0
// Output: 0

// Example 3:
// Input: n = 1
// Output: 0

// Constraints:
// 0 <= n <= 5 * 10^6
// _________________________________________________________________________________________

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }
    for(int i=2; i<n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(isPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << countPrimes(n);
    cout << endl;
    return 0;
}

// T.C. -> O(n^2)
// S.C. -> O(1)
