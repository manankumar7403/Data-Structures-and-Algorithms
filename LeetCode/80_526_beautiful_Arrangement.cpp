// 🔴🔴🔴🔴 LEETCODE 526 -> Beautiful Arrangement 🔴🔴🔴🔴
// Refer 17_DnC_Backtracking -> 10_beautifulArrangement -> 1_beautifulArrangement.cpp
/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is
considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
1) perm[i] is divisible by i.
2) i is divisible by perm[i].

Given an integer n, return the number of the beautiful arrangements that you can construct.

Example 1:
Input: n = 2
Output: 2
Explanation:
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 15
*/
// ______________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void countArrangementHelper(vector<int> &v, int &n, int &ans, int currNum)
{
    // Base Case
    if (currNum == n + 1) // yaani saare numbers place ho gye
    {
        cout << "Beautiful arrangement: " << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << " "; // to print the beautiful arrangement
        }
        cout << endl;

        ans++; // returns the number of beautiful arrangements.
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) // v[i] == 0 matlab waha kuch nahi pada && (currNum % i == 0 || i % currNum == 0) conditions hai jo fulfil honi chahiye waha vo element place karne ke liye
        {
            v[i] = currNum;                                 // upar conditions true hai toh, v[i] ko occupy kar liya currNum ne
            countArrangementHelper(v, n, ans, currNum + 1); // baaki number recursion rakh ke dekhega

            // Backtracking -> dusre solutions dekhne ke liye ya koi number place nahi ho paaya
            v[i] = 0;
        }
    }
}

int countArrangement(int n)
{
    vector<int> v(n + 1); // because we are doing 1-indexing
    int ans = 0;

    countArrangementHelper(v, n, ans, 1);
    
    cout << "Number of beautiful arrangements: " << endl;
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of integers: " << endl;
    cin >> n;
    cout << countArrangement(n);
    cout << endl;
    return 0;
}

// TC -> O(n!)
// SC -> O(n)