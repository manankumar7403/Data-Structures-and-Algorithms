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
#include <vector>
using namespace std;

int countPrimes(int n)
{
    if(n == 0)
    {
        return 0;
    }
    vector<bool>prime(n, true);  // all are prime marked initially
    prime[0] = prime[1] = false;   // since 0 and 1 are non-prime numbers
    int count = 0;
    for(int i=2; i<n; i++)
    {
        if(prime[i])
        {
            count++;
            int j = 2*i;
            while(j < n)
            {
                prime[j] = false;
                j = j + i;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout  << "Enter a number: " << endl;
    cin >> n;
    cout << "There are " << countPrimes(n) << " prime numbers strictly less than " << n <<".";
    cout << endl;
    return 0;
}

// T.C. -> O(n * log(logn))
// S.c. -> O(n)