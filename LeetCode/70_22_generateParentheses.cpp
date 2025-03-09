// 🔴🔴🔴🔴 LEETCODE 22 -> Generate Parentheses 🔴🔴🔴🔴
// Refer 16_DnC -> DnC Level 5 -> generate Parentheses Backtracking
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/
// _________________________________________________________________________________________________

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string> &ans, int n, int used_open, int used_close, int rem_open, int rem_close, string output)
{
    // Base case -> no more open and close brackets left -> we found the answer
    if (rem_open == 0 && rem_close == 0)
    {
        ans.push_back(output);
        return;
    }

    // include open brackets
    if (rem_open > 0)
    {
        output.push_back('(');
        solve(ans, n, used_open + 1, used_close, rem_open - 1, rem_close, output);

        // Backtracking
        output.pop_back();
    }

    // include closing brackets
    if (used_open > used_close)
    {
        output.push_back(')');
        solve(ans, n, used_open, used_close + 1, rem_open, rem_close - 1, output);

        // Backtracking
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    int used_open = 0;
    int used_close = 0;
    int rem_open = n;
    int rem_close = n;
    string output = "";
    solve(ans, n, used_open, used_close, rem_open, rem_close, output);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    vector<string> result = generateParenthesis(n);
    for(auto i: result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
### Time Complexity:
The time complexity of this solution can be expressed in terms of the number of recursive calls made.
In the worst case, the algorithm explores all possible combinations of open and close brackets to generate
valid parentheses.

Let C(n) be the number of valid combinations for a given n, then the time complexity can be represented as:
T(n) = C(n)

To determine the exact time complexity, we need to analyze the recursion tree. In the worst case, each node in
the recursion tree has two children, and the depth of the tree is 2n. Therefore, the total number of nodes in
the recursion tree is O(2^(2n)), leading to an exponential time complexity.

T(n) = O(2^{2n})

### Space Complexity:
The space complexity is determined by the maximum depth of the recursion stack and the space required for the
variables in each function call.

In each recursive call, the function uses a constant amount of space O(1) for the parameters and local
variables. The maximum depth of the recursion stack is 2n, corresponding to the maximum number of open and
close brackets.
Therefore, the space complexity is O(n) due to the recursion stack.

### Summary:
- Time Complexity: O(2^{2n})
- Space Complexity: O(n)
*/

// TC -> O(2^2n)
// SC -> O(n)