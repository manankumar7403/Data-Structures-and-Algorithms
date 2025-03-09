//⭐⭐ VERY IMPORTANT GFG QUESTION ⭐⭐
// 🔴🔴 Fermat's little theorem 🔴🔴 -> https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
/*
Geek wants you to evaluate (1 + A + A^2 + A^3 + ......+ A^K) (mod 10^9 + 7), where A, K are given.

Example 1:
Input:
A = 2, K = 2
Output:
7
Explaination:
=> (1 + A + A^2 + .....+ A^K)
=> (1 + 2 + 2^2)
=> (1 + 2 + 4)
=> 7 mod (10^9 + 7) => 7

Example 2:
Input:
A = 347148, K = 41171001
Output:
859147462

Constraints:
1 <= A, K <= 10^9
*/

#include<iostream>
using namespace std;

long long pow(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return result;
}

long long evaluateA(long long A, long long K)
{
    long long MOD = 1000000007;
    long long numerator = (1 - pow(A, K + 1, MOD)) % MOD;
    long long denominator = (1 - A) % MOD;
    long long result = (numerator * pow(denominator, MOD - 2, MOD)) % MOD;
    return result;
}

int main()
{
    long long A, K;
    cin >> A >> K;
    cout << "Geek's Equation result: " << evaluateA(A, K) << endl;
    return 0;
}

/*
The calculation of the numerator and denominator is a key step in the formula used to solve this problem.

The original expression that we need to evaluate is:
(1 + A + A^2 + A^3 + ... + A^K) (mod 10^9 + 7)

We can rewrite this as:
S = 1 + A + A^2 + A^3 + ... + A^K   -(1)

Multiplying both sides by A, we get:
A * S = A + A^2 + A^3 + ... + A^K + A^(K+1)  -(2)

Subtracting (2) from (1), we get:
S - A * S = 1 - A^(K+1)

Simplifying, we get:
S = (1 - A^(K+1)) / (1 - A)

This is the formula that we use to calculate the final result.

The numerator is (1 - A^(K+1)), and the denominator is (1 - A).

We calculate these values separately because they can become very large, and we need to perform the modular arithmetic to
keep the values within the range of the data type (long long).
By calculating the numerator and denominator separately, we can avoid intermediate overflow issues and compute the final
result correctly modulo 10^9 + 7.
The modular inverse of the denominator is also calculated to simplify the final expression and perform the division
efficiently.
So, the calculation of the numerator and denominator is an essential step in the overall solution to this problem.


Input:
- A = 2
- K = 2

Step 1: Calculate the numerator
Numerator = (1 - A^(K+1)) % MOD
Numerator = (1 - 2^(2+1)) % 1000000007
Numerator = (1 - 8) % 1000000007
Numerator = -7 % 1000000007
Numerator = 1000000000

Step 2: Calculate the denominator
Denominator = (1 - A) % MOD
Denominator = (1 - 2) % 1000000007
Denominator = -1 % 1000000007
Denominator = 1000000006

Step 3: Calculate the modular inverse of the denominator
We use the Fermat's Little Theorem to calculate the modular inverse.
Modular inverse of x = x^(MOD-2) (mod MOD)
Modular inverse of Denominator = 1000000006^(1000000005) (mod 1000000007)

Step 4: Calculate the final result
Final result = (Numerator * Modular inverse of Denominator) % MOD
Final result = (1000000000 * 1000000006^(1000000005)) % 1000000007
Final result = 7

Therefore, the final output is 7.

The key steps are:
1. Calculate the numerator using the formula (1 - A^(K+1)).
2. Calculate the denominator using the formula (1 - A).
3. Calculate the modular inverse of the denominator using Fermat's Little Theorem.
4. Multiply the numerator and the modular inverse of the denominator, and take the result modulo 1000000007.

This approach ensures that the intermediate calculations do not overflow the long long data type, and the final result is
calculated correctly.
*/