// Given an integer N, find its factorial. return a list of integers denoting the digits that make
// up the factorial of N.

// Example 1:
// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120

// Example 2:
// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

// Expected Time Complexity : O(N^2)
// Expected Auxilliary Space : O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N;
    cout << "Enter the value of N: " << endl;
    cin >> N;
    vector<int> result = factorial(N);

    cout << "Factorial of " << N << " is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    cout << endl;
    return 0;
}
