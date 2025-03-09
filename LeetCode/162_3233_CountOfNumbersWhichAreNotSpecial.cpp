// 🔴🔴LEETCODE 3233 -> Find the count of numbers which are not special🔴🔴
/*
You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the
proper divisors of x.
A number is called special if it has exactly 2 proper divisors. For example:
The number 4 is special because it has proper divisors 1 and 2.
The number 6 is not special because it has proper divisors 1, 2, and 3.
Return the count of numbers in the range [l, r] that are not special.

Example 1:
Input: l = 5, r = 7
Output: 3
Explanation:
There are no special numbers in the range [5, 7].

Example 2:
Input: l = 4, r = 16
Output: 11
Explanation:
The special numbers in the range [4, 16] are 4 and 9.

Constraints:
1 <= l <= r <= 10^9
*/
// ___________________________________________________________________________________________________________

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int nonSpecialCount(int l, int r)
{
    int limit = sqrt(r);
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes

    // Sieve of Eratosthenes to find all primes up to sqrt(r)
    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Find squares of primes within the range [l, r]
    vector<int> specialNumbers;
    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            int square = i * i;
            if (square >= l && square <= r)
            {
                specialNumbers.push_back(square);
            }
        }
    }

    // Total numbers in the range [l, r]
    int totalNumbers = r - l + 1;

    // Non-special numbers are total numbers minus the count of special numbers
    return totalNumbers - specialNumbers.size();
}

int main()
{
    int l,r;
    cout << "Enter the value of l: " << endl;
    cin >> l;
    cout << "Enter the value of r: " << endl;
    cin >> r;
    int ans = nonSpecialCount(l, r);
    cout << "Number of non-special characters are: " << ans << endl;
    return 0;
}

// limit = sqrt(r)
// say r = 16, sqrt(16) = 4
// Primes upto 4 are 2 and 3
// Squares of 2 and 3 are 2^2 and 3^2 = 4 and 9 respectively.
// If we didn't limit the prime search to sqrt(r), we'd check unnecessarily larger prime numbers, whose squares would
// exceed r and hence be irrelevant.

/*
Dry Run for (l=4) and (r=16)

Input:
(l=4), (r=16)

Step 1: Calculate Limit
Compute (sqrt{r}):
sqrt{16} = 4
Limit for sieve: ({limit}=4)

Step 2: Sieve of Eratosthenes
Initialize isPrime as:
isPrime = [false, false, true, true, true]  // Index 0 and 1 are not prime

Iterate from (i = 2) to ({limit} = 4):
1. For (i = 2):
   -(2) is prime.
   - Mark multiples of (2) as non-prime (4):
     isPrime = [false, false, true, true, false]

2. For (i = 3):
   -(3) is prime.
   - No multiples of (3) (within (<=4)) need marking.

Final isPrime array:
isPrime = [false, false, true, true, false]  // Primes are at indices 2 and 3

Step 3: Find Special Numbers
Iterate through primes in isPrime:
1. For (i = 2):
   - Compute square: (2^2 = 4).
   - (4 in [4, 16]), so add to specialNumbers.

2. For (i = 3):
   - Compute square: (3^2 = 9).
   - (9 in [4, 16]), so add to specialNumbers.

3. For (i = 4):
   - (4) is not prime, skip.

Special Numbers:
specialNumbers = [4, 9]
*/