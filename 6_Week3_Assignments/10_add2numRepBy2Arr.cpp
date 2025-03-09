// Given two array A[0...N-1] and B[0...M-1] of size N and M respectively, representing two numbers
// such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and B[] = { 2, 1, 4 }
// represent 123 and 214 respectively. The task is to find the sum of both the numbers.

// Example 1:
// Input : A[] = {1, 2}, B[] = {2, 1}
// Output : 33
// Explanation:
// N=2, and A[]={1,2}
// M=2, and B[]={2,1}
// Number represented by first array is 12.
// Number represented by second array is 21
// Sum=12+21=33

// Example 2:
// Input : A[] = {9, 5, 4, 9}, B[] = {2, 1, 4} 
// Output : 9763 

// Expected Time Complexity: O(N + M).
// Expected Auxiliary Space: O(N + M).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string calc_Sum(vector<int>& a, int n, vector<int>& b, int m)
{
    int carry = 0;
    string ans;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0)
    {
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--, j--;
    }

    while (i >= 0)
    {
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
    }

    while (j >= 0)
    {
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        j--;
    }

    if (carry)
    {
        ans.push_back(carry + '0');
    }

    while (ans[ans.size() - 1] == '0')
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the vector a: " << endl;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements in arr a: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cout << "Enter the size of the vector b: " << endl;
    cin >> m;
    vector<int> b(m);
    cout << "Enter the elements in arr b: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    string result = calc_Sum(a, n, b, m);
    cout << result << endl;
    return 0;
}